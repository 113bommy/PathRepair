#include <bits/stdc++.h>
using namespace std;
int dp[105][105][2];
pair<int, int> c[105];
int e[105];
bool u[105];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string type;
    int val;
    cin >> type >> val;
    c[i] = make_pair(val, type == "ATK" ? 0 : 1);
  }
  for (int i = 0; i < m; i++) cin >> e[i];
  sort(c, c + n);
  sort(e, e + m);
  int l = 0, r = 0;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (c[i].second == 1) {
      while (l < m && c[i].first >= e[l]) ++l;
      if (l == m) {
        ok = false;
        break;
      }
      u[l] = true;
      ++l;
    }
  }
  int ans = 0;
  if (ok) {
    l = 0;
    for (int i = 0; i < n; i++) {
      if (c[i].second == 0) {
        while (l < m && c[i].first > e[l] && u[l] == false) ++l;
        if (l == m) {
          ok = false;
          break;
        }
        ++l;
      }
    }
  }
  if (ok) {
    int sum1 = 0;
    for (int i = 0; i < n; i++) {
      if (c[i].second == 0) sum1 += c[i].first;
    }
    int sum2 = 0;
    for (int i = 0; i < m; i++) {
      if (u[i] == false) {
        sum2 += e[i];
      }
    }
    ans = sum2 - sum1;
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k < 2; k++) {
        if (dp[i][j][k] == -1) continue;
        if (j == n) {
          if (k == 0)
            dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + e[i]);
          continue;
        }
        dp[i][j + 1][1] = max(dp[i][j + 1][1], dp[i][j][k]);
        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
        if (e[i] >= c[j].first && c[j].second == 0)
          dp[i + 1][j + 1][k] =
              max(dp[i + 1][j + 1][k], dp[i][j][k] + e[i] - c[j].first);
        if (e[i] > c[j].first && c[j].second == 1)
          dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k]);
      }
    }
  }
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++)
      for (int k = 0; k < n; k++) ans = max(ans, dp[i][j][k]);
  }
  cout << ans << endl;
  return 0;
}
