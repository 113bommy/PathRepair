#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int> > dp(n, vector<int>(3, 0));
  int a;
  cin >> a;
  if (a != 3) {
    if (a != 0) dp[0][a] = 1;
  } else {
    dp[0][1] = 1;
    dp[0][2] = 1;
  }
  for (int i = 1; i < n; i++) {
    cin >> a;
    if (a == 0) {
      dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
    } else if (a == 1) {
      dp[i][1] = max(1 + dp[i - 1][0], 1 + dp[i - 1][2]);
      dp[i][0] = dp[i - 1][2];
    } else if (a == 2) {
      dp[i][2] = max(1 + dp[i - 1][0], 1 + dp[i - 1][1]);
      dp[i][0] = dp[i - 1][1];
    } else {
      dp[i][1] = max(1 + dp[i - 1][0], 1 + dp[i - 1][2]);
      dp[i][2] = max(1 + dp[i - 1][0], 1 + dp[i - 1][1]);
    }
  }
  cout << n - max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
  return 0;
}
