#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int nmax = 200010;
const int MOD = (1e9) + 7;
int n;
int a[nmax];
void solve() {
  string s;
  cin >> n;
  cin >> s;
  s = " " + s;
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<vector<long long int>> dp(4, vector<long long int>(n + 1, 1e9));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] != 'h' && s[i] != 'a' && s[i] != 'r' && s[i] != 'd') {
      for (int j = 0; j < 4; j++) dp[j][i] = dp[j][i - 1];
      continue;
    }
    if (s[i] == 'h') {
      for (int j = 0; j < 4; j++)
        if (j != 1 && j != 0) dp[j][i] = min(dp[j][i], dp[j][i - 1]);
      dp[1][i] = min(dp[1][i], min(dp[1][i - 1], dp[0][i - 1]));
      dp[0][i] = min(dp[0][i], dp[0][i - 1] + a[i]);
    } else if (s[i] == 'a') {
      for (int j = 0; j < 4; j++)
        if (j != 2 && j != 1) dp[j][i] = min(dp[j][i], dp[j][i - 1]);
      dp[2][i] = min(dp[2][i], min(dp[2][i - 1], dp[1][i - 1]));
      dp[1][i] = min(dp[1][i], dp[1][i - 1] + a[i]);
    } else if (s[i] == 'r') {
      for (int j = 0; j < 4; j++)
        if (j != 3 && j != 2) dp[j][i] = min(dp[j][i], dp[j][i - 1]);
      dp[3][i] = min(dp[3][i], min(dp[3][i - 1], dp[2][i - 1]));
      dp[2][i] = min(dp[2][i], dp[2][i - 1] + a[i]);
    } else {
      for (int j = 0; j < 4; j++)
        if (j != 3) dp[j][i] = min(dp[j][i], dp[j][i - 1]);
      dp[3][i] = min(dp[3][i], dp[3][i - 1] + a[i]);
    }
  }
  long long int ans = dp[0][n];
  for (int i = 0; i < 4; i++) ans = min(ans, dp[i][n]);
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
