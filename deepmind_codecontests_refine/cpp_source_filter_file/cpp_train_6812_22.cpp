#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<vector<vector<int>>> dp(n,
                                 vector<vector<int>>(m, vector<int>(k + 1, 0)));
  vector<vector<vector<bool>>> f(
      n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
  vector<vector<vector<int>>> pre(n,
                                  vector<vector<int>>(m, vector<int>(k + 1)));
  for (int i = 0; i < m; i++) {
    int x = v[n - 1][i] - '0';
    f[n - 1][i][x % (k + 1)] = true;
    dp[n - 1][i][x % (k + 1)] = x;
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < m; j++) {
      for (int r = 0; r <= k; r++) {
        if (j > 1) {
          int x = v[i - 1][j - 1] - '0';
          if (f[i][j][r] &&
              dp[i - 1][j - 1][(r + x) % (k + 1)] < dp[i][j][r] + x) {
            f[i - 1][j - 1][(r + x) % (k + 1)] = true;
            dp[i - 1][j - 1][(r + x) % (k + 1)] = dp[i][j][r] + x;
            pre[i - 1][j - 1][(r + x) % (k + 1)] = j;
          }
        }
        if (j < m - 1) {
          int x = v[i - 1][j + 1] - '0';
          if (f[i][j][r] &&
              dp[i - 1][j + 1][(r + x) % (k + 1)] < dp[i][j][r] + x) {
            f[i - 1][j + 1][(r + x) % (k + 1)] = true;
            dp[i - 1][j + 1][(r + x) % (k + 1)] = dp[i][j][r] + x;
            pre[i - 1][j + 1][(r + x) % (k + 1)] = j;
          }
        }
      }
    }
  }
  int mx = -1, idx;
  for (int i = 0; i < m; i++) {
    if (f[0][i][0]) {
      if (dp[0][i][0] > mx) {
        mx = dp[0][i][0];
        idx = i;
      }
    }
  }
  if (mx == -1)
    puts("-1");
  else {
    vector<char> ans;
    int j = idx, now = 0;
    for (int i = 0; i < n - 1; i++) {
      int x = v[i][j] - '0';
      int nxt = pre[i][j][now];
      now = ((now - x) % (k + 1) + (k + 1)) % (k + 1);
      if (nxt < j) {
        ans.push_back('R');
      } else {
        ans.push_back('L');
      }
      j = nxt;
    }
    reverse(ans.begin(), ans.end());
    cout << mx << '\n';
    cout << j + 1 << '\n';
    for (char ch : ans) cout << ch;
  }
  return 0;
}
