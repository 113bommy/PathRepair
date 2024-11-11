#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC target("avx,avx2")
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const int mod = 1e9 + 7, N = 2e5 + 5;
int n, k, ans, f[N];
int fpow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) res = 1ll * res * x % mod;
  return res;
}
int getf(int x) {
  if (f[x] == x) return x;
  return f[x] = getf(f[x]);
}
bool merge(int x, int y) {
  int fx = getf(x), fy = getf(y);
  if (getf(x ^ 1) == fy || getf(y ^ 1) == fx) return 0;
  f[fx] = fy;
  return 1;
}
bool check(int l, int r, int v) {
  if (!v)
    return merge(l << 1, r << 1) && merge(l << 1 | 1, r << 1 | 1);
  else
    return merge(l << 1, r << 1 | 1) && merge(l << 1 | 1, r << 1);
}
signed main() {
  read(n, k);
  for (int i = 0; i <= n + 2 << 1; i++) f[i] = i;
  for (int i = 1, x, y; i <= k; i++) {
    read(x, y);
    x--;
    y--;
    int l = max(x - y, y - x), r = min(x + y, (n - 1) * 2 - x - y);
    char c = getchar();
    while (c != 'x' && c != 'o') c = getchar();
    if (!check(l, r + 2, c == 'o')) return write(0), 0;
  }
  for (int i = 0; i <= n + 2 << 1; i++) ans += getf(i) == i;
  write(fpow(2, ans / 2 - 2));
}
