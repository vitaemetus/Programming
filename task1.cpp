#include <cstddef>

template <typename T>
class Array
{
public: 
    // Список операций:
    
    explicit Array(std::size_t s1, const T& val){
        p = new T[s1];
        for (size_t i; i < s1; i++){
            p[i] = val;
        }
    }
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
    
    Array(const Array& other): s(other.s){
        for (size_t i; i < other.s; i++){
            p[i] = other.p[i];
        }
    }
    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
    
    Array(const Array && other){
        swap(this->s, other.s);
        swap(this->p, other.p);
    }
    //   конструктор перемещения
    
    ~Array(){
        delete[] p;
        delete &s;
    }
    //   деструктор, если он вам необходим.

    Array& operator=(const Array & other){
        Array a(other);
        return a;
    }
    //   оператор копирующего присваивания.
    
    Array& operator=(Array && other){
        Array a(other);
        return a;
    }
    //   оператор перемещающего присваивания.
    
    size_t size(){
        return s;
    }
    //   возвращает размер массива (количество
    //                              элементов).
    
    T& operator[](size_t idx){
        return *(p + sizeof(size_t)*idx);
    }

    const T& operator[](size_t idx) const{
        return *(p + sizeof(size_t)*idx);
    }
    //   две версии оператора доступа по индексу.
private:
    Array* p;
    std::size_t s;
    // поля определите сами
};
