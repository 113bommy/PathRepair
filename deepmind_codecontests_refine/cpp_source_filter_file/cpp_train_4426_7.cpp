#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, q, pa[N][17], h[N];
vector<int> c[N], p[N], l[N][17];
vector<int> combine(vector<int> a, vector<int> b) {
  vector<int> ans(a.size() + b.size());
  merge(a.begin(), a.end(), b.begin(), b.end(), ans.begin());
  while (ans.size() > 10) ans.pop_back();
  return ans;
}
void dfs(int par, int u) {
  h[u] = h[par] + 1;
  l[u][0] = p[par];
  pa[u][0] = par;
  for (int i = 0; i < c[u].size(); i++) {
    int v = c[u][i];
    if (v == par) continue;
    dfs(u, v);
  }
}
void rmq() {
  for (int j = 1; j <= 17; j++)
    for (int i = 1; i <= n; i++) {
      if (!pa[i][j - 1]) continue;
      pa[i][j] = pa[pa[i][j - 1]][j - 1];
      l[i][j] = combine(l[i][j - 1], l[pa[i][j - 1]][j - 1]);
    }
}
vector<int> lca(int u, int v) {
  vector<int> ans;
  if (h[u] < h[v]) swap(u, v);
  int del = h[u] - h[v];
  ans = p[u];
  for (int i = 16; i >= 0; i--)
    if ((del >> i) & 1) {
      ans = combine(ans, l[u][i]);
      u = pa[u][i];
    }
  if (u == v) return ans;
  ans = combine(ans, p[v]);
  for (int i = 16; i >= 0; i--)
    if (pa[u][i] != pa[v][i]) {
      ans = combine(ans, l[u][i]);
      ans = combine(ans, l[v][i]);
      u = pa[u][i];
      v = pa[v][i];
    }
  return combine(ans, p[pa[u][0]]);
}
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    c[u].push_back(v);
    c[v].push_back(u);
  }
  for (int i = 1, x; i <= m; i++) {
    scanf("%d", &x);
    if (p[x].size() == 10) continue;
    p[x].push_back(i);
  }
  dfs(0, 1);
  rmq();
  for (int i = 1; i <= q; i++) {
    int u, v, a;
    scanf("%d %d %d", &u, &v, &a);
    vector<int> ans = lca(u, v);
    int k = min(a, int(ans.size()));
    printf("%d ", k);
    for (int i = 0; i < k; i++) printf("%d ", ans[i]);
    printf("\n");
  }
  return 0;
}
