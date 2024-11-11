#include <bits/stdc++.h>
const bool DEBUG = false;
using namespace std;
const long long maxn = 2e5 + 5;
const long long INF = 1e18 + 1;
const long long M = 1e9 + 7;
const int lg = 21;
int ANS, n, m, par[maxn], mx[maxn], ans[maxn], h[maxn], dp[maxn], mn[maxn];
bool cut[maxn], mark[maxn];
vector<int> g[maxn];
void dfs_first(int v, int p = -1) {
  mark[v] = 1;
  dp[v] = h[v];
  for (auto u : g[v]) {
    if (!mark[u]) {
      h[u] = h[v] + 1, dfs_first(u, v);
      dp[v] = min(dp[v], dp[u]);
    } else if (u != p)
      dp[v] = min(dp[v], h[u]);
  }
  if (v != 0 and dp[v] >= h[v]) cut[v] = 1;
}
void dfs_second(int v, int p = -1) {
  int a = 0, b = 0, child = 0;
  mark[v] = 1;
  if (v != 0) ans[v] = ans[p];
  ans[v] += cut[v];
  for (auto u : g[v])
    if (!mark[u]) {
      dfs_second(u, v);
      mx[v] = max(mx[v], mx[u]);
      if (a < mx[u]) a = mx[u];
      if (a > b) swap(a, b);
      child++;
    }
  mx[v] = max(mx[v], ans[v]);
  ANS = max(ANS, ans[v]);
  if (child >= 2) ANS = max(ANS, a + b - 2 * ans[v]);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y, x--, y--;
    g[x].push_back(y), g[y].push_back(x);
  }
  fill(mn, mn + maxn, 10000000);
  dfs_first(0);
  fill(mark, mark + maxn, 0);
  dfs_second(0);
  cout << ANS << endl;
  return 0;
}
