#include <bits/stdc++.h>
using namespace std;
const int len = 510;
int dp[len][len];
vector<int> c[len];
const int none = 1 << 30;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    vector<int> p;
    for (int j = 0; j < m; j++)
      if (s[j] == '1') p.push_back(j);
    c[i].resize(p.size() + 1, 0);
    if (p.size() != 0) c[i][0] = p[p.size() - 1] - p[0] + 1;
    for (int j = 1; j < p.size(); j++) {
      c[i][j] = none;
      for (int l = 0; l <= j; l++) {
        c[i][j] = min(c[i][j], p[p.size() - j + l - 1] - p[l] + 1);
      }
    }
    if (p.size() != 0) {
      c[i][p.size()] = 0;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = none;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      if (dp[i][j] < none) {
        for (int t = 0; t <= min(k, (int)c[i].size() - 1); t++) {
          if (j + t <= k) {
            dp[i + 1][j + t] = min(dp[i + 1][j + t], dp[i][j] + c[i][t]);
          }
        }
      }
    }
  }
  int ans = none;
  for (int i = 0; i <= k; i++) {
    ans = min(ans, dp[n][i]);
  }
  cout << ans;
}
