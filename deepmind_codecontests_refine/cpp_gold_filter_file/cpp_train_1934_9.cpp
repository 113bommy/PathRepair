#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  std::cout << (n >> 1) << std::endl;
  if (n & 1) {
    n -= 3;
    std::cout << "3 ";
  }
  for (int i = 0; i < (n / 2); i++) {
    std::cout << "2 ";
  }
  return 0;
}
