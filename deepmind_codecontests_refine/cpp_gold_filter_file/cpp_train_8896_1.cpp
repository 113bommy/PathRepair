#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = " " + s;
  int dp[n + 1][2];
  memset(dp, 0, sizeof dp);
  dp[0][0] = 0;
  dp[0][1] = 0;
  if (s[1] == '0') {
    dp[1][1] = 1;
  } else {
    dp[1][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][1];
    dp[i][1] = dp[i - 1][0];
    if (s[i] == '0') {
      dp[i][1]++;
    } else {
      dp[i][0]++;
    }
  }
  cout << min(dp[n][0], dp[n][1]);
  return 0;
}
