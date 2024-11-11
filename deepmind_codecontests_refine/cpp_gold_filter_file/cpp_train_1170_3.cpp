#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int pos = 0;
    vector<vector<char> > v(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> v[i][j];
        if (v[i][j] == '.') {
          pos++;
        }
      }
    }
    if ((2 * x) <= y) {
      cout << pos * x << '\n';
      continue;
    }
    int ans = 0;
    vector<vector<int> > dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (v[i][j] == '.') {
          if (j == 0 || dp[i][j - 1] == 0 || dp[i][j - 1] == 3) {
            dp[i][j] = 1;
            ans += x;
          } else {
            dp[i][j] = 3;
            ans -= x;
            ans += y;
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
