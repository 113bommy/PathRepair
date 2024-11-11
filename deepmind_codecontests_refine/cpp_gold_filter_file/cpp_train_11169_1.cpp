#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 5e3 + 10;
int dp[maxn][maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 2;
      } else
        dp[i][j] = max({0, dp[i - 1][j] - 1, dp[i][j - 1] - 1});
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';
}
