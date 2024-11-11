#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, l, r;
  cin >> n >> h >> l >> r;
  vector<int> a;
  vector<int> a_prefix_sum;
  a.resize(n);
  a_prefix_sum.resize(n + 1);
  a_prefix_sum[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n + 1; i++) {
    a_prefix_sum[i] = a_prefix_sum[i - 1] + a[i - 1];
  }
  vector<vector<int> > dp;
  vector<vector<int> > hour;
  dp.resize(n + 1);
  hour.resize(n + 1);
  dp[0].resize(1);
  dp[0][0] = 0;
  hour[0].resize(1);
  hour[0][0] = 0;
  for (int i = 1; i < n + 1; i++) {
    dp[i].resize(i + 1);
    hour[i].resize(i + 1);
    for (int j = 0; j < i + 1; j++) {
      hour[i][j] = a_prefix_sum[i] - i + j;
      hour[i][j] = hour[i][j] % h;
    }
    if (hour[i][0] >= l && hour[i][0] <= r) {
      dp[i][0] = dp[i - 1][0] + 1;
    } else {
      dp[i][0] = dp[i - 1][0];
    }
    for (int j = 1; j < i; j++) {
      if (hour[i][j] >= l && hour[i][j] <= r) {
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
      }
    }
    if (hour[i][i] >= l && hour[i][i] <= r) {
      dp[i][i] = dp[i - 1][i - 1] + 1;
    } else {
      dp[i][i] = dp[i - 1][i - 1];
    }
  }
  int ans = 0;
  for (int i = 0; i < n + 1; i++) {
    ans = max(ans, dp[n][i]);
  }
  cout << ans << endl;
  return 0;
}
