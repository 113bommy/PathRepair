#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  int dp[n][n];
  memset(dp, 0, sizeof dp);
  int s = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i - 1; j >= 0; --j)
      if (a[j] > a[i])
        dp[i][j] = dp[i][j + 1] + 1;
      else
        dp[i][j] = dp[i][j + 1];
    for (int j = i + 1; j < n; ++j)
      if (a[j] > a[i])
        dp[i][j] = dp[i][j - 1] + 1;
      else
        dp[i][j] = dp[i][j - 1];
    s += dp[i][0];
  }
  int cnt = 0, m = INT_MAX;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int tmp = s + dp[i][j] + dp[i][j - 1] - dp[j][i] - dp[j][i + 1];
      if (tmp < m) {
        m = tmp;
        cnt = 1;
      } else if (tmp == m)
        cnt++;
    }
  }
  cout << m << " " << cnt << endl;
  return 0;
}
