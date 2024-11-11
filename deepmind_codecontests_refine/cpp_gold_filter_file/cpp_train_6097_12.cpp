#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);
const int MX = 2e5 + 5;
long long mod = 1e9 + 7;
int par[MX];
int skip(int u) { return par[u] = (par[u] == u ? u : skip(par[u])); }
int c[MX], w[MX], ord[MX];
vector<int> adj[MX], xadj[MX];
int pari[20][MX], maxi[20][MX];
int level[MX];
void dfs(int u, int p, int parEdgesId) {
  level[u] = level[p] + 1;
  pari[0][u] = p;
  maxi[0][u] = parEdgesId;
  for (int i = 0; i < ((int)(adj[u]).size()); i++) {
    if (p != adj[u][i]) dfs(adj[u][i], u, xadj[u][i]);
  }
}
int x[MX], y[MX];
bool isSeleced[MX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> c[i];
    ord[i] = i;
  }
  for (int i = 1; i <= m; i++) cin >> x[i] >> y[i];
  for (int i = 1; i <= n; i++) par[i] = i;
  int *__ = w;
  sort(ord + 1, ord + m + 1, [__](int i, int j) { return __[i] < __[j]; });
  c[0] = mod;
  int minInTree = 0;
  long long mst = 0;
  for (int j = 1, k = n - 1; j <= m and k; j++) {
    int i = ord[j];
    int u = skip(x[i]);
    int v = skip(y[i]);
    if (u != v) {
      k--;
      isSeleced[i] = true;
      mst += w[i];
      par[u] = v;
      if (c[i] < c[minInTree]) minInTree = i;
      adj[x[i]].push_back(y[i]);
      adj[y[i]].push_back(x[i]);
      xadj[x[i]].push_back(i);
      xadj[y[i]].push_back(i);
    }
  }
  dfs(1, 0, 0);
  for (int j = 1; (1 << j) < n; j++) {
    for (int u = 1; u <= n; u++) {
      pari[j][u] = pari[j - 1][pari[j - 1][u]];
      maxi[j][u] = w[maxi[j - 1][u]] > w[maxi[j - 1][pari[j - 1][u]]]
                       ? maxi[j - 1][u]
                       : maxi[j - 1][pari[j - 1][u]];
    }
  }
  int s;
  cin >> s;
  int maximum_benifit = s / c[minInTree];
  int best_candidate = minInTree;
  int willReplace = 0;
  for (int i = 1; i <= m; i++) {
    if (not isSeleced[i]) {
      int u = x[i], v = y[i];
      int max_edges_along_path = 0;
      if (level[u] > level[v]) swap(u, v);
      if (level[v] > level[u]) {
        int k = floor(log2(level[v] - level[u]));
        while (level[u] < level[v]) {
          if (level[pari[k][v]] >= level[u]) {
            if (w[max_edges_along_path] < w[maxi[k][v]])
              max_edges_along_path = maxi[k][v];
            v = pari[k][v];
          }
          k--;
        }
      }
      int k = floor(log2(level[u]));
      if (u != v) {
        while (k >= 0) {
          if (pari[k][u] != pari[k][v]) {
            if (w[max_edges_along_path] < w[maxi[k][v]])
              max_edges_along_path = maxi[k][v];
            if (w[max_edges_along_path] < w[maxi[k][u]])
              max_edges_along_path = maxi[k][u];
            u = pari[k][u];
            v = pari[k][v];
          }
          k--;
        }
        if (w[max_edges_along_path] < w[maxi[0][v]])
          max_edges_along_path = maxi[0][v];
        if (w[max_edges_along_path] < w[maxi[0][u]])
          max_edges_along_path = maxi[0][u];
      }
      int benifit = w[max_edges_along_path] - w[i] + s / c[i];
      if (benifit > maximum_benifit) {
        maximum_benifit = benifit;
        best_candidate = i;
        willReplace = max_edges_along_path;
      }
    }
  }
  isSeleced[best_candidate] = 1;
  isSeleced[willReplace] = 0;
  w[best_candidate] -= s / c[best_candidate];
  cout << mst - maximum_benifit << '\n';
  for (int i = 1; i <= m; i++)
    if (isSeleced[i]) cout << i << " " << w[i] << '\n';
  return 0;
}
