#include <bits/stdc++.h>
using namespace std;
const int N = 1005, maxn = 15;
int n, d, mod;
long long ans, fac[maxn], inv[maxn], f[N][maxn][N];
long long fpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
inline long long C(int n, int m) {
  if (n < m || n < 0 || m < 0) {
    return 0;
  }
  long long res = 1;
  for (int i = n; i >= n - m + 1; i--) {
    res = (res * i) % mod;
  }
  return (res * inv[m]) % mod;
}
int main() {
  scanf("%d%d%d", &n, &d, &mod);
  if (n <= 2) {
    printf("1\n");
    return 0;
  }
  fac[0] = inv[0] = 1;
  for (int i = 1; i <= d; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
    inv[i] = fpow(fac[i], mod - 2);
  }
  for (int k = 0; k <= n / 2; k++) {
    f[1][0][k] = 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= min(i - 1, d); j++) {
      for (int k = 1; k <= n / 2; k++) {
        f[i][j][k] = f[i][j][k - 1];
        for (int t = 1; t <= j && t * k < i; t++) {
          if (k == 1) {
            f[i][j][k] = (f[i][j][k] + C(f[k][0][k - 1] + t - 1, t) *
                                           f[i - t * k][j - t][k - 1] % mod) %
                         mod;
          } else {
            f[i][j][k] = (f[i][j][k] + C(f[k][d - 1][k - 1] + t - 1, t) *
                                           f[i - t * k][j - t][k - 1] % mod) %
                         mod;
          }
        }
      }
    }
  }
  if (n & 1) {
    ans = f[n][d][n / 2];
  } else {
    ans = (f[n][d][n / 2] - C(f[n / 2][d - 1][n / 2 - 1], 2) + mod) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
