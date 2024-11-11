#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
bool isp[N], in_p[N];
pair<int, int> par[N];
int sz[N], h[N], root = -1, dia = -1, id = -1, n, k, node1, node2, dp_up[N],
                 dp_down[N], idr, idL, idR, par_b;
vector<pair<int, int> > adj_t[N], adj[N];
vector<pair<int, int> > path;
int ans[N];
void p_dfs(int v, int p = -1) {
  if (isp[v]) sz[v]++;
  for (auto U : adj_t[v]) {
    int u = U.first, w = U.second;
    if (u == p) continue;
    p_dfs(u, v);
    sz[v] += sz[u];
    if (sz[u] > 0) {
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
  }
}
void d_dfs(int v, int p = -1, int x = 0) {
  par[v] = {p, x};
  if (p == -1) h[v] = 0;
  for (auto U : adj[v]) {
    int u = U.first, w = U.second;
    if (u == p) continue;
    h[u] = h[v] + w;
    d_dfs(u, v, w);
  }
}
int get_diametr() {
  d_dfs(root);
  for (int i = 1; i <= n; i++) {
    if (dia < h[i]) {
      root = i;
      dia = h[i];
    }
  }
  d_dfs(root);
  dia = -1;
  for (int i = 1; i <= n; i++) {
    if (dia < h[i]) {
      dia = h[i];
      id = i;
    }
  }
  while (id != -1) {
    path.push_back({id, par[id].second});
    id = par[id].first;
  }
  int sum = 0, type = 2;
  for (int i = 0; i < path.size(); i++) {
    if (sum < (long double)(dia) / 2) {
      node1 = i;
      node2 = i + 1;
    }
    sum += path[i].second;
    if (sum == (long double)(dia) / 2) {
      type = 1;
      root = path[i + 1].first;
      idr = i + 1;
      break;
    }
  }
  if (type == 2) {
    idL = node1;
    idR = node2;
    node1 = path[node1].first;
    node2 = path[node2].first;
  } else {
    node1 = path[idr - 1].first;
    node2 = path[idr + 1].first;
  }
  for (auto X : path) {
    in_p[X.first] = true;
  }
  return type;
}
void l_dfs_down(int v, int p = -1) {
  if (p == -1 || p == par_b) h[v] = 0;
  if (isp[v]) sz[v]++;
  if (isp[v]) dp_down[v] = h[v];
  for (auto U : adj[v]) {
    int u = U.first, w = U.second;
    if (u == p) continue;
    h[u] = h[v] + 1;
    l_dfs_down(u, v);
    sz[v] += sz[u];
    if (dp_down[u] != -1) dp_down[v] = max(dp_down[v], dp_down[u]);
  }
}
void l_dfs_up(int v, int p = -1) {
  if (p == -1 || p == par_b) dp_up[v] = 0;
  int mx1 = 0, mx2 = 0;
  for (auto U : adj[v]) {
    int u = U.first;
    if (u == p) continue;
    if (mx1 <= dp_down[u]) {
      mx2 = mx1;
      mx1 = dp_down[u];
    } else if (dp_down[u] >= mx2)
      mx2 = dp_down[u];
  }
  for (auto U : adj[v]) {
    int u = U.first;
    if (u == p) continue;
    if (u == node1) {
      for (auto X : adj[v]) {
        int x = X.first;
        if (x == node2 || x == node1) continue;
        dp_up[u] = max(dp_up[u], dp_down[x]);
      }
      continue;
    }
    if (u == node2) {
      for (auto X : adj[v]) {
        int x = X.first;
        if (x == node1 || x == node2) continue;
        dp_up[u] = max(dp_up[u], dp_down[x]);
      }
      continue;
    }
    dp_up[u] = dp_up[v];
    if (dp_down[u] == mx1)
      dp_up[u] = max(dp_up[u], mx2);
    else
      dp_up[u] = max(dp_up[u], mx1);
    l_dfs_up(u, v);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int v;
    cin >> v;
    isp[v] = true;
    root = v;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj_t[v].push_back({u, w});
    adj_t[u].push_back({v, w});
  }
  p_dfs(1);
  int type = get_diametr();
  if (type == 1) {
    memset(sz, 0, sizeof sz);
    memset(dp_down, -1, sizeof dp_down);
    memset(dp_up, -1, sizeof dp_up);
    par_b = -1;
    l_dfs_down(root);
    l_dfs_up(root);
    for (int i = 0; i < path.size(); i++) {
      int v = path[i].first;
      if (isp[v]) continue;
      if (i < idr) {
        if (dp_up[v] < dp_down[v])
          ans[v] = sz[node2] + sz[v];
        else
          ans[v] = sz[v];
      }
      if (v == root) {
        ans[v] = k;
      }
      if (i > idr) {
        if (dp_up[v] < dp_down[v])
          ans[v] = sz[node1] + sz[v];
        else
          ans[v] = sz[v];
      }
      for (int i = 1; i <= n; i++) {
        if (in_p[i]) continue;
        if (isp[i]) continue;
        ans[i] = sz[i];
      }
    }
  } else if (type == 2) {
    memset(sz, 0, sizeof sz);
    memset(dp_down, -1, sizeof dp_down);
    memset(dp_up, -1, sizeof dp_up);
    par_b = node2;
    l_dfs_down(node1, node2);
    l_dfs_up(node1, node2);
    par_b = node1;
    l_dfs_down(node2, node1);
    l_dfs_up(node2, node1);
    for (int i = 0; i < path.size(); i++) {
      int v = path[i].first;
      if (isp[v]) continue;
      if (i <= idL) {
        if (dp_up[v] < dp_down[v])
          ans[v] = sz[node2] + sz[v];
        else
          ans[v] = sz[v];
      }
      if (i >= idR) {
        if (dp_up[v] < dp_down[v])
          ans[v] = sz[node1] + sz[v];
        else
          ans[v] = sz[v];
      }
    }
    for (int i = 1; i <= n; i++) {
      if (in_p[i]) continue;
      if (isp[i]) continue;
      ans[i] = sz[i];
    }
  }
  int mxi = -1;
  for (int i = 1; i <= n; i++) mxi = max(mxi, ans[i]);
  if (mxi == 0) {
    cout << 0 << ' ' << n - k << '\n';
    return 0;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (ans[i] == mxi) cnt++;
  cout << mxi << ' ' << cnt << '\n';
}
