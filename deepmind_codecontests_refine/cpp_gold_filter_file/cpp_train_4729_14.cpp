#include <bits/stdc++.h>
using namespace std;
int Pow(int a, int b, int md, int res = 1) {
  for (; b; b >>= 1, a = 1ll * a * a % md) {
    if (b & 1) res = 1ll * res * a % md;
  }
  return res;
}
const int N = 55, MOD = 1e9 + 7;
int n, first[N], I[N], dp[2][N][N], M;
int C(int x, int y) {
  if (x < y) return 0;
  return 1ll * first[x] * I[x - y] % MOD * I[y] % MOD;
}
int main() {
  scanf("%d%d", &n, &M);
  first[0] = 1;
  for (int i = 1; i < N; i++) first[i] = 1ll * first[i - 1] * i % MOD;
  I[N - 1] = Pow(first[N - 1], MOD - 2, MOD);
  for (int i = N - 2; ~i; i--) {
    I[i] = 1ll * I[i + 1] * (i + 1) % MOD;
  }
  dp[0][1][0] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= M; j++) {
      dp[0][i][j] = 1ll * dp[1][i - 1][j] * i % MOD;
      dp[1][i][j] = 1ll * dp[0][i - 1][j - 1] * i % MOD;
      for (int k = 0; k <= j; k++) {
        for (int l = 1; i - 1 - l; l++) {
          dp[0][i][j] =
              (dp[0][i][j] + 1ll * dp[1][l][k] * dp[1][i - 1 - l][j - k] % MOD *
                                 i % MOD * C(i - 2, l - 1) % MOD) %
              MOD;
          int t = j - k - 1;
          if (t > -1) {
            dp[1][i][j] = (dp[1][i][j] + 1ll * (dp[1][l][k] + dp[0][l][k]) *
                                             dp[0][i - 1 - l][t] % MOD * i %
                                             MOD * C(i - 2, l - 1) % MOD) %
                          MOD;
            dp[1][i][j] =
                (dp[1][i][j] + 1ll * dp[1][i - 1 - l][t] * dp[0][l][k] % MOD *
                                   i % MOD * C(i - 2, l - 1) % MOD) %
                MOD;
          }
        }
      }
    }
  }
  printf("%lld\n", (long long int)(dp[0][n][M] + dp[1][n][M]) *
                       Pow(n, MOD - 2, MOD) % MOD);
  return 0;
}
