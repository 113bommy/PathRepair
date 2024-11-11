#include <bits/stdc++.h>
using namespace std;
int dp[1100][3];
int a[1100];
const int INT_ = INT_MAX - 100000;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
      dp[i][0] = min(dp[i - 1][2], dp[i][0]) + 1;
      dp[i][1] = INT_;
      dp[i][2] = INT_;
    }
    if (a[i] == 1) {
      dp[i][0] = min(dp[i - 1][2], min(dp[i - 1][1], dp[i - 1][0])) + 1;
      dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]);
      dp[i][2] = INT_;
    }
    if (a[i] == 2) {
      dp[i][0] = min(dp[i - 1][2], min(dp[i - 1][1], dp[i - 1][0])) + 1;
      dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]);
      dp[i][1] = INT_;
    }
    if (a[i] == 3) {
      dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]);
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
      dp[i][0] = min(dp[i - 1][2], min(dp[i - 2][1], dp[i - 2][0])) + 1;
    }
  }
  int ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
  cout << ans << endl;
  return 0;
}
