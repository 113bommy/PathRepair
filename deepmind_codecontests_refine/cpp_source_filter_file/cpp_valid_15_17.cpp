#include <bits/stdc++.h>
using namespace std;
const long long mod1 = 998244353;
const long long mod2 = 1000000007;
int t, n, k, u, v;
vector<int> con[105];
int dp[105][105];
int cnt[105][105];
int par[105];
int res, mx;
int dfs(int i, int p = -1) {
  par[i] = p;
  int ret = -1;
  for (int j = 0, l = con[i].size(); j < l; ++j)
    if (con[i][j] != p) ret = max(ret, dfs(con[i][j], i));
  return ++ret;
}
int cnts(int i, int d) {
  if (cnt[i][d] != -1) return cnt[i][d];
  if (d == 0) return cnt[i][d] = 1;
  int ret = 0;
  for (int j = 0, l = con[i].size(); j < l; ++j)
    if (con[i][j] != par[i]) ret += cnts(con[i][j], d - 1);
  return cnt[i][d] = ret;
}
void Q() {
  cin >> n >> k;
  res = 0;
  for (int i = 1; i <= (n); ++i) con[i].clear();
  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    con[u].push_back(v);
    con[v].push_back(u);
  }
  if (k == 2) {
    cout << 1ll * (n - 1) * n / 2 % mod2 << endl;
    return;
  }
  for (int r = 1; r <= n; ++r) {
    memset(cnt, -1, sizeof(cnt));
    mx = dfs(r);
    for (int d = 1; d <= mx; ++d) {
      memset(dp, 0, sizeof(dp));
      dp[0][0] = 1;
      for (int i = 0, l = con[r].size(); i <= l; ++i)
        for (int j = 0; j <= i && j <= k; ++j) {
          dp[i + 1][j] += dp[i][j];
          if (dp[i + 1][j] >= mod2) dp[i + 1][j] -= mod2;
          if (i != l) {
            dp[i + 1][j + 1] += 1ll * dp[i][j] * cnts(con[r][i], d - 1);
            if (dp[i + 1][j + 1] >= mod2) dp[i + 1][j + 1] -= mod2;
          }
        }
      res += dp[con[r].size()][k];
      if (res >= mod2) res -= mod2;
    }
  }
  cout << res << endl;
}
int main() {
  cin >> t;
  while (t--) Q();
  return 0;
}
