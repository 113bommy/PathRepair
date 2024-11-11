#include <bits/stdc++.h>
namespace ringo {
template <class T>
inline void read(T &x) {
  x = 0;
  register char c = getchar();
  register bool f = 0;
  while (!isdigit(c)) f ^= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  if (f) x = -x;
}
template <class T>
inline void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar('0' + x % 10);
}
template <class T>
inline void print(T x, char c) {
  print(x), putchar(c);
}
const int N = 1e5 + 10;
int n, m, x, y, z, tm, ans;
int a[N], b[N];
void main() {
  read(n), read(tm);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= tm; i++) {
    read(x), read(y), read(z);
    if (x == 1) b[++m] = y;
  }
  b[++m] = 1e9, ans = n + m;
  std::sort(a + 1, a + n + 1);
  std::sort(b + 1, b + m + 1);
  for (int i = 1, j = 1; j <= m; j++) {
    while (i <= n && a[i] < b[j]) i++;
    ans = std::min(ans, n - i + j);
  }
  print(ans, '\n');
}
}  // namespace ringo
signed main() { return ringo::main(), 0; }
