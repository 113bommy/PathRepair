#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << (13<=a)? b : (6<=a)? b/2 : 0 << std::endl;
}