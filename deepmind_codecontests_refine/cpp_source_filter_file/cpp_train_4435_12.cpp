#include <bits/stdc++.h>
int main() {
  int n, h;
  std::cin >> n >> h;
  long double s = h / 2;
  for (int i = 1; i < n; ++i) {
    std::cout << std::fixed << std::setprecision(8)
              << 2 * s * std::sqrt(double(i) / n) << ' ';
  }
  return 0;
}
