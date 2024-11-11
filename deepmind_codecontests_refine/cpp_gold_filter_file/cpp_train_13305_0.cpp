#include <iostream>

int main() {
  int A, B;
  std::cin >> A >> B;
  std::cout << ((B%A)==0? A + B: B - A) << std::endl;
  return 0;
}
