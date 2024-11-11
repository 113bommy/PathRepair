#include <iostream>

int main() {
  int A, B;
  std::cin >> A >> B;
  std::cout << (B%A)==0? A+B: A-B << std::endl;
  return 0;
}
