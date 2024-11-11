#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
using namespace std;
const int MOD = 1000000007;
const long long INF = 1e18;
const int N = 1e5 + 500;
int a[N], sz[N], p[N];
long long ans = 0;
struct edge {
  int u, v, cost;
  edge(){};
  edge(int a, int b, int c) : u(a), v(b), cost(c){};
};
edge ed[N];
bool cmp(edge a, edge b) { return a.cost > b.cost; }
int get(int u) { return p[u] = (p[u] == u ? u : get(p[u])); }
void unite(int u, int v) {
  u = get(u);
  v = get(v);
  if (sz[u] > sz[v]) swap(u, v);
  p[u] = v;
  sz[v] += sz[u];
}
void lamberson() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  lamberson();
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    ed[i] = edge(u, v, min(a[u], a[v]));
  }
  sort(ed + 1, ed + m + 1, cmp);
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    sz[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    if (get(ed[i].u) == get(ed[i].v)) continue;
    ans += (sz[get(ed[i].u)] * 1ll * sz[get(ed[i].v)]) * 1ll * ed[i].cost;
    unite(get(ed[i].u), get(ed[i].v));
  }
  long long q = (n * 1ll * n - n) / 2;
  long double qq = (ans + 0.0) / q;
  cout << qq;
  return 0;
}
