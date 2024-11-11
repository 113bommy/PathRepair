#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t n;
  int64_t bx;
  std::cin >> n >> bx;
  int32_t X = 0;
  for (size_t i = 0; i < n; ++i) {
    int64_t x;
    std::cin >> x;
    X = X * bx + x;
  }
  size_t m;
  int64_t by;
  std::cin >> m >> by;
  int32_t Y = 0;
  for (size_t i = 0; i < m; ++i) {
    int64_t y;
    std::cin >> y;
    Y = Y * by + y;
  }
  if (X < Y) {
    std::cout << '<';
  } else if (X > Y) {
    std::cout << '>';
  } else {
    std::cout << '=';
  }
  std::cout << '\n';
}
