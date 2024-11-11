#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> nxt(n, vector<int>(26, m));
    nxt[n - 1][s[n - 1] - 'a'] = m - 1;
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        nxt[i][j] = nxt[i + 1][j];
      }
      nxt[i][s[i] - 'a'] = i;
    }
    bool ans = false;
    for (int i = 0; i <= m - 1; i++) {
      vector<vector<int>> dp(i + 1, vector<int>(m - i + 1, INF));
      dp[0][0] = 0;
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k <= m - i; k++) {
          if (dp[j][k] < m) {
            if (j < i) {
              dp[j + 1][k] = min(dp[j + 1][k], nxt[dp[j][k]][t[j] - 'a'] + 1);
            }
            if (k < m - i) {
              dp[j][k + 1] =
                  min(dp[j][k + 1], nxt[dp[j][k]][t[k + i] - 'a'] + 1);
            }
          }
        }
      }
      if (dp[i][m - i] <= m) {
        ans = true;
      }
    }
    if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
