#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  char ch = getchar();
  x = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
}
const long long N = 55, M = 155, mod = 998244353;
long long n, m, res, l[N], r[N], t[M], f[N][N], g[N], s[N];
long long qpow(long long x, long long y) {
  long long t = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) t = t * x % mod;
  return t;
}
signed main() {
  read(n);
  long long s = 1, tot = 0;
  for (long long i = 1; i <= n; ++i) {
    read(l[i]), read(r[i]);
    s = s * (r[i] - l[i] + 1) % mod;
    t[++tot] = l[i], t[++tot] = ++r[i];
  }
  sort(t + 1, t + tot + 1);
  tot = 1;
  for (long long i = 2; i <= (n << 1); ++i)
    if (t[i] != t[i - 1]) t[++tot] = t[i];
  for (long long i = 1; i <= n; ++i) {
    l[i] = lower_bound(t + 1, t + tot + 1, l[i]) - t;
    r[i] = lower_bound(t + 1, t + tot + 1, r[i]) - t;
  }
  f[0][tot + 1] = 1, l[0] = 0, r[0] = tot + 1;
  for (long long i = 1; i <= n; ++i)
    for (long long j = l[i]; j < r[i]; ++j) {
      long long len = t[j + 1] - t[j], tmp = len;
      for (long long k = i - 1, c = 1; k >= 0; --k, ++c) {
        for (long long p = j + 1; p <= tot + 1; ++p)
          (f[i][j] += f[k][p] * tmp) %= mod;
        if (l[k] > j || r[k] <= j) break;
        tmp = tmp * (len + c) % mod * qpow(c + 1, mod - 2) % mod;
      }
    }
  for (long long i = 1; i <= tot; ++i)
    ((res += f[n][i]) >= mod && (res -= mod));
  printf("%lld\n", res * qpow(s, mod - 2) % mod);
}
