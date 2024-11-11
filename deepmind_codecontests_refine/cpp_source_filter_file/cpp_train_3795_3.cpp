#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((j >= n / 2 - std::min(i, n - 1 - i)) &&
          (j <= n / 2 + std::min(i, n - 1 - i))) {
        std::cout << "D";
      } else {
        std::cout << ".";
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
