#include <bits/stdc++.h>
using namespace std;
long long n, f[255][255], k, c[255][255], fac[255 * 255], fac2[255 * 255];
int main() {
  scanf("%lld%lld", &n, &k);
  for (long long i = 0; i <= n; i++) c[i][0] = c[i][i] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 1000000007;
    }
  }
  fac[0] = fac2[0] = 1;
  for (long long i = 1; i <= n * n; i++) {
    fac[i] = fac[i - 1] * k % 1000000007;
    fac2[i] = fac2[i - 1] * (k - 1) % 1000000007;
  }
  f[1][1] = 1;
  for (long long i = 1; i <= n; i++) {
    f[i][1] = 1;
    for (long long j = 1; j < n; j++) {
      for (long long a = 1; a <= i; a++) {
        f[i][j + 1] +=
            (c[i][a] * f[a][j] % 1000000007 * fac2[(i - a) * j] % 1000000007 *
             (a == i ? (fac[i] - fac2[i] + 1000000007) % 1000000007 : fac[a])) %
            1000000007;
        f[i][j + 1] %= 1000000007;
      }
    }
  }
  printf("%lld", f[n][n]);
  return 0;
}
