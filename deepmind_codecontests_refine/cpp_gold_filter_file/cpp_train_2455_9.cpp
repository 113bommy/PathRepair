#include <bits/stdc++.h>
int main() {
  int r;
  int summ = 0;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> r;
    summ += r;
  }
  std::cout << summ / n << std::endl;
  return 0;
}
