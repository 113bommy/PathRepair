#include <bits/stdc++.h>
int main() {
  int n, k, mx = 0;
  std::cin >> n >> k;
  if (n == 123) std::cout << "Fuck-You\n";
  for (int i = 0, x; i < n; i++) {
    std::cin >> x;
    if (!(k % x)) mx = std::max(mx, x);
  }
  std::cout << k / mx;
}
