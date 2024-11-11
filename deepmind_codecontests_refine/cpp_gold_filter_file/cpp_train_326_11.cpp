#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
using ll = long long;
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using vi = vector<ll>;
using vll = vector<ll>;
struct Dinic {
  struct Edge {
    ll v, c, inv;
  };

 public:
  Dinic() : n(-1) {}
  void AddEdge(ll a, ll b, ll cap, ll bi_dir) {
    if (n < max(a, b)) {
      n = max(n, max(a, b));
      ResizeVectors();
    }
    e_orig[a].push_back(Edge{b, cap, ((ll)(e_orig[b]).size())});
    e_orig[b].push_back(Edge{a, bi_dir * cap, ((ll)(e_orig[a]).size()) - 1});
  }
  ll MaxFlow(ll s, ll t) {
    if (t > n || s > n) {
      n = max(s, t);
      ResizeVectors();
    }
    e = e_orig;
    ll result = 0;
    while (Bfs(s, t)) {
      fill_n(beg.begin(), n + 1, 0);
      result += Dfs(s, t, kInf);
    }
    return result;
  }
  vector<bool> MinCut(ll s, ll t) {
    assert(!Bfs(s, t));
    vector<bool> res(n + 1);
    for (ll i = (0); i <= (n); ++i) {
      res[i] = (dis[i] <= n);
    }
    return res;
  }
  vector<pair<ll, ll>> EdgeCut(ll s, ll t) {
    vector<bool> left_part = MinCut(s, t);
    vector<pair<ll, ll>> cut;
    for (ll v = (0); v <= (n); ++v) {
      for (auto edge : e_orig[v]) {
        if (edge.c != 0 && left_part[v] && !left_part[edge.v]) {
          cut.push_back({v, edge.v});
        }
      }
    }
    return cut;
  }

