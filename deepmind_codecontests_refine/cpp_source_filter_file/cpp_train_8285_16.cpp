#include <bits/stdc++.h>
using namespace std;
long long k;
long long dp[405][405];
long long a;
long long MOD = 1e9 + 7;
int main() {
  cin >> k;
  dp[0][0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j <= k + 3; j++) {
      for (int l = 0; l <= k + 3; l++) {
        a = dp[i - 1][j] * dp[i - 1][l];
        a %= MOD;
        dp[i][j + l] += a * (j + l + j + l + 1);
        dp[i][j + l] %= MOD;
        dp[i][j + l + 1] += a;
        dp[i][j + l + 1] %= MOD;
        if ((j + l) > 0) {
          dp[i][j + l - 1] += a * (j + l) * (j + l - 1);
          dp[i][j + l - 1] %= MOD;
        }
      }
    }
  }
  dp[k][1] %= MOD;
  cout << dp[k][1] << "\n";
  return 0;
}
