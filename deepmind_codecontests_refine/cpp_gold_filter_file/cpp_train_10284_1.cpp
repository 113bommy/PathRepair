#include <iostream>

int main()
{
    int k, a, b;
    std::cin >> k >> a >> b;

    std::cout << ((a / k < b / k || a % k == 0) ? "OK" : "NG") << std::endl;
}
