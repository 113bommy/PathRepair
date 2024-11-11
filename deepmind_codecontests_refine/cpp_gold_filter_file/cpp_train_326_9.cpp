#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using ld = long double;
const ll inf = (ll)1e18 + 100;
ll n, m;
ll d[100][100];
ll s, b, k;
struct ship {
  ll x, a, f, p;
} ss[100000];
struct base {
  ll x, d, g;
} bb[100000];
struct maxflow {
  struct edge {
    ll to, c, f;
  };
  vector<edge> e;
  vector<vi> g;
  ll N, S, T;
  vi pt, d;
  ll A;
  bool bfs() {
    fill_n(d.begin(), N, inf);
    d[S] = 0;
    queue<ll> q;
    q.push(S);
    while (!q.empty()) {
      ll v = q.front();
      q.pop();
      for (ll i : g[v]) {
        edge& ee = e[i];
        if (ee.c - ee.f >= A && d[ee.to] == inf) {
          d[ee.to] = d[v] + 1;
          q.push(ee.to);
        }
      }
    }
    return (d[T] != inf);
  }
  ll dfs(ll v, ll cmin) {
    if (v == T) {
      return cmin;
    }
    for (; pt[v] < (ll)((g[v]).size()); pt[v]++) {
      ll i = g[v][pt[v]];
      edge& ee = e[i];
      if (ee.c - ee.f >= A && d[ee.to] == d[v] + 1) {
        ll f = dfs(ee.to, min(cmin, ee.c - ee.f));
        if (f > 0) {
          ee.f += f;
          e[i ^ 1].f -= f;
          return f;
        }
      }
    }
    return 0;
  }
  void dinic() {
    d.resize(N);
    pt.resize(N);
    ll mf = 0;
    for (A = inf; A; A >>= 1) {
      while (bfs()) {
        fill_n(pt.begin(), N, 0);
        while (dfs(S, inf))
          ;
      }
    }
  }
  void addEdge(ll u, ll v, ll c) {
    static ll i = 0;
    e.push_back({v, c, 0});
    e.push_back({u, 0, 0});
    g[u].push_back(i);
    g[v].push_back(i ^ 1);
    i += 2;
  }
  void zhfs(ll v, vector<bool>& was) {
    was[v] = true;
    for (ll i : g[v]) {
      edge& ee = e[i];
      if (ee.c - ee.f > 0 && !was[ee.to]) {
        zhfs(ee.to, was);
      }
    }
  }
};
vi g1[100000];
vector<pii> e;
bool ban[100000];
ll w[100000];
void dfs(ll v) {
  ban[v] = true;
  for (ll to : g1[v])
    if (!ban[to]) dfs(to);
}
vector<pii> pl[100];
vi pm[100];
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (ll i = 0; i < n; i++)
    for (ll j = 0; j < n; j++)
      if (i != j) d[i][j] = inf;
  for (ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    --u;
    --v;
    d[u][v] = d[v][u] = 1;
  }
  for (ll k = 0; k < n; k++)
    for (ll i = 0; i < n; i++)
      for (ll j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  cin >> s >> b >> k;
  for (ll i = 0; i < s; i++)
    cin >> ss[i].x >> ss[i].a >> ss[i].f >> ss[i].p, --ss[i].x;
  for (ll i = 0; i < b; i++)
    cin >> bb[i].x >> bb[i].d >> bb[i].g, --bb[i].x,
        pl[bb[i].x].push_back({bb[i].d, bb[i].g});
  for (ll i = 0; i < n; i++) {
    if (pl[i].empty()) continue;
    sort((pl[i]).begin(), (pl[i]).end());
    pm[i].resize((ll)((pl[i]).size()));
    pm[i][0] = pl[i][0].second;
    for (ll j = 1; j < (ll)((pm[i]).size()); j++) {
      pm[i][j] = max(pm[i][j - 1], pl[i][j].second);
    }
  }
  vi broken;
  maxflow grape;
  grape.N = s + 2;
  grape.S = grape.N - 2;
  grape.T = grape.N - 1;
  grape.g.resize(grape.N);
  vi ord(s);
  iota((ord).begin(), (ord).end(), 0);
  sort((ord).begin(), (ord).end(),
       [](ll i, ll j) { return ss[i].a < ss[j].a; });
  vi pt(n, -1);
  for (ll i : ord) {
    ll hi = -1;
    for (ll p = 0; p < n; p++)
      if (ss[i].f >= d[ss[i].x][p]) {
        while (pt[p] + 1 < (ll)((pl[p]).size()) &&
               ss[i].a >= pl[p][pt[p] + 1].first)
          pt[p]++;
        if (pt[p] != -1) hi = max(hi, pm[p][pt[p]]);
      }
    if (hi == -1)
      broken.push_back(i);
    else {
      hi -= ss[i].p;
      w[i] = hi;
    }
  }
  for (ll i = 0; i < k; i++) {
    ll u, v;
    cin >> u >> v;
    --u;
    --v;
    g1[v].push_back(u);
    e.push_back({u, v});
  }
  for (ll u : broken)
    if (!ban[u]) dfs(u);
  for (ll i = 0; i < s; i++)
    if (!ban[i]) {
      ll hi = w[i];
      if (hi < 0)
        grape.addEdge(i, grape.T, -hi);
      else if (hi > 0)
        grape.addEdge(grape.S, i, hi);
    }
  for (pii r : e) {
    ll u = r.first, v = r.second;
    if (!ban[u] && !ban[v]) grape.addEdge(u, v, inf);
  }
  grape.dinic();
  vector<bool> was(grape.N, false);
  grape.zhfs(grape.S, was);
  ll ans = 0;
  for (ll u = 0; u < s; u++) {
    if (was[u]) {
      ans += w[u];
    }
  }
  cout << ans;
}
