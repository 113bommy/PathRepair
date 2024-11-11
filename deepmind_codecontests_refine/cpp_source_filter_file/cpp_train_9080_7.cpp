#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
void fix(int &x) {
  if (x >= MOD) {
    x -= MOD;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  char s[1000005], t[1000005];
  cin >> (s + 1) >> (t + 1);
  int n = strlen(s + 1);
  int m = strlen(t + 1);
  int ans = 0;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = m; i <= n; ++i) {
    if (i > m || s[i] == t[m]) {
      dp[i][0] = 1;
    }
    if (s[i] == t[i]) {
      dp[i][1] = 1;
    }
  }
  for (int i = n; i > 1; --i) {
    for (int j = 0; j <= n - i + 1; ++j) {
      if (j + 1 > m || s[i - 1] == t[j + 1]) {
        dp[i - 1][j + 1] += dp[i][j];
        fix(dp[i - 1][j + 1]);
      }
      if (i > 1) {
        int x = j + i - 1;
        if (x > m || s[i - 1] == t[x]) {
          dp[i - 1][j] += dp[i][j];
          fix(dp[i - 1][j]);
        }
      }
    }
  }
  for (int j = 0; j <= n; ++j) {
    ans += dp[1][j];
    fix(ans);
  }
  cout << ans << '\n';
  return 0;
}
