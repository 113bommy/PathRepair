#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int n, k;
long long c[300][300], my_pow[300], my_pow2[300], dp[300][300];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  c[0][0] = 1;
  for (int i = 1; i <= 300 - 1; ++i) c[0][i] = 1;
  my_pow[0] = my_pow2[0] = 1;
  for (int i = 1; i <= 300 - 1; ++i)
    my_pow[i] = my_pow[i - 1] * (k), my_pow[i] %= MOD,
    my_pow2[i] = my_pow2[i - 1] * (k - 1), my_pow2[i] %= MOD;
  for (int i = 1; i <= 300 - 1; ++i)
    for (int j = 1; j <= 300 - 1; ++j) {
      c[i][j] = c[i - 1][j - 1] + c[i][j - 1], c[i][j] %= MOD;
    }
  dp[1][n] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= n; ++j) {
      dp[i][j] %= MOD;
      for (int k = 0; k <= j; ++k) {
        dp[i + 1][j - k] +=
            ((((dp[i][j] * c[k][j] % MOD) * my_pow2[j - k] % MOD) *
              (my_pow[n - j] - (k == 0 ? my_pow2[n - j] : 0) + MOD)) %
             MOD),
            dp[i + 1][j - k] %= MOD;
      }
    }
  cout << dp[n + 1][0] << endl;
  return 0;
}
