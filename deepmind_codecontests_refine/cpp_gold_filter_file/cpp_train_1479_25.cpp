#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  long long c[4][n + 1];
  for (long long i = 1; i <= 3; i++)
    for (long long j = 1; j <= n; j++) cin >> c[i][j];
  vector<long long> g[n + 1];
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long dp[n + 1][6], ind, par[n + 1];
  bool fg = false;
  memset(dp, 0, sizeof(dp));
  for (auto it : g) {
    if (it.size() >= 3) fg = true;
  }
  for (long long i = 1; i <= n; i++)
    if (g[i].size() == 1) ind = i;
  if (fg) {
    cout << -1;
    return 0;
  }
  par[ind] = 0;
  dp[ind][0] = dp[ind][1] = c[1][ind];
  dp[ind][2] = dp[ind][3] = c[2][ind];
  dp[ind][4] = dp[ind][5] = c[3][ind];
  long long cost = 1e18;
  for (auto itr : dp[ind]) {
    cost = min(cost, itr);
  }
  bool vis[n + 1];
  memset(vis, false, sizeof(vis));
  vis[ind] = true;
  while (1) {
    long long min1 = 1e18, cnt = 0;
    for (auto it : g[ind]) {
      if (vis[it] == false) {
        vis[it] = true;
        dp[it][0] = dp[ind][3] + c[1][it];
        dp[it][1] = dp[ind][5] + c[1][it];
        dp[it][2] = dp[ind][1] + c[2][it];
        dp[it][3] = dp[ind][4] + c[2][it];
        dp[it][4] = dp[ind][0] + c[3][it];
        dp[it][5] = dp[ind][2] + c[3][it];
        for (auto itr : dp[it]) {
          min1 = min(min1, itr);
        }
        par[it] = ind;
        ind = it;
        cnt++;
      }
    }
    if (cnt) cost = min1;
    if (!cnt) break;
  }
  cout << cost << endl;
  long long ans[n + 1];
  long long min1 = 1e18, tmp;
  for (long long i = 0; i < 6; i++) {
    if (min1 > dp[ind][i]) {
      min1 = dp[ind][i];
      tmp = i;
    }
  }
  long long xx = tmp;
  if (tmp == 0) tmp = 1;
  if (tmp == 3) tmp = 2;
  if (tmp == 4 || tmp == 5) tmp = 3;
  ans[ind] = tmp;
  long long p = ind;
  while (p != 0) {
    p = par[p];
    if (xx == 2 || xx == 1 || xx == 5)
      tmp--;
    else
      tmp++;
    if (tmp == 0) tmp = 3;
    if (tmp == 4) tmp = 1;
    ans[p] = tmp;
  }
  for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
