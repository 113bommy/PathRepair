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
pi readpi(ll off = 0) {
  ll first, second;
  cin >> first >> second;
  return pi(first + off, second + off);
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
vvc<ll> readGraph(ll n, ll m) {
  vvc<ll> g(n);
  for (ll i = ll(0); i < ll(m); i++) {
    ll first, second;
    cin >> first >> second;
    first--;
    second--;
    g[first].push_back(second);
    g[second].push_back(first);
  }
  return g;
}
vvc<ll> readTree(ll n) { return readGraph(n, n - 1); }
struct modinfo {
  uint mod, root;
};
template <modinfo const& ref>
struct modular {
  static constexpr uint const& mod = ref.mod;
  static modular root() { return modular(ref.root); }
  uint v;
  modular(ll vv = 0) { s(vv % mod + mod); }
  modular& s(uint vv) {
    v = vv < mod ? vv : vv - mod;
    return *this;
  }
  modular operator-() const { return modular() - *this; }
  modular& operator+=(const modular& rhs) { return s(v + rhs.v); }
  modular& operator-=(const modular& rhs) { return s(v + mod - rhs.v); }
  modular& operator*=(const modular& rhs) {
    v = ull(v) * rhs.v % mod;
    return *this;
  }
  modular& operator/=(const modular& rhs) { return *this *= rhs.inv(); }
  modular operator+(const modular& rhs) const { return modular(*this) += rhs; }
  modular operator-(const modular& rhs) const { return modular(*this) -= rhs; }
  modular operator*(const modular& rhs) const { return modular(*this) *= rhs; }
  modular operator/(const modular& rhs) const { return modular(*this) /= rhs; }
  modular pow(ll n) const {
    modular res(1), x(*this);
    while (n) {
      if (n & 1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }
  modular inv() const { return pow(mod - 2); }
  friend modular operator+(ll x, const modular& y) { return modular(x) + y; }
  friend modular operator-(ll x, const modular& y) { return modular(x) - y; }
  friend modular operator*(ll x, const modular& y) { return modular(x) * y; }
  friend modular operator/(ll x, const modular& y) { return modular(x) / y; }
  friend ostream& operator<<(ostream& os, const modular& m) {
    return os << m.v;
  }
  friend istream& operator>>(istream& is, modular& m) {
    ll x;
    is >> x;
    m = modular(x);
    return is;
  }
  bool operator<(const modular& r) const { return v < r.v; }
  bool operator==(const modular& r) const { return v == r.v; }
  bool operator!=(const modular& r) const { return v != r.v; }
  explicit operator bool() const { return v; }
};
extern constexpr modinfo base{1000000007, 0};
using mint = modular<base>;
const ll vmax = (1 << 21) + 10;
mint fact[vmax], finv[vmax], invs[vmax];
void initfact() {
  fact[0] = 1;
  for (ll i = ll(1); i < ll(vmax); i++) {
    fact[i] = fact[i - 1] * i;
  }
  finv[vmax - 1] = fact[vmax - 1].inv();
  for (ll i = vmax - 2; i >= 0; i--) {
    finv[i] = finv[i + 1] * (i + 1);
  }
  for (ll i = vmax - 1; i >= 1; i--) {
    invs[i] = finv[i] * fact[i - 1];
  }
}
mint choose(ll n, ll k) { return fact[n] * finv[n - k] * finv[k]; }
mint binom(ll first, ll second) {
  return fact[first + second] * finv[first] * finv[second];
}
mint catalan(ll n) {
  return binom(n, n) - (n - 1 >= 0 ? binom(n - 1, n + 1) : 0);
}
struct Candy {
  ll x, y, c;
  void readinit() {
    cin >> x >> y >> c;
    c--;
  }
};
bool cmpX(const Candy& first, const Candy& second) {
  return first.x < second.x;
}
bool cmpY(const Candy& first, const Candy& second) {
  return first.y > second.y;
}
struct lower_left_region {
  struct P {
    ll x, y;
    bool operator<(const P& rhs) const {
      return x != rhs.x ? x < rhs.x : y > rhs.y;
    }
  };
  set<P> s;
  ll area = 0;
  void add(ll x, ll y) {
    auto itr = s.lower_bound(P{x, y});
    P l{0, 0}, r{0, 0};
    if (itr != s.end()) {
      if (y <= itr->y) return;
      r = *itr;
    }
    P pre = r;
    while (itr != s.begin()) {
      auto p = prev(itr);
      area += p->x * pre.y;
      if (p->y > y) {
        l = *p;
        break;
      }
      area -= p->x * p->y;
      pre = *p;
      s.erase(p);
    }
    s.insert(itr, P{x, y});
    area += x * y;
    area -= l.x * y;
    area -= x * r.y;
  }
};
struct Query {
  ll t, x, y;
};
mint sub(ll lf, vc<Candy> ps, ll K, ll L) {
  sort(ps.begin(), ps.end(), cmpY);
  vc<Query> qs;
  vvc<pi> pos(K, vc<pi>{pi(-1, L)});
  for (const auto& p : ps) {
    auto& cur = pos[p.c];
    qs.push_back({p.y + 1, L, cur.back().second});
    ll f = lwb(cur, pi(p.x, -1));
    for (ll i = ll(f); i < ll(ll(cur.size())); i++) {
      qs.push_back({p.y + 1, cur[i].first, cur[i - 1].second});
    }
    cur.resize(f);
    cur.emplace_back(p.x, p.y);
  }
  lower_left_region llr;
  for (ll c = ll(0); c < ll(K); c++) {
    for (ll i = ll(0); i < ll(ll(pos[c].size())); i++) {
      ll nx = i + 1 < ll(pos[c].size()) ? pos[c][i + 1].first : L;
      llr.add(nx - lf, pos[c][i].second);
    }
  }
  reverse(qs.begin(), qs.end());
  mint ans = 0;
  ll pre = 0;
  for (const auto& q : qs) {
    mint tmp = ((L - lf) * L - llr.area);
    ans += mint(q.t - pre) * tmp;
    llr.add(q.x - lf, q.y);
    pre = q.t;
  }
  return ans;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  ll n, k, l;
  cin >> n >> k >> l;
  vc<Candy> ps(n);
  for (ll i = ll(0); i < ll(n); i++) {
    ps[i].readinit();
  }
  sort(ps.begin(), ps.end(), cmpX);
  ll pre = -1;
  mint ans = 0;
  for (ll i = ll(0); i < ll(n); i++) {
    if (pre < ps[i].x) {
      ans += sub(ps[i].x, vc<Candy>(ps.begin() + i, ps.end()), k, l) *
             (ps[i].x - pre);
      pre = ps[i].x;
    }
  }
  print(ans);
}
