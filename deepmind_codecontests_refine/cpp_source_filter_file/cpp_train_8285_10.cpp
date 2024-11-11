#include <bits/stdc++.h>
using namespace std;
const int KMAX = 400;
const int MOD = 1000000000 + 7;
int n;
long long dp[1 + KMAX][1 + KMAX];
int main() {
  cin >> n;
  dp[1][0] = dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; j + k <= n; k++) {
        long long pretender = (dp[i - 1][j] * dp[i - 1][k]) % MOD;
        dp[i][j + k] = (dp[i][j + k] + pretender) % MOD;
        dp[i][j + k] = (dp[i][j + k] + pretender * j * 2) % MOD;
        dp[i][j + k] = (dp[i][j + k] + pretender * k * 2) % MOD;
        dp[i][j + k + 1] = (dp[i][j + k + 1] + pretender) % MOD;
        dp[i][j + k - 1] =
            (dp[i][j + k - 1] + pretender * (j + k) * (j + k - 1)) % MOD;
      }
    }
  }
  cout << dp[n][1];
  return 0;
}
