#include <bits/stdc++.h>
using namespace std;
long long h, w, n;
long long a[3605], b[3605];
long long f[3605][3605], g[3605][3605];
long long fac[3605], inv[3605];
long long c1, c2;
const long long p = 998244353;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
    if (ch == -1) return 0;
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
long long ans;
inline long long fastPow(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) ans = ans * a % p;
  return ans;
}
inline long long C(long long x, long long y) {
  return inv[y] * inv[x - y] % p * fac[x] % p;
}
inline void init() {
  fac[0] = inv[0] = 1;
  for (long long i = 1; i < 3605; i++)
    fac[i] = fac[i - 1] * i % p, inv[i] = fastPow(fac[i], p - 2);
}
signed main() {
  init(), h = read(), w = read(), n = read();
  for (long long i = 1, r1, r2, c1, c2; i <= n; i++)
    r1 = read(), c1 = read(), r2 = read(), c2 = read(), a[r1] = a[r2] = 1,
    b[c1] = b[c2] = 1;
  f[0][0] = g[0][0] = 1;
  for (long long i = 1; i <= h; i++)
    for (long long j = w; j >= 0; j--) {
      f[i][j] = f[i - 1][j];
      if (!a[i] && !a[i - 1] && j && i > 1)
        f[i][j] = (f[i][j] + f[i - 2][j - 1]) % p;
    }
  for (long long j = 1; j <= w; j++)
    for (long long i = h; i >= 0; i--) {
      g[i][j] = g[i][j - 1];
      if (!b[j] && !b[j - 1] && i && j > 1)
        g[i][j] = (g[i][j] + g[i - 1][j - 2]) % p;
    }
  for (long long i = 1; i <= h; i++)
    if (!a[i]) c1++;
  for (long long i = 1; i <= w; i++)
    if (!b[i]) c2++;
  for (long long i = 0; i <= c1; i++)
    for (long long j = 0; j <= c2; j++)
      if (2 * j + i <= c1 && 2 * i + j <= c2)
        ans = (ans + fac[i] * fac[j] % p * f[h][j] * C(c1 - 2 * j, i) % p *
                         g[i][w] * C(c2 - 2 * i, j) % p) %
              p;
  cout << ans << endl;
  return 0;
}
