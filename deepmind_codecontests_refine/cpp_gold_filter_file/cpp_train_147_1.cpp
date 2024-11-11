#include <bits/stdc++.h>
using namespace std;
long long mo(long long a) { return a % (long long)(1e9 + 7); }
long long po(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res % p;
}
vector<vector<long long>> g;
long long n, m, q;
struct dsu {
  int n;
  vector<long long> a, rank, dia;
  void init(long long si) {
    n = si;
    a.resize(n);
    rank.resize(n);
    dia.resize(n);
    for (long long i = 0; i < n; i++) {
      rank[i] = 1;
      a[i] = i;
      dia[i] = 0;
    }
  }
  long long get(long long i) { return a[i] = ((i == a[i]) ? i : get(a[i])); }
  void unio(long long i, long long j) {
    long long x = get(i), y = get(j);
    if (x == y) return;
    if (rank[x] == rank[y]) rank[x]++;
    if (rank[y] > rank[x]) swap(x, y);
    a[y] = x;
    dia[x] = max({dia[x], dia[y], (dia[x] + 1) / 2 + (dia[y] + 1) / 2 + 1});
  }
};
vector<long long> vis, dist, vis2;
long long root;
dsu ds;
void dfs(long long par, long long is) {
  vis[par] = 1;
  if (dist[root] < dist[par]) root = par;
  for (long long e : g[par]) {
    if (!vis[e]) {
      ds.unio(par, e);
      dist[e] = dist[par] + 1;
      dfs(e, is);
    }
  }
  if (is) vis[par] = 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> q;
  g.assign(n, {});
  vis.assign(n, 0);
  dist.assign(n, 0);
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  ds.init(n);
  for (long long i = 0; i < n; i++) {
    if (!vis[i]) {
      root = i;
      dist[root] = 0;
      dfs(i, 1);
      dist[root] = 0;
      dfs(root, 0);
      ds.dia[ds.get(i)] = dist[root];
    }
  }
  while (q--) {
    long long op;
    cin >> op;
    if (op == 1) {
      long long x;
      cin >> x;
      x--;
      cout << ds.dia[ds.get(x)] << "\n";
    } else {
      long long x, y;
      cin >> x >> y;
      x--;
      y--;
      ds.unio(x, y);
    }
  }
  return 0;
}
