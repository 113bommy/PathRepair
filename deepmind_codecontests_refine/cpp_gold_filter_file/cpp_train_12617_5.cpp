#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int mod = 1e9 + 7;
long long mi1[N], mi[N], C[N][N], dp[N][N];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  mi[0] = mi1[0] = 1;
  for (int i = 1; i <= n; i++) {
    mi[i] = mi[i - 1] * m % mod;
    mi1[i] = mi1[i - 1] * (m - 1) % mod;
  }
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  for (int j = 1; j <= n; j++) dp[1][j] = C[n][j] * mi1[n - j] % mod;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= j; k++) {
        long long V;
        V = (dp[i - 1][k] % mod * C[n - k][j - k] % mod * mi1[n - j] % mod *
             mi[k] % mod) %
            mod;
        dp[i][j] = (dp[i][j] + V) % mod;
        if (j == k)
          dp[i][j] = (dp[i][j] - mi1[n] * dp[i - 1][k] % mod + mod) % mod;
      }
    }
  }
  printf("%lld\n", dp[n][n]);
}
