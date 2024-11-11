#include <bits/stdc++.h>
using namespace std;
const int N = 152, INF = 1e8;
int n, a[N], ans[N][N], dp[N][N][N];
string s;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == -1) a[i] = -INF;
  }
  cin >> s;
  for (int i = 0; i <= n; i++) {
    fill(*dp[i], *end(dp[i]), -INF);
    dp[i][i][0] = dp[i][i + 1][1] = 0;
  }
  for (int len = 1; len <= n; len++)
    for (int l = 0, r = len; r <= n; l++, r++) {
      for (int x = 1; x <= len; x++) {
        if (x >= 2 && s[l] == s[r - 1]) dp[l][r][x] = dp[l + 1][r - 1][x - 2];
        for (int i = l + 1; i < r; i++)
          dp[l][r][x] = max({dp[l][r][x], dp[l][i][x] + dp[i][r][0],
                             dp[l][i][0] + dp[i][r][x]});
        dp[l][r][0] = max(dp[l][r][0], dp[l][r][x] + a[x]);
      }
      ans[l][r] = dp[l][r][0];
      for (int i = l + 1; i < r; i++)
        ans[l][r] = max(ans[l][r], ans[l][i] + ans[i][r]);
    }
  cout << max(ans[0][n], 0) << endl;
}
