#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
using mat = vector<vector<T> >;
template <int mod>
struct modint {
  int x;
  modint() : x(0) {}
  modint(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  modint &operator+=(const modint &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  modint &operator-=(const modint &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  modint &operator*=(const modint &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  modint &operator/=(const modint &p) {
    *this *= p.inverse();
    return *this;
  }
  modint operator-() const { return modint(-x); }
  modint operator+(const modint &p) const { return modint(*this) += p; }
  modint operator-(const modint &p) const { return modint(*this) -= p; }
  modint operator*(const modint &p) const { return modint(*this) *= p; }
  modint operator/(const modint &p) const { return modint(*this) /= p; }
  bool operator==(const modint &p) const { return x == p.x; }
  bool operator!=(const modint &p) const { return x != p.x; }
  modint inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return modint(u);
  }
  modint pow(int64_t n) const {
    modint ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const modint &p) { return os << p.x; }
  friend istream &operator>>(istream &is, modint &a) {
    int64_t t;
    is >> t;
    a = modint<mod>(t);
    return (is);
  }
  static int get_mod() { return mod; }
};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
T mypow(T x, ll n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) (ret *= x);
    (x *= x);
    n >>= 1;
  }
  return ret;
}
ll modpow(ll x, ll n, const ll mod) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) (ret *= x);
    (x *= x);
    n >>= 1;
    x %= mod;
    ret %= mod;
  }
  return ret;
}
uint64_t my_rand(void) {
  static uint64_t x = 88172645463325252ULL;
  x = x ^ (x << 13);
  x = x ^ (x >> 7);
  return x = x ^ (x << 17);
}
template <typename T>
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T> >;
template <typename T>
using WeightedGraph = vector<Edges<T> >;
const long double eps = 0.001;
const long double PI = 3.141592653589793;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << setprecision(20);
  int n;
  cin >> n;
  mat<pair<int, int> > event(n + 1);
  for (int i = (0), max_i = (n); i < max_i; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    event[a].emplace_back(make_pair(b, i));
  }
  multiset<pair<int, int> > R;
  vector<int> cumsum(n + 1);
  vector<int> ans(n, -1);
  vector<int> girigiri(n);
  for (int i = (0), max_i = (n); i < max_i; i++) {
    for (pair<int, int> p : event[i]) {
      R.insert(p);
    }
    pair<int, int> r = *R.begin();
    ans[r.second] = i;
    R.erase(R.begin());
    if (r.first == i + 1) girigiri[i]++;
  }
  for (int i = (0), max_i = (n); i < max_i; i++)
    cumsum[i + 1] = cumsum[i] + girigiri[i];
  bool flag = true;
  vector<int> ans2(n);
  for (int i = (0), max_i = (n); i < max_i; i++) {
    for (pair<int, int> p : event[i]) {
      R.insert(p);
    }
    pair<int, int> r = *R.begin();
    if (((int)(R).size()) == 1) {
      R.erase(R.begin());
      ans2[r.second] = i;
      continue;
    }
    pair<int, int> r1 = *(++R.begin());
    if (flag && girigiri[i] == 0 &&
        cumsum[ans[r1.second]] - cumsum[r.first - 1] <= 0) {
      R.erase(++R.begin());
      ans2[r1.second] = i;
      flag = false;
    } else {
      R.erase(R.begin());
      ans2[r.second] = i;
    }
  }
  if (flag) {
    cout << "Yes" << '\n';
    for (int i = (0), max_i = (n); i < max_i; i++) cout << ans[i] + 1 << ' ';
    cout << '\n';
  } else {
    cout << "NO" << '\n';
    for (int i = (0), max_i = (n); i < max_i; i++) cout << ans[i] + 1 << ' ';
    cout << '\n';
    for (int i = (0), max_i = (n); i < max_i; i++) cout << ans2[i] + 1 << ' ';
    cout << '\n';
  }
}
