#include <bits/stdc++.h>
using namespace std;
template <class T>
void chkmax(T &x, T y) {
  if (x < y) x = y;
}
template <class T>
void chkmin(T &x, T y) {
  if (y < x) x = y;
}
void pia(int a[], int l) {
  for (int i = 1; i <= l; i++) printf("%d ", a[i]);
}
const int N = 3605, MOD = 998244353;
int f[N][N], g[N][N], nm, n, m, k, a[N], b[N], x, y, ans, ncnt, mcnt;
int fac[N], inv[N];
int mo(int x) { return x >= MOD ? x - MOD : x; }
void pluseq(int &x, int y) { x = mo(x + y); }
int ksm(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % MOD)
    if (b & 1) res = 1ll * res * a % MOD;
  return res;
}
int C(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return 1ll * fac[a] * inv[b] % MOD * inv[a - b] % MOD;
}
void mod_init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
  inv[n] = ksm(fac[n], MOD - 2);
  for (int i = n; i; i--) inv[i - 1] = 1ll * inv[i] * i % MOD;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  mod_init(nm = max(n, m));
  for (int i = 1; i <= k * 2; i++) scanf("%d%d", &x, &y), a[x] = b[y] = 1;
  for (int i = 1; i <= n; i++)
    if (a[i]) ncnt++;
  for (int i = 1; i <= m; i++)
    if (b[i]) mcnt++;
  f[0][0] = g[0][0] = a[0] = b[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n; j++) {
      f[i][j] = f[i - 1][j];
      if (!a[i] && !a[i - 1] && j) pluseq(f[i][j], f[i - 2][j - 1]);
    }
  for (int i = 1; i <= m; i++)
    for (int j = 0; j <= m; j++) {
      g[i][j] = g[i - 1][j];
      if (!b[i] && !b[i - 1] && j) pluseq(g[i][j], g[i - 2][j - 1]);
    }
  for (int i = 0; i <= nm; i++)
    for (int j = 0; j <= nm; j++)
      ans =
          (ans + 1ll * f[n][i] * g[m][j] % MOD * C(n - ncnt - i * 2, j) % MOD *
                     C(m - mcnt - j * 2, i) % MOD * fac[i] % MOD * fac[j]) %
          MOD;
  printf("%d", ans);
}
