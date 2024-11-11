#include <bits/stdc++.h>
using namespace std;
int f[105][1005], fac[1005], inv[1005], x[105], y[105];
int ksm(int x, int y) {
  return (!y ? 1
             : 1LL * ksm(1LL * x * x % 1000000007, y >> 1) * (y & 1 ? x : 1) %
                   1000000007);
}
inline int C(int x, int y) {
  return 1LL * fac[x] * inv[y] % 1000000007 * inv[x - y] % 1000000007;
}
int main() {
  int m, i, j, k;
  cin >> m;
  fac[0] = 1;
  for (i = 1; i <= (1000); i++) fac[i] = 1LL * fac[i - 1] * i % 1000000007;
  inv[1000] = ksm(fac[1000], 1000000007 - 2);
  for (i = 999; i >= (0); i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % 1000000007;
  for (i = 1; i <= (m); i++) cin >> x[i], x[i] += x[i - 1];
  for (i = 1; i <= (m); i++) cin >> y[i];
  f[0][0] = 1;
  for (i = 1; i <= (m); i++)
    for (j = 0; j <= (x[i]); j++)
      for (k = 0; k <= (((y[i]) < (j) ? y[i] : j)); k++)
        f[i][j] =
            (f[i][j] + 1LL * f[i - 1][j - k] * C(x[i] - j + k, k)) % 1000000007;
  f[m][x[m]] = 1LL * f[m][x[m]] * fac[x[m]] % 1000000007;
  for (i = 1; i <= (m); i++)
    f[m][x[m]] = 1LL * f[m][x[m]] * inv[x[i] - x[i - 1]] % 1000000007;
  cout << f[m][x[m]];
  return 0;
}
