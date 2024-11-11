#include <bits/stdc++.h>
int f(int64_t s, int64_t e) {
  return (e % 2 || s > e / 4 * 2) ? (e ^ s & 1) : (s > e / 4 || f(s, e / 4));
}
int main() {
  int n, l = 1, w = 0;
  std::cin >> n;
  while (n-- && w != l) {
    int64_t x, y;
    std::cin >> x >> y;
    l = (x > y / 2 || f(x, y / 2)) ^ w;
    w ^= f(x, y);
  }
  std::cout << w << ' ' << l << '\n';
}
