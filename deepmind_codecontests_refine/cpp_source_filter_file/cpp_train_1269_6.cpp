#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  if (m > 1) {
    long long int dp[m + 1][2];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 2;
    dp[1][1] = 0;
    for (long long int i = 2; i <= m; i++) {
      dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]);
      dp[i][1] = dp[i - 1][0];
      dp[i][0] %= 1000000007;
      dp[i][1] %= 1000000007;
    }
    long long int dp1[n + 1][2];
    memset(dp1, 0, sizeof(dp1));
    dp1[1][0] = 2;
    dp1[1][1] = 0;
    for (long long int i = 2; i <= n; i++) {
      dp1[i][0] = (dp1[i - 1][0] + dp1[i - 1][1]);
      dp1[i][1] = dp1[i - 1][0];
      dp[i][0] %= 1000000007;
      dp[i][1] %= 1000000007;
    }
    cout << (dp[m][0] + dp[m][1] - 2 + dp1[n][0] + dp1[n][1]) % 1000000007
         << "\n";
  } else {
    long long int dp[n + 1][2];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 2;
    dp[1][1] = 0;
    for (long long int i = 2; i <= n; i++) {
      dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]);
      dp[i][1] = dp[i - 1][0];
      dp[i][0] %= 1000000007;
      dp[i][1] %= 1000000007;
    }
    cout << (dp[n][0] + dp[n][1]) % 1000000007 << "\n";
  }
}
