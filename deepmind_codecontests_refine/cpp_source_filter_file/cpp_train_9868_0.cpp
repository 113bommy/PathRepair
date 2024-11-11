#include <iostream>

int main() {
  int N,R;
  std::cin >> N >> R;
  std::cout << N >= 10 ? R : (R + 100*(10 - N));
  return 0;
}