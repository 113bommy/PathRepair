#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, mod = 1e9 + 7;
vector<pair<int, int> > g[N];
long long dis[N];
int par[N], sz[N];
set<pair<long long, int> > s;
void dijekstra() {
  while (s.size()) {
    auto x = *s.begin();
    s.erase(s.begin());
    long long d = x.first;
    int v = x.second;
    for (auto xx : g[v]) {
      int u = xx.first, w = xx.second;
      if (dis[u] > d + w) {
        par[u] = par[v];
        s.erase({dis[u], u});
        dis[u] = d + w;
        s.insert({dis[u], u});
      }
    }
  }
}
int pr(int x) {
  if (par[x] == x) return x;
  return par[x] = pr(par[x]);
}
long long l[N], r[N], mid[N];
int a[N], b[N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, q;
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--;
    v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  for (int i = 0; i < n; i++) dis[i] = 1ll * mod * mod;
  for (int i = 0; i < k; i++) {
    s.insert({0, i});
    dis[i] = 0;
    par[i] = i;
  }
  dijekstra();
  vector<pair<long long, pair<int, int> > > e;
  for (int i = 0; i < n; i++)
    for (auto x : g[i]) {
      int v = x.first, w = x.second;
      if (par[i] < par[v]) e.push_back({w + dis[i] + dis[v], {par[i], par[v]}});
    }
  sort(e.begin(), e.end());
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &a[i], &b[i]);
    a[i]--;
    b[i]--;
    l[i] = 0, r[i] = 1ll * k * mod;
  }
  bool go = true;
  while (go) {
    go = false;
    vector<pair<long long, int> > vec;
    for (int i = 0; i < q; i++) {
      if (r[i] - l[i] > 1) {
        mid[i] = (l[i] + r[i]) / 2;
        vec.push_back({mid[i], i});
        go = true;
      }
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < k; i++) par[i] = i, sz[i] = 1;
    int cur = 0;
    for (auto x : vec) {
      while (cur < e.size() && e[cur].first <= x.first) {
        int u = e[cur].second.first, v = e[cur].second.second;
        u = pr(u);
        v = pr(v);
        if (sz[u] > sz[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
        cur++;
      }
      int id = x.second;
      if (pr(a[id]) == pr(b[id]))
        r[id] = mid[id];
      else
        l[id] = mid[id];
    }
  }
  for (int i = 0; i < q; i++) printf("%lld\n", r[i]);
  return 0;
}
