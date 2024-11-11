#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
long long n, m, grp, ans, timer;
vector<pair<long long, long long>> g[N];
vector<long long> tree[N], comp[N];
long long isBridge[N], tin[N], low[N], vis[N], tout[N];
void dfs1(long long v, long long p) {
  vis[v] = 1;
  timer++;
  tin[v] = timer;
  low[v] = timer;
  for (auto it : g[v]) {
    long long u = it.first, idx = it.second;
    if (!vis[u]) {
      dfs1(u, v);
      low[v] = min(low[v], low[u]);
      if (low[u] > tin[v]) {
        isBridge[idx] = 1;
      }
    } else if (u != p) {
      low[v] = min(low[v], tin[u]);
    }
  }
  tout[v] = timer;
}
void dfs2(long long v, long long cmp) {
  queue<long long> q;
  q.push(v);
  vis[v] = 1;
  while (q.size()) {
    v = q.front();
    q.pop();
    comp[cmp].push_back(v);
    for (auto it : g[v]) {
      long long u = it.first, idx = it.second;
      if (vis[u]) {
        continue;
      }
      if (isBridge[idx]) {
        grp++;
        tree[grp].push_back(cmp);
        tree[cmp].push_back(grp);
        dfs2(u, grp);
      } else {
        q.push(u);
        vis[u] = 1;
      }
    }
  }
}
long long dfs3(long long v) {
  long long mx1 = 0;
  vis[v] = 1;
  for (auto u : tree[v]) {
    if (vis[u]) {
      continue;
    }
    long long mx2 = 1 + dfs3(u);
    ans = max(ans, mx1 + mx2);
    mx1 = max(mx1, mx2);
  }
  return mx1;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  memset(vis, 0, sizeof(vis));
  dfs1(1, 0);
  grp++;
  memset(vis, 0, sizeof(vis));
  dfs2(1, 1);
  memset(vis, 0, sizeof(vis));
  dfs3(1);
  cout << ans << endl;
  return 0;
}
