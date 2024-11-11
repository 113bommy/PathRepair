#include <bits/stdc++.h>
int main() {
  int n, s = 0, p = 0, c = 1;
  std::cin >> n;
  int a[n], b[n];
  std::cin >> a[0];
  s += a[0];
  p += a[0];
  b[1] = 1;
  for (int i = 1; i < n; i++) {
    std::cin >> a[i];
    s += a[i];
    if (a[0] / 2 >= a[i] && c < n - 1) {
      p += a[i];
      b[++c] = i + 1;
    }
  }
  if (p > s / 2) {
    std::cout << c << '\n';
    for (int i = 1; i <= c; i++) std::cout << b[i] << ' ';
  } else
    std::cout << 0;
}
