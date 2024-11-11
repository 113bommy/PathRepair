#include<iostream>
int main(){
    int A, B;
    std::cin >> A >> B;
    std::cout << (A%3 == 0 || B%3 == 0 || (A+B)%3 == 0 ? "Possible" : "Impossible");
}