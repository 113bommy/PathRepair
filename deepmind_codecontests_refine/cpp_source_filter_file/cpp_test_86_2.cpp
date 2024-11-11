#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
template <class T>
void print_offset(const vector<T>& v, ll off, ll suc = 1) {
  for (ll i = ll(0); i < ll(v.size()); i++)
    print(v[i] + off, i == ll(v.size()) - 1 ? suc : 2);
}
template <class T, size_t N>
void print(const array<T, N>& v, ll suc = 1) {
  for (ll i = ll(0); i < ll(N); i++) print(v[i], i == ll(N) - 1 ? suc : 2);
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
    if (n < 0) return inv().pow(-n);
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
extern constexpr modinfo base{998244353, 3};
using mint = modular<base>;
const ll kmax = ten(7) + 10;
mint p2[kmax], i2[kmax], w[kmax];
mint j2[kmax], z[kmax];
ll cnt[kmax];
mint sub(ll n, ll m) {
  mint num = 0, den = 1;
  mint pn = mint(2).pow(n), nmd = 1, dd = 1;
  ll s = min(n, m);
  j2[s] = pn.inv();
  for (ll i = ll(s) - 1; i >= ll(0); i--) j2[i] = j2[i + 1] * 2;
  cnt[0] = 0;
  z[0] = 1;
  for (ll i = ll(0); i < ll(s); i++) {
    if (j2[i + 1] == 1) {
      cnt[i + 1] = cnt[i + 1];
      z[i + 1] = 1;
    } else {
      cnt[i + 1] = cnt[i];
      z[i + 1] = z[i] * (1 - j2[i + 1]);
    }
  }
  for (ll d = ll(0); d < ll(min(n, m) + 1); d++) {
    if (cnt[s - d] == cnt[s]) {
      mint x = nmd * z[s] * w[m];
      mint y = dd * z[s - d] * w[m - d] * w[d];
      tie(num, den) = make_pair(num * y + x * den, den * y);
    }
    nmd *= pn * p2[m];
    dd *= sq(p2[d]);
  }
  return num / den;
}
void slv() {
  ll n, k, unko;
  cin >> n >> k >> unko;
  if (unko == 0) {
    if (n > k) {
      print(0);
    } else {
      mint ans = 1;
      for (ll i = ll(0); i < ll(n); i++) ans *= p2[k] - p2[i];
      print(ans);
    }
  } else {
    mint fsum = sub(n, k);
    mint ans = (p2[k].pow(n) * p2[k] - fsum) / (p2[k] - 1);
    print(ans);
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  p2[0] = 1;
  for (ll i = ll(1); i < ll(kmax); i++) p2[i] = p2[i - 1] * 2;
  i2[kmax - 1] = p2[kmax - 1].inv();
  for (ll i = ll(kmax) - 1; i >= ll(1); i--) i2[i - 1] = i2[i] * 2;
  w[0] = 1;
  for (ll i = ll(1); i < ll(kmax); i++) w[i] = w[i - 1] * (1 - i2[i]);
  ll t;
  cin >> t;
  for (ll _ = ll(0); _ < ll(t); _++) slv();
}
