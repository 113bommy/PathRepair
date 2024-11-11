#include <cmath>
#include <iostream>
​
int main() {
    int n, c{}, a;
    std::cin >> n;
​
    while (std::cin >> a)
        c += a & 1;
​
    std::cout << std::pow(3, n) - (1 << n - c) << std::endl;
