#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 50;
long long par[maxn];
long long high[maxn];
long long cost[maxn];
long long n, m;
long long cnte;
struct edge {
  long long u, v, cost;
};
bool cmp(const edge& e1, const edge& e2) { return e1.cost < e2.cost; }
edge es[2 * maxn];
void init() {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    high[i] = 0;
  }
}
int find(long long x) { return par[x] == x ? x : par[x] = find(par[x]); }
void unite(long long x, long long y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (high[x] < high[y])
    par[x] = y;
  else {
    par[y] = x;
    if (high[x] == high[y]) high[x]++;
  }
}
bool same(long long x, long long y) { return find(x) == find(y); }
void kruskal() {
  sort(es, es + cnte, cmp);
  init();
  long long ans = 0;
  for (int i = 0; i < cnte; i++) {
    edge e = es[i];
    if (!same(e.u, e.v)) {
      unite(e.u, e.v);
      ans += e.cost;
    }
  }
  cout << ans << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  cnte = 0;
  for (int i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    es[cnte++] = {u - 1, v - 1, w};
  }
  int mini = 0;
  for (int i = 0; i < n; i++) {
    if (cost[i] < cost[mini]) {
      mini = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (mini == i) continue;
    es[cnte++] = {i, mini, cost[i] + cost[mini]};
  }
  kruskal();
  return 0;
}
