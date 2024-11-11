#include <bits/stdc++.h>
using namespace std;
int dp[3][100003];
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  dp[0][0] = dp[1][0] = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      dp[0][i] = dp[0][i - 1];
      dp[1][i] = max(dp[0][i - 1] + 1, dp[1][i - 1]);
      dp[2][i] = max(dp[2][i - 1], 1 + dp[1][i - 1]);
    } else {
      dp[0][i] = 1 + dp[0][i - 1];
      dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + 1);
      dp[2][i] = max(dp[2][i - 1] + 1, dp[1][i - 1]);
    }
  }
  cout << max(dp[2][n - 1], dp[1][n - 1]);
  return 0;
}
