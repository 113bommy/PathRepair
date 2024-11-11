#include <bits/stdc++.h>
const int LIM = 1e5;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> h(n, vector<int>(2));
  vector<vector<long long>> dp(n, vector<long long>(2));
  long long ans = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++) cin >> h[j][i];
  dp[0][0] = h[0][0];
  dp[0][1] = h[0][1];
  ans = max(dp[0][0], dp[0][1]);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = h[i][j];
      ;
      if (i >= 2)
        dp[i][j] += max({dp[i - 1][1 ^ j], dp[i - 2][0], dp[i - 2][1]});
      else
        dp[i][j] += dp[i - 1][1 ^ j];
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << "\n";
  return 0;
}
