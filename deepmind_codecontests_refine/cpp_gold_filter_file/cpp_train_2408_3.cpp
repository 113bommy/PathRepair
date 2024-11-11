#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int par[MAXN];
int get(int u) {
  if (par[u] == u) return u;
  return par[u] = get(par[u]);
}
bool unite(int u, int v) {
  u = get(u);
  v = get(v);
  if (u == v) return false;
  if (rand() % 2) swap(u, v);
  par[u] = v;
  return true;
}
long long a[MAXN];
struct edge {
  int from, to;
  long long weg;
  edge() {}
  edge(int _from, int _to, long long _weg) {
    from = _from;
    to = _to;
    weg = _weg;
  }
  bool operator<(const edge &e) const { return weg < e.weg; }
};
vector<edge> edges;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  long long mn = (long long)1e15;
  int idxmn = -1;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] < mn) {
      mn = a[i];
      idxmn = i;
    }
  }
  for (int i = 1; i <= n; i++) par[i] = i;
  for (int i = 1; i <= n; i++) {
    if (i - idxmn) edges.emplace_back(i, idxmn, a[i] + a[idxmn]);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    long long w;
    scanf("%d %d %lld", &u, &v, &w);
    edges.emplace_back(u, v, w);
  }
  sort(edges.begin(), edges.end());
  long long ans = 0;
  for (auto &e : edges) {
    if (unite(e.from, e.to)) ans += e.weg;
  }
  printf("%lld\n", ans);
  return 0;
}
