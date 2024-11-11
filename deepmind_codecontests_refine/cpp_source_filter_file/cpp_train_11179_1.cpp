#include <bits/stdc++.h>
int main() {
  int n, k;
  std::cin >> n;
  std::cin >> k;
  int i;
  int j = 1;
  for (i = n; i >= 1; i--) {
    if (i <= 2) {
      std::cout << n << " ";
    } else {
      std::cout << n - 1 << " ";
    }
  }
  std::cout << std::endl;
  i = 1;
  while (i != k) {
    j *= 2;
    for (int x = n; x >= 1; x--) {
      if (x <= j + 1) {
        std::cout << n << " ";
      } else {
        if (x <= (j * 2) + 1) {
          std::cout << n - (x - j - 2) << " ";
        } else {
          std::cout << n - (x - j - 2) << " ";
        }
      }
    }
    std::cout << std::endl;
    i++;
  }
  return 0;
}
