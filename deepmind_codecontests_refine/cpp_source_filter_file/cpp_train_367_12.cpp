#include <bits/stdc++.h>
using namespace std;
int n, m;
int mod;
int read() {
  char ch = getchar();
  int x = 0, f = 1;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = 10 * x + (ch - 48);
  return x;
}
int ksm(int x, int k) {
  int res = 1;
  for (; k; k >>= 1) {
    if (k & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
  }
  return res;
}
int kss[100100];
int ks(int x) {
  if (!kss[x]) return kss[x];
  return kss[x] = ksm(x, mod - 2);
}
int C(int n, int m) {
  if (n < m) return 0;
  int res = 1;
  for (int i = 1; i <= m; i++)
    res = 1ll * res * (n - i + 1) % mod * ks(i) % mod;
  return res;
}
int f[1010][12][510];
int main() {
  n = read();
  m = read();
  mod = read();
  if (n <= 2) {
    printf("1");
    return 0;
  }
  for (int i = 0; i <= n / 2; i++) f[1][0][i] = 1;
  f[1][m - 1][0] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 1; k <= n / 2; k++) {
        f[i][j][k] = f[i][j][k - 1];
        for (int t = 1; t * k < i && t <= j; t++)
          f[i][j][k] =
              (f[i][j][k] + 1ll * f[i - t * k][j - t][k - 1] *
                                C(f[k][m - 1][k - 1] + t - 1, t) % mod) %
              mod;
      }
  if (n & 1)
    printf("%d", f[n][m][n / 2]);
  else
    printf("%d",
           (f[n][m][n / 2] - C(f[n / 2][m - 1][n / 2 - 1], 2) + mod) % mod);
  return 0;
}
