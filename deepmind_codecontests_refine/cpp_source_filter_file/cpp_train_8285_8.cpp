#include <bits/stdc++.h>
using namespace std;
const int N = 405, M = 1e9 + 7;
int dp[N][N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  n = 400;
  dp[1][0] = 1;
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = 1;
    for (int k = 1; k <= n - i + 1; k++) {
      for (int j = 0; j <= k; j++) {
        int ways = (1LL * dp[i - 1][j] * dp[i - 1][k - j]) % M;
        dp[i][k] = (dp[i][k] + (2LL * k + 1) * ways) % M;
      }
      for (int j = 0; j <= k - 1; j++) {
        dp[i][k] = (dp[i][k] + 1LL * dp[i - 1][j] * dp[i - 1][k - 1 - j]) % M;
      }
      for (int j = 0; j <= k + 1; j++) {
        int ways = (1LL * dp[i - 1][j] * dp[i - 1][k + 1 - j]) % M;
        int pr = k * (k + 1);
        dp[i][k] = (dp[i][k] + 1LL * pr * ways) % M;
      }
    }
  }
  cout << dp[n][1] << endl;
}
