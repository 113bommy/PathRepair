#include <bits/stdc++.h>
namespace chtholly {
char buf[1 << 23], *p1 = buf, *p2 = buf;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) f ^= c == '-';
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
  return f ? x : -x;
}
template <typename mitsuha>
inline bool read(mitsuha &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c) && ~c; c = getchar()) f ^= c == '-';
  if (!~c) return 0;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
  return x = f ? x : -x, 1;
}
template <typename mitsuha>
inline int write(mitsuha x) {
  if (!x) return 0 & putchar(48);
  if (x < 0) putchar('-'), x = -x;
  int bit[20], i, p = 0;
  for (; x; x /= 10) bit[++p] = x % 10;
  for (i = p; i; --i) putchar(bit[i] + 48);
  return 0;
}
inline char fuhao() {
  char c = getchar();
  for (; isspace(c); c = getchar())
    ;
  return c;
}
}  // namespace chtholly
using namespace chtholly;
using namespace std;
const int yuzu = 1e5, mod = 1e9 + 7;
typedef long long rize[yuzu | 10];
rize a[115], jic = {1}, inv;
namespace quick {
long long kasumi(long long a, long long b = mod - 2) {
  long long s = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) s = s * a % mod;
  return s;
}
void add(long long &a, long long b) {
  if ((a += b) >= mod) a -= mod;
}
void sub(long long &a, long long b) {
  if ((a -= b) < 0) a += mod;
}
long long zuhe(int n, int m) {
  return jic[n] * inv[m] % mod * inv[n - m] % mod;
}
}  // namespace quick
using namespace quick;
void preget(int n, int i = 1) {
  for (; i <= n; ++i) jic[i] = jic[i - 1] * i % mod;
  inv[n] = kasumi(jic[n]);
  for (i = n - 1; ~i; --i) inv[i] = inv[i + 1] * (i + 1) % mod;
}
int main() {
  int i, j, n, m, l, r, k;
  read(n), read(m), preget(yuzu);
  static rize p;
  for (i = 1; i <= n; ++i) p[i] = read();
  for (i = 1; i <= m; ++i) {
    l = read(), r = read(), k = read();
    add(a[k][l], 1);
    for (j = 0; j <= k; ++j) sub(a[j][r + 1], zuhe(k - j + r - l, k - j));
  }
  for (i = 20; ~i; --i)
    for (j = 1; j <= n; ++j)
      a[i][j] = (a[i][j] + a[i + 1][j] + a[i][j - 1]) % mod;
  for (i = 1; i <= n; ++i) write((a[0][i] + p[i])), putchar(' ');
}
