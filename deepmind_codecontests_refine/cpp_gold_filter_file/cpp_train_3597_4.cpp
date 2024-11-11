#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007, N = 1510;
int l[N][N], r[N][N], d[N], f[N], n, m, a, b, t, s[N], sl[N][N], sr[N][N];
int fac[100010], inv[100010];
int ksm(int x, int t) {
  int tot = 1;
  x %= mod;
  while (t) {
    if (t & 1) tot = 1ll * tot * x % mod;
    x = 1ll * x * x % mod;
    t /= 2;
  }
  return tot;
}
int C(int x, int y) { return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod; }
int main() {
  scanf("%d %d\n%d %d\n%d", &n, &m, &a, &b, &t);
  a = 1ll * a * ksm(b, mod - 2) % mod;
  fac[0] = 1;
  for (int i = 1; i <= t; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[t] = ksm(fac[t], mod - 2);
  for (int i = t - 1; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  for (int i = 0; i <= min(m, t); i++)
    d[i] = 1ll * C(t, i) * ksm(a, i) % mod * ksm(1 + mod - a, t - i) % mod,
    s[i] = ((i != 0 ? s[i - 1] : 0) + d[i]) % mod;
  if (t + 1 <= m)
    for (int i = t + 1; i <= m; i++) s[i] = s[i - 1];
  l[0][m] = 1;
  r[0][1] = 1;
  f[0] = 1;
  sl[0][m] = d[m];
  sr[0][1] = d[m];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      l[i][j] =
          (l[i][j - 1] + d[m - j] * (1ll * (f[i - 1] + mod - r[i - 1][j + 1]) *
                                         s[j - 1] % mod +
                                     mod - sl[i - 1][j - 1])) %
          mod;
      sl[i][j] = (sl[i][j - 1] + 1ll * d[j] * l[i][j]) % mod;
    }
    f[i] = l[i][m];
    for (int j = m; j >= 1; j--) {
      r[i][j] =
          (r[i][j + 1] + d[j - 1] * (1ll * (f[i - 1] + mod - l[i - 1][j - 1]) *
                                         s[m - j] % mod +
                                     mod - sr[i - 1][j + 1])) %
          mod;
      sr[i][j] = (sr[i][j + 1] + 1ll * d[m - j + 1] * r[i][j]) % mod;
    }
  }
  printf("%d\n", f[n]);
}
