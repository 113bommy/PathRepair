#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class t, class u>
bool chmax(t& first, u second) {
  if (first < second) {
    first = second;
    return true;
  } else
    return false;
}
template <class t, class u>
bool chmin(t& first, u second) {
  if (second < first) {
    first = second;
    return true;
  } else
    return false;
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
template <class t, class u>
void print(const pair<t, u>& p, ll suc = 1) {
  print(p.first, 2);
  print(p.second, suc);
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
using ld = long double;
const ll nmax = 200010;
vc<pi> t[nmax];
ll w[nmax];
pair<ld, ld> dfs(ll v, ll p, ll d) {
  ld val = sqrtl(d) * w[v];
  ld first = val, second = val * d;
  for (auto [to, cost] : t[v])
    if (p != to) {
      auto [x, y] = dfs(to, v, d + cost);
      first += x;
      second += y;
    }
  return make_pair(first, second);
}
bool rem[nmax];
ll tsize(ll v, ll p) {
  ll ret = 1;
  for (auto [to, cost] : t[v])
    if (to != p && !rem[to]) ret += tsize(to, v);
  return ret;
}
ll findc(ll v, ll p, ll s) {
  ll ret = 1, mx = 0;
  for (auto [to, cost] : t[v])
    if (to != p && !rem[to]) {
      ll f = findc(to, v, s);
      if (f <= 0)
        return f;
      else {
        ret += f;
        chmax(mx, f);
      }
    }
  chmax(mx, s - ret);
  if (mx * 2 <= s)
    return -v;
  else
    return ret;
}
void slv() {
  ll n;
  cin >> n;
  for (ll i = ll(0); i < ll(n); i++) cin >> w[i];
  for (ll _ = ll(0); _ < ll(n - 1); _++) {
    ll first, second, c;
    cin >> first >> second >> c;
    first--;
    second--;
    t[first].emplace_back(second, c);
    t[second].emplace_back(first, c);
  }
  ld ans = ld(1) / 0;
  ll cent = -1;
  ll root = 0;
  while (root != -1) {
    ll s = tsize(root, -1);
    root = -findc(root, -1, s);
    rem[root] = true;
    ld sum = 0;
    ld mx = -1;
    ll nx = -1;
    for (auto [to, cost] : t[root]) {
      auto [first, second] = dfs(to, root, cost);
      sum += second;
      if (!rem[to] && chmax(mx, first)) nx = to;
    }
    if (chmin(ans, sum)) cent = root;
    root = nx;
  }
  cout << cent + 1 << " " << ans << endl;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  slv();
}
