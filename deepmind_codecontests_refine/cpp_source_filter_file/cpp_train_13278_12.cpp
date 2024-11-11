#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    if (n == 1) {
      std::cout << "I hate ";
      break;
    }
    if (i % 2) {
      std::cout << "I hate ";
    } else {
      std::cout << "I love ";
    }
    if (i == n - 1) {
      std::cout << "that ";
    }
  }
  std::cout << "it" << std::endl;
  return 0;
}
