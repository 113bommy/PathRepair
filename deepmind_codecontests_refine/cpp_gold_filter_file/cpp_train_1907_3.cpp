#include <bits/stdc++.h>
using namespace std;
const int N = 150 + 5;
int a[N], mx[N][N][N], dp[N][N];
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  string s;
  cin >> s;
  memset(mx, -1, sizeof mx);
  for (int i = 0; i <= n; i++) mx[i][i][0] = dp[i][i] = 0;
  for (int len = 1; len <= n; len++)
    for (int l = 0, r = len; r <= n; l++, r++) {
      if (~mx[l][r - 1][0] && ~a[1]) mx[l][r][0] = mx[l][r - 1][0] + a[1];
      if (s[l] == s[r - 1])
        for (int k = 0; k <= len - 2; k++)
          if (~mx[l + 1][r - 1][k] && ~a[k + 2])
            mx[l][r][0] = max(mx[l][r][0], mx[l + 1][r - 1][k] + a[k + 2]);
      for (int i = l + 1; i < r - 1; i++)
        if (s[i] == s[r - 1] && ~mx[l][i][0] && ~mx[i][r][0])
          mx[l][r][0] = max(mx[l][r][0], mx[l][i][0] + mx[i][r][0]);
      for (int i = l; i < r; i++)
        if (~mx[l][i][0] && ~mx[i + 1][r][0])
          mx[l][r][1] = max(mx[l][r][1], mx[l][i][0] + mx[i + 1][r][0]);
      for (int k = 2; k <= len; k++) {
        if (s[l] == s[r - 1]) mx[l][r][k] = mx[l + 1][r - 1][k - 2];
        for (int i = l; i < r; i++) {
          if (i > l && ~mx[l][i][0] && ~mx[i][r][k])
            mx[l][r][k] = max(mx[l][r][k], mx[l][i][0] + mx[i][r][k]);
          if (i < r - 1 && ~mx[l][i + 1][k] && ~mx[i + 1][r][0])
            mx[l][r][k] = max(mx[l][r][k], mx[l][i + 1][k] + mx[i + 1][r][0]);
        }
      }
      dp[l][r] = max(mx[l][r][0], 0);
      for (int i = l; i < r; i++)
        dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][r]);
    }
  cout << dp[0][n] << endl;
  return 0;
}
