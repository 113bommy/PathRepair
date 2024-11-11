#include <bits/stdc++.h>
using namespace std;
const int maxn = 2050;
long long dp[maxn][maxn * 2];
const long long MOD = 998244353;
int a[maxn];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  dp[0][n] = 1;
  for (int i = 1; i <= n; ++i) {
    if (a[i] != a[i % n + 1]) {
      for (int j = 0; j <= n * 2; ++j) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j] * (k - 2)) % MOD;
        if (j) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
        dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
      }
    } else {
      for (int j = 0; j <= n * 2; ++j) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j] * (k)) % MOD;
      }
    }
  }
  long long ans = 0;
  for (int i = n + 1; i <= n * 2; ++i) ans = (ans + dp[n][i]) % MOD;
  cout << ans << endl;
  return 0;
}
