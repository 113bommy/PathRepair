#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
vector<int> ed[N], child[N], cc_ed[N];
bool bridge[N][N];
int tin[N], low[N], id[N], cc_sz[N], sub_sz[N];
void dfs_bridge(int u, int p, int& tm) {
  low[u] = tin[u] = ++tm;
  for (int i = 0; i < ed[u].size(); ++i) {
    int v = ed[u][i];
    if (v == p) continue;
    if (tin[v] > 0) {
      low[u] = min(low[u], tin[v]);
    } else {
      dfs_bridge(v, u, tm);
      child[u].push_back(v);
      low[u] = min(low[u], low[v]);
    }
  }
}
void dfs_cc(int u, int k) {
  if (id[u]) return;
  ++cc_sz[k];
  id[u] = k;
  for (int i = 0; i < ed[u].size(); ++i) {
    int v = ed[u][i];
    if (!bridge[u][v]) {
      dfs_cc(v, k);
    }
  }
}
pair<int, int> dfs(int u, int p) {
  int sz = cc_sz[u];
  int r = sz * sz;
  for (int i = 0; i < cc_ed[u].size(); ++i) {
    int v = cc_ed[u][i];
    if (v == p) continue;
    pair<int, int> x = dfs(v, u);
    sz = sz + x.first;
    r = r + cc_sz[u] * x.first + x.second;
  }
  return make_pair(sz, r);
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    ed[u].push_back(v);
    ed[v].push_back(u);
  }
  int tm = 0;
  dfs_bridge(1, 0, tm);
  for (int u = 1; u <= n; ++u) {
    for (int i = 0; i < child[u].size(); ++i) {
      int v = child[u][i];
      if (low[v] > tin[u]) {
        bridge[v][u] = bridge[u][v] = 1;
      }
    }
  }
  int cc_cnt = 0;
  for (int u = 1; u <= n; ++u)
    if (!id[u]) {
      dfs_cc(u, ++cc_cnt);
    }
  for (int u = 1; u <= n; ++u) {
    int uid = id[u];
    for (int i = 0; i < ed[u].size(); ++i) {
      int v = ed[u][i];
      int vid = id[v];
      if (vid == uid) continue;
      cc_ed[uid].push_back(vid);
      cc_ed[vid].push_back(uid);
    }
  }
  for (int u = 1; u <= cc_cnt; ++u) {
    sort(cc_ed[u].begin(), cc_ed[u].end());
    cc_ed[u].erase(unique(cc_ed[u].begin(), cc_ed[u].end()), cc_ed[u].end());
  }
  int ans = 0;
  for (int root = 1; root <= cc_cnt; ++root) {
    bool can[N] = {0};
    can[0] = 1;
    int sz = cc_sz[root];
    int r = sz * sz, sum = 0;
    for (int i = 0; i < cc_ed[root].size(); ++i) {
      int u = cc_ed[root][i];
      pair<int, int> x = dfs(u, root);
      r = r + x.second;
      for (int j = sum; j >= 0; --j)
        if (can[j]) {
          can[j + x.first] = 1;
        }
      sum = sum + x.first;
    }
    int add = 0;
    for (int i = 0; i <= sum; ++i)
      if (can[i]) {
        int val = i * sz + i * (sum - i) + sz * (sum - i);
        add = max(add, val);
      }
    ans = max(ans, r + add);
  }
  printf("%d", ans);
}
