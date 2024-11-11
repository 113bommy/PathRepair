#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
const ll inf = (1e18);
const ll mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }
struct __INIT {
  __INIT() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
  }
} __init;
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
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
struct ST {
  using F = function<T(T, T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  ST(){};
  ST(F f, T ti) : f(f), ti(ti) {}
  void init(int n_) {
    n = 1;
    while (n < n_) n <<= 1;
    dat.assign(n << 1, ti);
  }
  void build(const vector<T> &v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++) dat[n + i] = v[i];
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }
  void set_val(int k, T x) {
    dat[k += n] = x;
    while (k >>= 1) dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
  }
  T query(int a, int b) {
    T vl = ti, vr = ti;
    for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f(vl, dat[l++]);
      if (r & 1) vr = f(dat[--r], vr);
    }
    return f(vl, vr);
  }
};
int main() {
  auto f = [](ll a, ll b) { return max(a, b); };
  auto g = [](ll a, ll b) { return min(a, b); };
  int n;
  cin >> n;
  V<ll> l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  ST<ll> segl(f, 0ll), segr(g, inf);
  segl.build(l);
  segr.build(r);
  ll ma, mi, ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      mi = segl.query(i + 1, n);
      ma = segr.query(i + 1, n);
      chmax(ans, ma - mi);
    } else if (i == n - 1) {
      mi = segl.query(0, n - 1);
      ma = segr.query(0, n - 1);
      chmax(ans, ma - mi);
    } else {
      mi = f(segl.query(0, i), segl.query(i + 1, n));
      ma = g(segr.query(0, i), segr.query(i + 1, n));
      chmax(ans, ma - mi);
    }
  }
  cout << ans << "\n";
}