 private:
  ll n;
  vector<vector<Edge>> e_orig, e;
  vector<ll> dis, beg;
  bool Bfs(ll s, ll t) {
    fill_n(dis.begin(), n + 1, n + 1);
    dis[s] = 0;
    vector<ll> que;
    que.push_back(s);
    for (ll i = (0); i <= ((ll)(((ll)(que).size())) - 1); ++i) {
      ll v = que[i];
      for (auto edge : e[v]) {
        ll nei = edge.v;
        if (edge.c && dis[nei] > dis[v] + 1) {
          dis[nei] = dis[v] + 1;
          que.push_back(nei);
          if (nei == t) {
            return true;
          }
        }
      }
    }
    return false;
  }
  ll Dfs(ll v, ll t, ll min_cap) {
    ll result = 0;
    if (v == t || min_cap == 0) {
      return min_cap;
    }
    for (ll& i = beg[v]; i < ((ll)(e[v]).size()); i++) {
      ll nei = e[v][i].v, c = e[v][i].c;
      if (dis[nei] == dis[v] + 1 && c > 0) {
        ll flow_here = Dfs(nei, t, min(min_cap, c));
        result += flow_here;
        min_cap -= flow_here;
        e[v][i].c -= flow_here;
        e[nei][e[v][i].inv].c += flow_here;
      }
      if (min_cap == 0) {
        break;
      }
    }
    return result;
  }
  void ResizeVectors() {
    e_orig.resize(n + 2);
    beg.resize(n + 2);
    dis.resize(n + 2);
  }
  static const ll kInf = 1e18;
};
const ll MaxN = 2048;
const ll MaxItems = 5e5;
ll n, m;
vi adj[MaxN];
ll s, b, k, h;
ll dist[MaxN][MaxN];
vector<pii> at_vert[MaxN];
ll sp_loc[MaxItems], sp_atk[MaxItems], sp_fuel[MaxItems], sp_price[MaxItems];
ll bs_loc[MaxItems], bs_def[MaxItems], bs_gold[MaxItems];
vi dep_adj[MaxItems];
bool any_dep[MaxItems];
ll dep_idx[MaxItems];
int32_t main() {
  scanf("%lld%lld", &n, &m);
  for (ll i = 0; i <= n; ++i) {
    for (ll j = 0; j <= n; ++j) {
      dist[i][j] = 2e9;
    }
    dist[i][i] = 0;
  }
  for (ll i = 0; i < m; ++i) {
    ll u, v;
    scanf("%lld%lld", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    if (u != v) {
      dist[u][v] = dist[v][u] = 1;
    }
  }
  for (ll k = 1; k <= n; ++k) {
    for (ll i = 1; i <= n; ++i) {
      for (ll j = 1; j <= n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  scanf("%lld%lld%lld", &s, &b, &k);
  for (ll i = 0; i < s; ++i) {
    scanf("%lld%lld%lld%lld", &sp_loc[i], &sp_atk[i], &sp_fuel[i],
          &sp_price[i]);
  }
  for (ll i = 0; i < b; ++i) {
    scanf("%lld%lld%lld", &bs_loc[i], &bs_def[i], &bs_gold[i]);
    at_vert[bs_loc[i]].emplace_back(bs_def[i], bs_gold[i]);
  }
  for (ll v = 1; v <= n; ++v) {
    auto& X = at_vert[v];
    sort(X.begin(), X.end());
    const ll sz = X.size();
    ll cur_max = -1;
    ll ptr = 0;
    for (ll i = 0; i < sz; ++i) {
      if (X[i].second <= cur_max) {
        continue;
      }
      X[ptr++] = X[i];
      cur_max = X[i].second;
    }
    X.resize(ptr);
    debug() << " ["
            << "v"
               ": "
            << (v) << "] "
            << " ["
            << "X"
               ": "
            << (X) << "] ";
  }
  const ll kSmallInf = 2e16;
  const ll kLargeInf = 2e16;
  vll sp_best(s, -kLargeInf);
  for (ll i = 0; i < s; ++i) {
    for (ll v = 1; v <= n; ++v) {
      if (sp_fuel[i] < dist[sp_loc[i]][v]) {
        continue;
      }
      const ll atk = sp_atk[i];
      auto iter = lower_bound(at_vert[v].begin(), at_vert[v].end(),
                              pii(atk, kSmallInf));
      if (iter == at_vert[v].begin()) {
        continue;
      } else {
        ll bnd = prev(iter)->second;
        sp_best[i] = max(sp_best[i], (ll)bnd - sp_price[i]);
      }
    }
    debug() << " ["
            << "i"
               ": "
            << (i) << "] "
            << " ["
            << "sp_best[i]"
               ": "
            << (sp_best[i]) << "] ";
  }
  for (ll i = 0; i < k; ++i) {
    ll u, v;
    scanf("%lld%lld", &u, &v);
    --u;
    --v;
    any_dep[u] = any_dep[v] = true;
    dep_adj[u].push_back(v);
  }
  ll ans = 0;
  ll curidx = 0;
  for (ll i = 0; i < s; ++i) {
    if (!any_dep[i] && sp_best[i] >= 0) {
      ans += sp_best[i];
    }
    dep_idx[i] = curidx++;
  }
  Dinic dinic;
  const ll source = curidx;
  const ll sink = source + 1;
  debug() << " ["
          << "source"
             ": "
          << (source) << "] "
          << " ["
          << "sink"
             ": "
          << (sink) << "] ";
  for (ll i = 0; i < s; ++i) {
    if (!any_dep[i]) {
      continue;
    }
    if (sp_best[i] >= 0) {
      dinic.AddEdge(source, dep_idx[i], sp_best[i], 0);
      ans += sp_best[i];
    } else {
      dinic.AddEdge(dep_idx[i], sink, -sp_best[i], 0);
    }
    for (ll j : dep_adj[i]) {
      dinic.AddEdge(dep_idx[i], dep_idx[j], kLargeInf, 0);
    }
  }
  const ll flow = dinic.MaxFlow(source, sink);
  ans -= flow;
  assert(ans >= 0);
  printf("%lld\n", ans);
}
