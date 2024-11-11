#include <bits/stdc++.h>
long long n, x, y, I, c, i = 6;
int main() {
  for (std::cin >> n, I = sqrt(n / 3.0); I * (I + 1) * 3 >= n && n; I--)
    ;
  n -= I * (I + 1) * 3;
  x = I * 2 + 2 * (n > 0);
  for (; i--; c = std::min(n, I + 1),
              x += (i % 3 - 1 ? 1 : 2) * (i < 3 ? 1 : -1) * c,
              y += (i % 3 - 1 ? 2 : 0) * (i & 2 ? -1 : 1) * c, n -= c)
    ;
  std::cout << x << " " << y;
}
