#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int fa[N], d[N][2], d2[N], a[N], cnt[N], mx[N], ans[N];
vector<int> G[N], vec[N];
void dfs1(int u, int f) {
  d[u][1] = -1e9;
  for (int i = 0, iend = G[u].size(); i < iend; ++i) {
    int v = G[u][i];
    if (v != f) {
      dfs1(v, u), fa[v] = u;
      if (d[v][0] + 1 > d[u][0])
        d[u][1] = d[u][0], d[u][0] = d[v][0] + 1;
      else if (d[v][0] + 1 > d[u][1])
        d[u][1] = d[v][0] + 1;
    }
  }
}
void dfs2(int u, int f) {
  for (int i = 0, iend = G[u].size(); i < iend; ++i) {
    int v = G[u][i];
    if (v != f) {
      d2[v] = max(d2[u], d[v][0] + 1 == d[u][0] ? d[u][1] : d[u][0]) + 1;
      dfs2(v, u);
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v), G[v].push_back(u);
  }
  dfs1(1, 0), dfs2(1, 0);
  for (int u = 1; u <= n; ++u) {
    for (int i = 0, iend = G[u].size(); i < iend; ++i) {
      int v = G[u][i];
      if (v != fa[u]) vec[d[v][0] + 1].push_back(u);
    }
    if (fa[u]) {
      vec[d2[u]].push_back(u);
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = 0, jend = vec[i].size(); j < jend; ++j) {
      int u = vec[i][j];
      ans[2 * i + 1] = max(ans[2 * i + 1], cnt[u] + 1);
    }
    for (int j = 0, jend = vec[i].size(); j < jend; ++j) {
      int u = vec[i][j];
      mx[fa[u]] = max(mx[fa[u]], ++cnt[u]);
      ans[2 * i] = max(ans[2 * i], cnt[u]);
      ans[2 * i - 1] = max(ans[2 * i - 1], cnt[u]);
      ans[2 * i] = max(ans[2 * i], cnt[fa[u]] + cnt[u] - 2);
      ans[2 * i] = max(ans[2 * i], mx[u] + cnt[u] - 2);
    }
  }
  for (int i = n; i >= 1; --i) ans[i] = max(ans[i], ans[i + 2]);
  for (int u = 1; u <= n; ++u) ans[1] = max(ans[1], 1 + (int)G[u].size());
  for (int i = 1; i <= n; ++i) printf("%d ", max(ans[i], 1));
  return 0;
}
