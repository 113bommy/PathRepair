#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class t, class u>
void chmax(t& first, u second) {
  if (first < second) first = second;
}
template <class t, class u>
void chmin(t& first, u second) {
  if (second < first) first = second;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using pi = pair<ll, ll>;
using vi = vc<ll>;
template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <class t>
ostream& operator<<(ostream& os, const vc<t>& v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
using uint = unsigned;
using ull = unsigned long long;
template <class t, size_t n>
ostream& operator<<(ostream& os, const array<t, n>& first) {
  return os << vc<t>(first.begin(), first.end());
}
template <ll i, class T>
void print_tuple(ostream&, const T&) {}
template <ll i, class T, class H, class... Args>
void print_tuple(ostream& os, const T& t) {
  if (i) os << ",";
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}
template <class... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << "{";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << "}";
}
template <class t>
void print(t x, ll suc = 1) {
  cout << x;
  if (suc == 1) cout << "\n";
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(ll n, ll off = 0) {
  vi v(n);
  for (ll i = ll(0); i < ll(n); i++) v[i] = read() + off;
  return v;
}
template <class T>
void print(const vector<T>& v, ll suc = 1) {
  for (ll i = ll(0); i < ll(v.size()); i++)
    print(v[i], i == ll(v.size()) - 1 ? suc : 2);
}
string readString() {
  string s;
  cin >> s;
  return s;
}
template <class T>
T sq(const T& t) {
  return t * t;
}
void yes(bool ex = true) {
  cout << "Yes"
       << "\n";
  if (ex) exit(0);
}
void no(bool ex = true) {
  cout << "No"
       << "\n";
  if (ex) exit(0);
}
void possible(bool ex = true) {
  cout << "Possible"
       << "\n";
  if (ex) exit(0);
}
void impossible(bool ex = true) {
  cout << "Impossible"
       << "\n";
  if (ex) exit(0);
}
constexpr ll ten(ll n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const ll inf = infLL;
ll topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
ll topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
ll botbit(signed first) { return first == 0 ? 32 : __builtin_ctz(first); }
ll botbit(ll first) { return first == 0 ? 64 : __builtin_ctzll(first); }
ll popcount(signed t) { return __builtin_popcount(t); }
ll popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(ll i) { return i && (i & -i) == i; }
ll mask(ll i) { return (ll(1) << i) - 1; }
bool inc(ll first, ll second, ll c) { return first <= second && second <= c; }
template <class t>
void mkuni(vc<t>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
ll rand_int(ll l, ll r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<ll>(l, r)(gen);
}
template <class t>
void myshuffle(vc<t>& first) {
  for (ll i = ll(0); i < ll(ll(first.size())); i++)
    swap(first[i], first[rand_int(0, i)]);
}
template <class t>
ll lwb(const vc<t>& v, const t& first) {
  return lower_bound(v.begin(), v.end(), first) - v.begin();
}
struct unionfind {
  vi p, s;
  ll c;
  unionfind(ll n) : p(n, -1), s(n, 1), c(n) {}
  ll find(ll first) {
    return p[first] == -1 ? first : (p[first] = find(p[first]));
  }
  bool unite(ll first, ll second) {
    first = find(first);
    second = find(second);
    if (first == second) return false;
    p[second] = first;
    s[first] += s[second];
    c--;
    return true;
  }
  bool same(ll first, ll second) { return find(first) == find(second); }
  ll sz(ll first) { return s[find(first)]; }
};
template <class E>
struct HLD {
  vvc<E> g;
  ll n, rt, cnt;
  vi sub, in, out, par, head, dep;
  ll dfs1(ll v, ll p, ll d) {
    par[v] = p;
    dep[v] = d;
    g[v].erase(remove(g[v].begin(), g[v].end(), p), g[v].end());
    for (auto& e : g[v]) {
      sub[v] += dfs1(e, v, d + 1);
      if (sub[g[v][0]] < sub[e]) swap(g[v][0], e);
    }
    return sub[v];
  }
  void dfs2(ll v, ll h) {
    in[v] = cnt++;
    head[v] = h;
    for (ll to : g[v]) dfs2(to, to == g[v][0] ? h : to);
    out[v] = cnt;
  }
  HLD() {}
  HLD(const vvc<E>& gg, ll rr)
      : g(gg),
        n(g.size()),
        rt(rr),
        cnt(0),
        sub(n, 1),
        in(n),
        out(n),
        par(n, -1),
        head(n),
        dep(n) {
    dfs1(rt, -1, 0);
    dfs2(rt, rt);
  }
  ll lca(ll first, ll second) {
    while (head[first] != head[second]) {
      if (dep[head[first]] > dep[head[second]]) swap(first, second);
      second = par[head[second]];
    }
    if (dep[first] > dep[second]) swap(first, second);
    return first;
  }
  ll len(ll first, ll second) {
    return dep[first] + dep[second] - dep[lca(first, second)] * 2;
  }
  bool asde(ll first, ll second) {
    return in[first] <= in[second] && out[second] <= out[first];
  }
  vi index;
  void init() { index.resize(n); }
  vc<pi> tree_compress(vi vs) {
    assert(index.size());
    auto comp = [&](ll x, ll y) { return in[x] < in[y]; };
    sort(vs.begin(), vs.end(), comp);
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    ll k = vs.size();
    for (ll i = ll(0); i < ll(k - 1); i++) {
      vs.push_back(lca(vs[i], vs[i + 1]));
    }
    sort(vs.begin(), vs.end(), comp);
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    k = vs.size();
    for (ll i = ll(0); i < ll(k); i++) index[vs[i]] = i;
    vc<pi> es;
    for (ll i = ll(1); i < ll(k); i++) {
      ll p = lca(vs[i - 1], vs[i]);
      es.emplace_back(vs[i], p);
    }
    return es;
  }
  ll c2(ll first) { return first * (first - 1); }
  ll c3(ll first) { return first * (first - 1) * (first - 2); }
  void slv() {
    vi cur(n);
    for (ll i = ll(1); i < ll(n); i++) {
      cur[par[i]] += c2(sub[i]);
      cur[i] += c2(n - sub[i]);
    }
    ll ans = n * c2(n - 1) - accumulate(cur.begin(), cur.end(), ll(0));
    unionfind uf(n);
    print(ans);
    ll q;
    cin >> q;
    for (ll _ = ll(0); _ < ll(q); _++) {
      ll u, v;
      cin >> u >> v;
      u--;
      v--;
      ll z = lca(u, v);
      vi ls;
      for (auto x : {u, v}) {
        while (x != -1 && dep[x] >= dep[z]) {
          x = uf.find(x);
          ls.push_back(x);
          x = par[x];
        }
      }
      mkuni(ls);
      sort(ls.begin(), ls.end(), [&](ll i, ll j) { return dep[i] < dep[j]; });
      if (ll(ls.size()) >= 2) {
        for (auto i : ls) {
          ll s = uf.sz(i);
          ans -= s * c2(n - s);
          ans += s * cur[i];
          ans -= c2(s) * 2 * (n - s);
          ans -= c3(s);
        }
        for (ll i = ll(1); i < ll(ll(ls.size())); i++) {
          cur[ls[0]] += cur[ls[i]];
          cur[ls[0]] -= c2(sub[ls[i]]);
          cur[ls[0]] -= c2(n - sub[ls[i]]);
          uf.unite(ls[0], ls[i]);
        }
        ll s = uf.sz(ls[0]);
        ans += s * c2(n - s);
        ans -= s * cur[ls[0]];
        ans += c2(s) * 2 * (n - s);
        ans += c3(s);
      }
      print(ans);
    }
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vvc<ll> t(n);
  for (ll _ = ll(0); _ < ll(n - 1); _++) {
    ll first, second;
    cin >> first >> second;
    first--;
    second--;
    t[first].push_back(second);
    t[second].push_back(first);
  }
  HLD<ll> h(t, 0);
  h.slv();
}
