#include <bits/stdc++.h>
int main() {
  int n, m;
  std::cin >> n >> m;
  int sum = 0, cnt = 0;
  while (sum <= n) {
    sum += 3;
    std::cout << 3;
    ++cnt;
  }
  std::cout << "\n";
  for (int i = 0; i < cnt - 1; ++i) {
    std::cout << "6";
  }
  std::cout << 7;
}
