#include <bits/stdc++.h>
using namespace std;
int sz[200005], dp[200005], n, x, y, mx;
vector<int> g[200005];
void dfs_sz(int v, int par = -1) {
  sz[v] = 1;
  for (auto i : g[v]) {
    if (i == par) continue;
    dfs_sz(i, v);
    sz[v] += sz[i];
  }
  return;
}
void dfs_dp(int v, int par = -1) {
  dp[v] = sz[v];
  for (auto i : g[v]) {
    if (i == par) continue;
    dfs_dp(i, v);
    dp[v] += dp[i];
  }
  return;
}
void calcdp(int v, int par = -1) {
  mx = max(mx, dp[v]);
  for (auto to : g[v]) {
    if (to == par) continue;
    dp[v] -= dp[to];
    dp[v] -= sz[to];
    sz[v] -= sz[to];
    sz[to] += sz[v];
    dp[to] += sz[v];
    dp[to] += dp[v];
    calcdp(to, v);
    dp[to] -= dp[v];
    dp[to] -= sz[v];
    sz[to] -= sz[v];
    sz[v] += sz[to];
    dp[v] += sz[to];
    dp[v] += dp[to];
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs_sz(1);
  dfs_dp(1);
  calcdp(1);
  cout << mx;
}
