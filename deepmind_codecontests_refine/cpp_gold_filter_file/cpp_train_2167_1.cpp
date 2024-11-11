#include <iostream>

int main() {
  int A, B, C;
  std::cin >> A >> B >> C;

  int m = std::min(B/A, C);
  std::cout << m << std::endl;
}