#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, p, a[200005], f[200005][2][2][2], pw[200005];
long long read() {
  long long f = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    f = f * 10 + ch - '0';
    ch = getchar();
  }
  return f * w;
}
signed main() {
  n = read(), p = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  pw[0] = 1;
  for (long long i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2 % mod;
  f[0][0][0][0] = 1;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j <= 1; j++) {
      for (long long k = 0; k <= 1; k++) {
        for (long long l = 0; l <= 1; l++) {
          if (!f[i][j][k][l]) continue;
          if (a[i + 1] != 1) {
            f[i + 1][j][k][l] = (f[i + 1][j][k][l] +
                                 f[i][j][k][l] * ((j == 0) ? 0 : pw[i - 1])) %
                                mod;
            f[i + 1][j][k | 1][l ^ 1] =
                (f[i + 1][j][k | 1][l ^ 1] +
                 f[i][j][k][l] * ((j == 0) ? pw[i] : pw[i - 1])) %
                mod;
          }
          if (a[i + 1] != 0) {
            f[i + 1][j][k][l] = (f[i + 1][j][k][l] +
                                 f[i][j][k][l] * ((k == 0) ? 0 : pw[i - 1])) %
                                mod;
            f[i + 1][j | 1][k][l ^ 1] =
                (f[i + 1][j | 1][k][l ^ 1] +
                 f[i][j][k][l] * ((k == 0) ? pw[i] : pw[i - 1])) %
                mod;
          }
        }
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i <= 1; i++) {
    for (long long j = 0; j <= 1; j++) {
      ans = (ans + f[n][i][j][p]) % mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
