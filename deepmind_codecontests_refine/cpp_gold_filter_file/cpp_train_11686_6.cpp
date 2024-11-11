#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, n;
  string s, t;
  cin >> T;
  while (T--) {
    cin >> n >> s >> t;
    s = '.' + s;
    t = '.' + t;
    vector<vector<int> > dp(n + 1, vector<int>(n + 1));
    vector<vector<int> > suf_s(n + 2, vector<int>(26)),
        suf_t(n + 2, vector<int>(26));
    for (int i = n; i >= 1; i--) {
      for (int k = 0; k <= 25; k++)
        suf_s[i][k] = suf_s[i + 1][k], suf_t[i][k] = suf_t[i + 1][k];
      ++suf_s[i][s[i] - 'a'];
      ++suf_t[i][t[i] - 'a'];
    }
    bool ok = 1;
    for (int i = 0; i <= 25; i++)
      if (suf_s[1][i] != suf_t[1][i]) ok = 0;
    if (!ok) {
      cout << -1 << endl;
      continue;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        int x = dp[i - 1][j] + 1;
        if (s[i] == t[j]) x = min(x, dp[i - 1][j - 1]);
        if (suf_s[i + 1][t[j] - 'a'] > suf_t[j + 1][t[j] - 'a'])
          x = min(x, dp[i][j - 1]);
        dp[i][j] = x;
      }
    cout << dp[n][n] << endl;
  }
}
