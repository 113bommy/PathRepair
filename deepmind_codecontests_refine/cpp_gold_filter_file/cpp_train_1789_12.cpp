#include <bits/stdc++.h>
using namespace std;
vector<int> e[1005];
int sz[1005], r = 0, n, C, fa[1005], ans[1005], dep[1005], dfn;
inline void dfs(int u, int f, int flag) {
  dep[u] = ++dfn;
  int mx = 0;
  sz[u] = 1, fa[u] = f, ans[u] = C;
  for (auto v : e[u]) {
    if (v == f) continue;
    dfs(v, u, flag), sz[u] += sz[v], mx = max(mx, sz[v]);
  }
  mx = max(mx, n - sz[u]);
  if (flag)
    if (mx <= n / 2) r = u;
}
vector<pair<int, int> > s;
int dp[1005][1005], qwq[1005];
signed main(int argc, char** argv) {
  cin >> n;
  int goal = n * n * 2 / 9;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0, 1), dfs(r, 0, 0);
  for (auto v : e[r]) s.push_back({sz[v], v});
  dp[0][0] = 1;
  for (int i = 0; i < s.size(); i++) {
    for (int j = s[i].first; j <= n; j++) dp[i + 1][j] |= dp[i][j - s[i].first];
    for (int j = 0; j <= n; j++) dp[i + 1][j] |= dp[i][j];
  }
  int now, Now;
  for (int i = n / 2; i >= 0; i--) {
    if (dp[s.size()][i]) {
      now = i;
      break;
    }
  }
  Now = now;
  for (int i = s.size(); i >= 1; i--)
    if (now >= s[i - 1].first && dp[i - 1][now - s[i - 1].first])
      qwq[s[i - 1].second] = 1, now -= s[i - 1].first;
  int sum1 = 1, sum2 = 1;
  dfn = 0;
  for (auto v : e[r])
    if (qwq[v]) C = 1, dfs(v, r, 0);
  dfn = 0;
  for (auto v : e[r])
    if (!qwq[v]) C = Now + 1, dfs(v, r, 0);
  for (int i = 1; i <= n; i++) ans[i] *= dep[i];
  for (int i = 1; i <= n; i++)
    if (fa[i]) cout << i << " " << fa[i] << " " << ans[i] - ans[fa[i]] << "\n";
  return 0;
}
