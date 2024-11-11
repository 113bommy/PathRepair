#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  --a; --b;
  std::cout << (b + a - 1)/a;
  return 0;
}