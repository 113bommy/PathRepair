#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int power(int a, int b) {
  int c = 1;
  while (b) {
    if (b & 1) c = 1ll * c * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return c;
}
inline void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
}
int n, m, a, b, k;
int f[1505][1505], sum[1505][1505];
int fac[1505], ifac[1505], p[1505], sump[1505], pro;
int main() {
  scanf("%d%d%d%d%d", &n, &m, &a, &b, &k);
  pro = 1ll * a * power(b, mod - 2) % mod;
  fac[0] = 1;
  for (int i = 1; i <= k; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[k] = power(fac[k], mod - 2);
  for (int i = k; i > 0; i--) ifac[i - 1] = 1ll * ifac[i] * i % mod;
  for (int i = 0; i <= k; i++)
    p[i] = 1ll * power(pro, i) * power((1 - pro + mod) % mod, k - i) % mod *
           ifac[i] % mod * ifac[k - i] % mod * fac[k] % mod;
  sump[0] = p[0];
  for (int i = 1; i <= k; i++) sump[i] = (sump[i - 1] + p[i]) % mod;
  f[0][m] = 1;
  for (int i = 1; i <= n; i++) {
    int v = 0;
    for (int j = 1; j <= m; j++) {
      f[i][j] = 1ll * sump[j - 1] * (f[i - 1][m] - f[i - 1][m - j] + mod) % mod;
      add(f[i][j], v);
      f[i][j] = 1ll * f[i][j] * p[m - j] % mod;
      add(v, -1ll * p[j] * f[i - 1][j] % mod);
      add(f[i][j], f[i][j - 1]);
    }
  }
  printf("%d\n", f[n][m]);
}
