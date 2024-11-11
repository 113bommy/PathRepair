#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10 * 1000 + 11, MAXL = 20;
bool mark[MAXN];
int d[MAXN], par[MAXN][MAXL], maxE[MAXN][MAXL];
vector<int> adj[MAXN], wei[MAXN];
vector<pair<int, pair<int, int> > > edge, edges;
struct Type_DSU {
  int size[MAXN], par[MAXN], h = 0;
  void make_set(int x) {
    par[x] = x;
    size[x] = 0;
    h++;
  }
  int findPar(int x) { return par[x] = (par[x] == x ? x : findPar(par[x])); }
  void merge(int x, int y) {
    x = findPar(x), y = findPar(y);
    if (x == y) return;
    if (size[y] > size[x]) swap(x, y);
    par[y] = x;
    size[x] += (size[x] == size[y]);
    h--;
    return;
  }
} DSU;
void dfs(int u) {
  mark[u] = true;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i], w = wei[u][i];
    if (!mark[v]) {
      d[v] = d[u] + 1;
      par[v][0] = u;
      maxE[v][0] = w;
      for (int j = 1; j < MAXL; j++) {
        par[v][j] = par[par[v][j - 1]][j - 1];
        maxE[v][j] = max(maxE[v][j - 1], maxE[par[v][j - 1]][j - 1]);
      }
      dfs(v);
    }
  }
  return;
}
int parent(int u, int d) {
  for (int i = 0; i < MAXL; i++)
    if ((d >> i) & 1) u = par[u][i];
  return u;
}
int maxEdge(int u, int d) {
  int ret = 0;
  for (int i = 0; i < MAXL; i++)
    if ((d >> i) & 1) {
      ret = max(ret, maxE[u][i]);
      u = par[u][i];
    }
  return ret;
}
int lca(int u, int v) {
  if (d[u] > d[v]) swap(u, v);
  int maxEE = maxEdge(v, d[v] - d[u]);
  v = parent(v, d[v] - d[u]);
  if (u == v) return maxEE;
  for (int i = MAXL - 1; i >= 0; i--)
    if (par[u][i] != par[v][i]) {
      maxEE = max(maxEE, maxE[u][i]);
      u = par[u][i];
      maxEE = max(maxEE, maxE[u][i]);
      v = par[v][i];
    }
  maxEE = max(maxEE, maxE[u][0]);
  maxEE = max(maxEE, maxE[v][0]);
  return maxEE;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) DSU.make_set(i);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge.push_back(make_pair(w, make_pair(u, v)));
  }
  sort(edge.begin(), edge.end());
  long long ans = 0;
  for (int i = 0; i < edge.size(); i++) {
    int u = edge[i].second.first, v = edge[i].second.second, w = edge[i].first;
    if (DSU.findPar(u) != DSU.findPar(v)) {
      DSU.merge(u, v);
      ans += w;
      adj[u].push_back(v);
      adj[v].push_back(u);
      wei[u].push_back(w);
      wei[v].push_back(w);
      edges.push_back(edge[i]);
    }
  }
  dfs(1);
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int a, b;
    cin >> a >> b;
    if (DSU.h > 2) {
      cout << -1 << endl;
      continue;
    }
    if (DSU.h == 2) {
      if (DSU.findPar(a) == DSU.findPar(b)) {
        cout << -1 << endl;
        continue;
      }
      cout << ans << endl;
      continue;
    }
    cout << ans - lca(a, b) << endl;
  }
  return 0;
}
