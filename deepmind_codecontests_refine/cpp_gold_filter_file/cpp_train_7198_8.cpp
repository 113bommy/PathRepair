#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
using ll = long long;
using ld = long double;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<double, double>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <typename A, typename B>
pair<A, B>& operator++(pair<A, B>& a) {
  ++a.second;
  ++a.first;
  return a;
}
template <typename A, typename B>
pair<A, B>& operator--(pair<A, B>& a) {
  --a.first;
  --a.second;
  return a;
}
template <typename A>
vector<A>& operator++(vector<A>& a) {
  for (auto it = a.begin(); it != a.end(); ++it) ++*it;
  return a;
}
template <typename A>
vector<A>& operator--(vector<A>& a) {
  for (auto it = a.begin(); it != a.end(); ++it) --*it;
  return a;
}
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
const int di8[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          dj8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const ld PI = acos((ld)-1);
const ll INF = 1e18;
const double eps = 1e-11;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }
using ul = unsigned long long;
ul modMul(ul a, ul b, const ul mod) {
  ll ret = a * b - mod * (ul)((ld)a * b / mod);
  return ret + ((ret < 0) - (ret >= (ll)mod)) * mod;
}
ul modPow(ul a, ul b, const ul mod) {
  if (b == 0) return 1;
  ul res = modPow(a, b / 2, mod);
  res = modMul(res, res, mod);
  return b & 1 ? modMul(res, a, mod) : res;
}
bool pow2(int i) { return i && (i & -i) == i; }
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
ll half(ll x) { return fdiv(x, 2); }
bool inc(ll a, ll b, ll c) { return a <= b && b <= c; }
template <class t>
int lwb(const vector<t>& v, const t& a) {
  return lower_bound((v).begin(), (v).end(), a) - v.begin();
}
template <class T>
bool chmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool chmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
void TIME() {}
template <class T>
void remDup(vector<T>& v) {
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), end(v));
}
template <class T, class U>
void remAll(vector<T>& v, U a) {
  v.erase(remove((v).begin(), (v).end(), a), v.end());
}
template <class T, class U>
T fstTrue(T lo, T hi, U f) {
  while (lo < hi) {
    T mid = half(lo + hi);
    f(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class U>
T lstTrue(T lo, T hi, U f) {
  while (lo < hi) {
    T mid = half(lo + hi + 1);
    f(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
template <typename I>
struct _reversed_struct {
  I& v_;
  explicit _reversed_struct(I& v) : v_{v} {}
  typename I::reverse_iterator begin() const { return v_.rbegin(); }
  typename I::reverse_iterator end() const { return v_.rend(); }
};
template <typename I>
_reversed_struct<I> reversed(I& v) {
  return _reversed_struct<I>(v);
}
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return to_string((int)b); }
string to_string(const char* s) { return (string)s; }
string to_string(string s) { return s; }
template <class T>
string to_string(complex<T> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}
string to_string(vb v) {
  string res = "{";
  for (int i = (0); i < (((int)(v).size())); ++i) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t SZ>
string to_string(bitset<SZ> b) {
  string res = "";
  for (int i = (0); i < (((int)(b).size())); ++i) res += char('0' + b[i]);
  return res;
}
template <class T, class U>
string to_string(pair<T, U> p);
template <class T>
string to_string(T v) {
  bool fst = 1;
  string res = "";
  for (const auto& x : v) {
    if (!fst) res += " ";
    fst = 0;
    res += to_string(x);
  }
  return res;
}
template <class T, class U>
string to_string(pair<T, U> p) {
  return to_string(p.first) + " " + to_string(p.second);
}
template <class T>
void re(complex<T>& c);
template <class T, class U>
void re(pair<T, U>& p);
template <class T>
void re(vector<T>& v);
template <class T>
void rv(int n, vector<T>& x) {
  x.resize(n);
  re(x);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(double& d) {
  string t;
  re(t);
  d = stod(t);
}
void re(ld& d) {
  string t;
  re(t);
  d = stold(t);
}
template <class T, class... U>
void re(T& t, U&... u) {
  re(t);
  re(u...);
}
template <class T>
void re(complex<T>& c) {
  T a, b;
  re(a, b);
  c = {a, b};
}
template <class T, class U>
void re(pair<T, U>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& x) {
  for (auto& a : x) re(a);
}
template <class T, size_t SZ>
void re(array<T, SZ>& x) {
  for (auto& a : x) re(a);
}
template <class T>
void pr(T x) {
  cout << to_string(x);
}
template <class T, class... U>
void pr(const T& t, const U&... u) {
  pr(t);
  pr(u...);
}
void ps() { pr("\n"); }
template <class T, class... U>
void ps(const T& t, const U&... u) {
  pr(t);
  if (sizeof...(u)) pr(" ");
  ps(u...);
}
struct chash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
  template <typename L, typename R>
  size_t operator()(pair<L, R> const& Y) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
  }
};
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using mpq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using ms = multiset<T>;
template <class T, class U>
using um = unordered_map<T, U, chash>;
template <class T>
using us = unordered_set<T, chash>;
template <class T>
using PR = pair<T, T>;
template <int MOD, int RT>
struct mint {
  static const int mod = MOD;
  static constexpr mint rt() { return RT; }
  int v;
  explicit operator int() const { return v; }
  mint() { v = 0; }
  mint(ll _v) {
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mint& a, const mint& b) { return a.v == b.v; }
  friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
  friend bool operator<(const mint& a, const mint& b) { return a.v < b.v; }
  friend void re(mint& a) {
    ll x;
    re(x);
    a = mint(x);
  }
  friend string to_string(mint a) { return to_string(a.v); }
  mint& operator+=(const mint& m) {
    if ((v += m.v) >= MOD) v -= MOD;
    return *this;
  }
  mint& operator-=(const mint& m) {
    if ((v -= m.v) < 0) v += MOD;
    return *this;
  }
  mint& operator*=(const mint& m) {
    v = (ll)v * m.v % MOD;
    return *this;
  }
  mint& operator/=(const mint& m) { return (*this) *= inv(m); }
  friend mint pow(mint a, ll p) {
    mint ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mint inv(const mint& a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  mint operator-() const { return mint(-v); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  friend mint operator+(mint a, const mint& b) { return a += b; }
  friend mint operator-(mint a, const mint& b) { return a -= b; }
  friend mint operator*(mint a, const mint& b) { return a *= b; }
  friend mint operator/(mint a, const mint& b) { return a /= b; }
};
typedef mint<MOD, 5> mi;
vi invs, fac, ifac;
void genFac(int SZ) {
  invs.resize(SZ), fac.resize(SZ), ifac.resize(SZ);
  invs[1] = fac[0] = ifac[0] = 1;
  for (int i = (2); i < (SZ); ++i)
    invs[i] = MOD - (ll)MOD / i * invs[MOD % i] % MOD;
  for (int i = (1); i < (SZ); ++i) {
    fac[i] = (ll)fac[i - 1] * i % MOD;
    ifac[i] = (ll)ifac[i - 1] * invs[i] % MOD;
  }
}
mi comb(int a, int b) {
  if (a < b || b < 0) return 0;
  return (ll)fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll ncr(ll a, ll b) {
  if (a < b) return 0;
  ll f = 1;
  for (int i = (1); i < (b + 1); ++i) {
    f *= (a + 1 - i);
    f /= i;
  }
  return f;
}
void DBG() { cerr << "]" << endl; }
template <class T, class... U>
void DBG(const T& t, const U&... u) {
  cerr << to_string(t);
  if (sizeof...(u)) cerr << ", ";
  DBG(u...);
}
V<vi> reg(int n, int m) {
  V<vi> g(n);
  for (int i = (0); i < (m); ++i) {
    int a, b;
    re(a, b);
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  return g;
}
V<vpi> rew(int n, int m) {
  V<vpi> g(n);
  for (int i = (0); i < (m); ++i) {
    int a, b, w;
    re(a, b, w);
    a--;
    b--;
    g[a].emplace_back(b, w);
    g[b].emplace_back(a, w);
  }
  return g;
}
void setPrec() { cout << fixed << setprecision(15); }
void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str s = "") {
  unsyncIO();
  setPrec();
  if (((int)(s).size())) {
    setIn(s + ".in");
    setOut(s + ".out");
  }
}
const int N = 2e5 + 5;
void solve(int tc) {
  ll n;
  re(n);
  vpl v(n);
  re(v);
  ll x = 0;
  sort((v).begin(), (v).end(),
       [](pl& a, pl& b) { return a.first - a.second > b.first - b.second; });
  for (int i = (0); i < (n); ++i)
    x += (v[i].first * i) + (v[i].second * (n - i - 1));
  ps(x);
}
int main() {
  setIO();
  int T = 1;
  for (int _ = (1); _ < (T + 1); ++_) solve(_);
}
