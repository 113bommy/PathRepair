#include <bits/stdc++.h>
using namespace std;
int n, m, res;
string s, w;
vector<int> dp[100007];
int kmp[100007];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> s >> w;
  n = s.size();
  m = w.size();
  s = '#' + s;
  w = '#' + w;
  for (int i = 0; i <= n + 3; ++i) {
    dp[i].resize(m + 3);
    fill((dp[i]).begin(), (dp[i]).end(), -1);
  }
  int q = 0;
  for (int i = 2; i <= m; ++i) {
    while (q && w[i] != w[q + 1]) q = kmp[q];
    if (w[i] == w[q + 1]) ++q;
    kmp[i] = q;
  }
  dp[0][0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = m - 1; j >= 0; --j) {
      if (s[i + 1] == '?' || s[i + 1] == w[j + 1]) {
        if (j + 1 == m)
          dp[i + 1][kmp[j + 1]] = max(dp[i + 1][kmp[j + 1]], dp[i][j] + 1);
        else
          dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
      }
      dp[i][kmp[j]] = max(dp[i][kmp[j]], dp[i][j]);
      dp[i + 1][0] = max(dp[i + 1][0], dp[i][j]);
    }
  }
  for (int i = 0; i <= m; ++i) {
    res = max(res, dp[n][i]);
  }
  cout << res;
}
