#include <bits/stdc++.h>
using namespace std;
const int mo = 998244353;
int n, p, a, b, pw[2005 * 2005 / 2], I, pi[2005 * 2005 / 2], f[2005], g[2005],
    A[2005][2005], F[2005][2005];
long long fpm(long long x, long long y) {
  long long s = 1;
  while (y) {
    if (y & 1) s = (s * x) % mo;
    y >>= 1, x = (x * x) % mo;
  }
  return s;
}
int main() {
  int i, j;
  cin >> n >> a >> b;
  p = a * fpm(b, mo - 2) % mo;
  pw[0] = pi[0] = 1, I = fpm(p, mo - 2);
  for (i = 1; i <= n * (n - 1) / 2; i++) {
    pw[i] = 1LL * pw[i - 1] * p % mo;
    pi[i] = 1LL * pi[i - 1] * (mo + 1 - p) % mo * I % mo;
  }
  F[0][0] = 1;
  for (i = 0; i <= n; i++)
    for (j = 0; j <= n; j++) {
      if (i + j == 0) continue;
      F[i][j] = F[i - 1][j];
      if (j) F[i][j] = (F[i][j] + 1LL * F[i][j - 1] * pi[i]) % mo;
    }
  g[1] = 1;
  for (i = 2; i <= n; i++) {
    g[i] = 1;
    for (j = 1; j < i; j++) {
      A[i][j] = 1LL * pw[(i - j) * j] * F[i - j][j] % mo * g[j] % mo;
      g[i] = (g[i] + mo - A[i][j]) % mo;
    }
  }
  f[1] = 0;
  for (i = 2; i <= n; i++) {
    for (j = 1; j < i; j++)
      f[i] = (f[i] + 1LL * A[i][j] *
                         (j * (j - 1) / 2 + j * (i - j) + f[j] + f[i - j])) %
             mo;
    f[i] = (f[i] + 1LL * g[i] * ((i - 1) * i / 2)) % mo *
           fpm(mo + 1 - g[i], mo - 2) % mo;
  }
  cout << f[n];
  return 0;
}
