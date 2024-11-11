#include <bits/stdc++.h>
using namespace std;
int n, m, q, maxd, maxv;
int id[300005], vis[300005], vis1[300005], par[300005];
vector<int> ids;
vector<vector<int> > g;
void dfs(int v, int d, int idd) {
  vis[v] = true;
  id[v] = idd;
  if (d > maxd) {
    maxd = d;
    maxv = v;
  }
  int to = g[v].size();
  for (int(i) = 0; (i) < (to); (i)++) {
    if (vis[g[v][i]])
      continue;
    else {
      dfs(g[v][i], d + 1, idd);
    }
  }
}
void dfs1(int v, int d) {
  vis1[v] = true;
  if (d > maxd) maxd = d;
  int to = g[v].size();
  for (int(i) = 0; (i) < (to); (i)++) {
    if (vis1[g[v][i]])
      continue;
    else {
      dfs1(g[v][i], d + 1);
    }
  }
}
int root(int v) { return par[v] < 0 ? v : (par[v] = root(par[v])); }
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> q;
  int u, v;
  g.resize(n + 1);
  for (int(i) = 0; (i) < (m); (i)++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int idd = 0;
  for (int(i) = 1; (i) <= (n); (i)++) {
    if (vis[i]) continue;
    maxd = 0;
    dfs(i, 1, idd);
    maxd = 0;
    dfs1(maxv, 1);
    ids.push_back(max(0, maxd - 1));
    idd++;
  }
  memset((par), (-1), sizeof((par)));
  int x, y, ty, d1, d2, dnew, ne;
  for (int(i) = 0; (i) < (q); (i)++) {
    cin >> ty;
    if (ty == 1) {
      cin >> x;
      if (par[id[x]] < 0)
        cout << ids[id[x]] << endl;
      else
        cout << ids[par[id[x]]] << endl;
    } else {
      cin >> x >> y;
      if ((u = root(id[x])) != (v = root(id[y]))) {
        if (par[v] < par[u]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        d1 = ids[u];
        d2 = ids[v];
        dnew = max(d1, d2);
        ne = ((d1 + 1) >> 1) + ((d2 + 1) >> 1) + 1;
        ids[u] = max(dnew, ne);
        ids[v] = max(dnew, ne);
      }
    }
  }
  return 0;
}
