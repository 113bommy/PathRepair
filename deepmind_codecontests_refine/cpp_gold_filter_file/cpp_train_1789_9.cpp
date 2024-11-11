#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[1009];
int siz[1009], w[1009], mx = 1009, rt;
void dfs1(int u, int fa) {
  siz[u] = 1;
  for (auto v : g[u])
    if (v != fa) {
      dfs1(v, u);
      siz[u] += siz[v];
      w[u] = max(w[u], siz[v]);
    }
  w[u] = max(w[u], n - siz[u]);
  if (mx > w[u]) mx = w[u], rt = u;
}
void dfs2(int u, int fa) {
  siz[u] = 1;
  for (auto v : g[u])
    if (v != fa) {
      dfs2(v, u);
      siz[u] += siz[v];
    }
}
int tot, z[1009], base;
void dfs3(int u, int fa) {
  tot += base;
  z[u] = tot;
  cout << u << " " << fa << " " << tot - z[fa] << endl;
  for (auto v : g[u])
    if (v != fa) dfs3(v, u);
}
pair<int, int> a[1009];
int na;
int main() {
  cin >> n;
  for (int i = 1, u, v; i < n; i++)
    cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
  dfs1(1, 0);
  dfs2(rt, 0);
  for (auto v : g[rt]) a[++na] = pair<int, int>(siz[v], v);
  sort(a + 1, a + na + 1);
  int mid = 0, sum = 0;
  for (int i = 1; i <= na; i++) {
    sum += a[i].first;
    if (sum >= (n - 1) / 3) {
      mid = i;
      break;
    }
  }
  base = 1;
  for (int i = 1; i <= mid; i++) {
    dfs3(a[i].second, rt);
  }
  base = tot + 1;
  tot = 0;
  for (int i = mid + 1; i <= na; i++) {
    dfs3(a[i].second, rt);
  }
  return 0;
}
