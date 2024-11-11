#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
  int n;
  vector<int> par, rnk;
  UnionFind(int n) : n(n), par(n), rnk(n) {
    for (int i = 0; i < n; i++) par[i] = i;
  }
  int find(int x) { return x == par[x] ? x : (par[x] = find(par[x])); }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rnk[x] == rnk[y]) rnk[x]++;
    }
  }
  bool same(int x, int y) { return find(x) == find(y); }
};
const int MAX_N = 110000;
int n, m;
pair<int, int> a[MAX_N];
vector<int> g[MAX_N];
int ct[MAX_N];
bool used[MAX_N];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n, greater<pair<int, int> >());
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  UnionFind uf(n);
  double s = 0;
  for (int i = 0; i < n; i++) {
    int v = a[i].second;
    int w = a[i].first;
    used[v] = true;
    int t = 1;
    double z = 0;
    for (int u : g[v])
      if (used[u]) {
        int k = ct[uf.find(u)];
        if (!uf.same(u, v)) {
          uf.unite(u, v);
          z += t * k;
          t += k;
        }
      }
    s += 2.0 * w * z;
    ct[uf.find(v)] = t;
  }
  cout << fixed << setprecision(10) << s / ((double)n * (n - 1)) << endl;
}
