#include <bits/stdc++.h>
using namespace std;
vector<int> edge[100005];
int up[19][100005];
int depth[100005];
vector<int> vs;
int rev[100005];
void dfs(int v, int u, int d) {
  depth[v] = d;
  up[0][v] = u;
  vs.push_back(v);
  rev[v] = vs.size() - 1;
  for (int i = 0; i < edge[v].size(); i++) {
    if (edge[v][i] == u) continue;
    dfs(edge[v][i], v, d + 1);
  }
}
set<int> se;
int lca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int i = 0; i < 19; i++) {
    if ((((depth[v] - depth[u]) >> i) & 1)) {
      v = up[i][v];
    }
  }
  if (u == v) return v;
  for (int i = 18; i >= 0; i--) {
    if (up[i][u] != up[i][v]) {
      u = up[i][u];
      v = up[i][v];
    }
  }
  return up[0][u];
}
int calc(int x) {
  if (se.empty()) return 1;
  set<int>::iterator it = se.lower_bound(rev[x]);
  int a = vs[it == se.end() ? *se.begin() : *it];
  int b = vs[it == se.begin() ? *se.rbegin() : *--it];
  return depth[x] - depth[lca(x, a)] - depth[lca(x, b)] + depth[lca(a, b)];
}
int main() {
  srand((unsigned int)time(NULL));
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  dfs(1, -1, 0);
  for (int i = 0; i < 18; i++) {
    for (int j = 1; j <= n; j++) {
      if (up[i][j] == -1)
        up[i + 1][j] = -1;
      else
        up[i + 1][j] = up[i][up[i][j]];
    }
  }
  int en = 1, cur = 0, ret = 0;
  for (int i = 1; i <= n; i++) {
    while (cur <= k) {
      ret = max(ret, en - i);
      if (en > n) break;
      cur += calc(en);
      se.insert(rev[en++]);
    }
    se.erase(rev[en]);
    cur -= calc(en);
  }
  printf("%d\n", ret);
}
