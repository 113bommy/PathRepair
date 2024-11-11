#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vvvvll = vector<vvvll>;
using dd = double;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;
using qll = tuple<ll, ll, ll, ll>;
using vpll = vector<pll>;
constexpr ll INF = 1LL << 60;
struct Fast {
  Fast() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(numeric_limits<double>::max_digits10);
  }
} fast;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline T MaxE(vector<T> &v, ll S, ll E) {
  T m = v[S];
  for (ll i = (S); i <= (E); i++) chmax(m, v[i]);
  return m;
}
template <class T>
inline T MinE(vector<T> &v, ll S, ll E) {
  T m = v[S];
  for (ll i = (S); i <= (E); i++) chmin(m, v[i]);
  return m;
}
template <class T>
inline T MaxE(vector<T> &v) {
  return MaxE(v, 0, (ll)v.size() - 1);
}
template <class T>
inline T MinE(vector<T> &v) {
  return MinE(v, 0, (ll)v.size() - 1);
}
template <class T>
inline T Sum(vector<T> &v, ll S, ll E) {
  T s = T();
  for (ll i = (S); i <= (E); i++) s += v[i];
  return s;
}
template <class T>
inline T Sum(vector<T> &v) {
  return Sum(v, 0, v.size() - 1);
}
template <class T>
inline ll sz(T &v) {
  return (ll)v.size();
}
inline ll CEIL(ll a, ll b) { return (a < 0) ? -(-a / b) : (a + b - 1) / b; }
inline ll FLOOR(ll a, ll b) { return -CEIL(-a, b); }
using vpll = vector<pll>;
using vvpll = vector<vpll>;
template <class T, class S>
inline pair<T, S> &operator+=(pair<T, S> &a, const pair<T, S> &b) {
  a.first += b.first;
  a.second += b.second;
  return a;
}
template <class T, class S>
inline pair<T, S> &operator-=(pair<T, S> &a, const pair<T, S> &b) {
  a.first -= b.first;
  a.second -= b.second;
  return a;
}
template <class T, class S>
inline pair<T, S> &operator*=(pair<T, S> &a, const pair<T, S> &b) {
  a.first *= b.first;
  a.second *= b.second;
  return a;
}
template <class T, class S>
inline pair<T, S> &operator/=(pair<T, S> &a, const pair<T, S> &b) {
  a.first /= b.first;
  a.second /= b.second;
  return a;
}
template <class T, class S>
inline pair<T, S> &operator%=(pair<T, S> &a, const pair<T, S> &b) {
  a.first %= b.first;
  a.second %= b.second;
  return a;
}
template <class T, class S, class R>
inline pair<T, S> &operator+=(pair<T, S> &a, R b) {
  a.first += b;
  a.second += b;
  return a;
}
template <class T, class S, class R>
inline pair<T, S> &operator-=(pair<T, S> &a, R b) {
  a.first -= b;
  a.second -= b;
  return a;
}
template <class T, class S, class R>
inline pair<T, S> &operator*=(pair<T, S> &a, R b) {
  a.first *= b;
  a.second *= b;
  return a;
}
template <class T, class S, class R>
inline pair<T, S> &operator/=(pair<T, S> &a, R b) {
  a.first /= b;
  a.second /= b;
  return a;
}
template <class T, class S, class R>
inline pair<T, S> &operator%=(pair<T, S> &a, R b) {
  a.first %= b;
  a.second %= b;
  return a;
}
template <class T, class S, class R>
inline pair<T, S> operator+(const pair<T, S> &a, R b) {
  pair<T, S> c = a;
  return c += b;
}
template <class T, class S, class R>
inline pair<T, S> operator-(const pair<T, S> &a, R b) {
  pair<T, S> c = a;
  return c -= b;
}
template <class T, class S, class R>
inline pair<T, S> operator*(const pair<T, S> &a, R b) {
  pair<T, S> c = a;
  return c *= b;
}
template <class T, class S, class R>
inline pair<T, S> operator/(const pair<T, S> &a, R b) {
  pair<T, S> c = a;
  return c /= b;
}
template <class T, class S, class R>
inline pair<T, S> operator%(const pair<T, S> &a, R b) {
  pair<T, S> c = a;
  return c %= b;
}
template <class T, class S, class R>
inline pair<T, S> operator-(R b, const pair<T, S> &a) {
  pair<T, S> c = -a;
  return c += b;
}
template <class T, class S>
inline pair<T, S> operator-(const pair<T, S> &a) {
  pair<T, S> c = a;
  return c *= (-1);
}
template <class T, class S>
inline ostream &operator<<(ostream &os, const pair<T, S> &a) {
  return os << a.first << ' ' << a.second;
}
template <class T>
inline vector<T> &operator+=(vector<T> &a, const vector<T> &b) {
  for (ll i = 0; i < (ll)a.size(); i++) a[i] += b[i];
  return a;
}
template <class T>
inline vector<T> &operator-=(vector<T> &a, const vector<T> &b) {
  for (ll i = 0; i < (ll)a.size(); i++) a[i] -= b[i];
  return a;
}
template <class T>
inline vector<T> &operator*=(vector<T> &a, const vector<T> &b) {
  for (ll i = 0; i < (ll)a.size(); i++) a[i] *= b[i];
  return a;
}
template <class T>
inline vector<T> &operator/=(vector<T> &a, const vector<T> &b) {
  for (ll i = 0; i < (ll)a.size(); i++) a[i] /= b[i];
  return a;
}
template <class T>
inline vector<T> &operator%=(vector<T> &a, const vector<T> &b) {
  for (ll i = 0; i < (ll)a.size(); i++) a[i] %= b[i];
  return a;
}
template <class T, class S>
inline vector<T> &operator+=(vector<T> &a, S b) {
  for (T &e : a) e += b;
  return a;
}
template <class T, class S>
inline vector<T> &operator-=(vector<T> &a, S b) {
  for (T &e : a) e -= b;
  return a;
}
template <class T, class S>
inline vector<T> &operator*=(vector<T> &a, S b) {
  for (T &e : a) e *= b;
  return a;
}
template <class T, class S>
inline vector<T> &operator/=(vector<T> &a, S b) {
  for (T &e : a) e /= b;
  return a;
}
template <class T, class S>
inline vector<T> &operator%=(vector<T> &a, S b) {
  for (T &e : a) e %= b;
  return a;
}
template <class T, class S>
inline vector<T> operator+(const vector<T> &a, S b) {
  vector<T> c = a;
  return c += b;
}
template <class T, class S>
inline vector<T> operator-(const vector<T> &a, S b) {
  vector<T> c = a;
  return c -= b;
}
template <class T, class S>
inline vector<T> operator*(const vector<T> &a, S b) {
  vector<T> c = a;
  return c *= b;
}
template <class T, class S>
inline vector<T> operator/(const vector<T> &a, S b) {
  vector<T> c = a;
  return c /= b;
}
template <class T, class S>
inline vector<T> operator%(const vector<T> &a, S b) {
  vector<T> c = a;
  return c %= b;
}
template <class T, class S>
inline vector<T> operator-(S b, const vector<T> &a) {
  vector<T> c = -a;
  return c += b;
}
template <class T>
inline vector<T> operator-(const vector<T> &a) {
  vector<T> c = a;
  return c *= (-1);
}
template <class T>
inline ostream &operator<<(ostream &os, const vector<T> &a) {
  for (ll i = 0; i < (ll)a.size(); i++) os << (i > 0 ? " " : "") << a[i];
  return os;
}
template <class T>
struct SegmentTree {
  using F = function<T(T, T)>;
  vector<T> dat;
  ll n;
  F f;
  T ti;
  SegmentTree() {}
  SegmentTree(vector<T> &v, F f, T ti) { Init(v, f, ti); }
  void Init(vector<T> &v, F f, T ti) {
    this->f = f;
    this->ti = ti;
    for (n = 1; n < (ll)v.size(); n *= 2)
      ;
    dat.resize(2 * n - 1, ti);
    for (ll i = (0); i <= (((ll)v.size()) - 1); i++) {
      dat[i + n - 1] = v[i];
    }
    for (ll i = ((n - 1) - 1); i >= (0); i--) {
      dat[i] = f(dat[2 * i + 1], dat[2 * i + 2]);
    }
  }
  void Set(ll i, T x) {
    i += n - 1;
    dat[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;
      dat[i] = f(dat[2 * i + 1], dat[2 * i + 2]);
    }
  }
  T Range(ll a, ll b) { return range(a, b + 1, 0, 0, n); }
  T operator[](ll i) { return dat[i + n - 1]; }
  void Dump(ll w = 5) {
    for (ll i = (0); i <= ((n)-1); i++)
      for (ll k = i + n - 1, m = 1, p = 1; k >= 0;
           p = m, m *= k % 2, k = (k == 0) ? -1 : (k - 1) / 2) {
        if (m)
          cerr << ((k < n - 1) ? " ┬ " : "") << setw(w) << dat[k];
        else
          cerr << ((p & ~m) ? " ┘ " : "");
        if (k == 0) cerr << '\n';
      }
    cerr << '\n';
  }
  T range(ll a, ll b, ll k, ll l, ll r) {
    if (r <= a || b <= l) return ti;
    if (a <= l && r <= b) return dat[k];
    return f(range(a, b, k * 2 + 1, l, (l + r) / 2),
             range(a, b, k * 2 + 2, (l + r) / 2, r));
  }
  ll FindL(ll a, ll b, T x) { return findL(a, b + 1, x, 0, 0, n); }
  ll findL(ll a, ll b, T x, ll k, ll l, ll r) {
    if (r <= a || b <= l || f(dat[k], x) != dat[k]) return b;
    if (k >= n - 1) return k - (n - 1);
    ll i = findL(a, b, x, 2 * k + 1, l, (l + r) / 2);
    if (i == b) i = findL(a, b, x, 2 * k + 2, (l + r) / 2, r);
    return i;
  }
  ll FindR(ll a, ll b, T x) { return findR(a, b + 1, x, 0, 0, n); }
  ll findR(ll a, ll b, T x, ll k, ll l, ll r) {
    if (r <= a || b <= l || f(dat[k], x) != dat[k]) return a - 1;
    if (k >= n - 1) return k - (n - 1);
    ll i = findR(a, b, x, 2 * k + 2, (l + r) / 2, r);
    if (i == a - 1) i = findR(a, b, x, 2 * k + 1, l, (l + r) / 2);
    return i;
  }
};
void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll B = b * d;
  ll K = c / d;
  if (b * c < a) {
    cout << -1 << '\n';
    return;
  }
  auto f = [&](ll k) { return (k + 1) * a - B * k * (k + 1) / 2; };
  ll l = 1;
  ll r = K + 1;
  while (r - l > 2) {
    ll lll = (l * 2 + r) / 3;
    ll rrr = (l + r * 2) / 3;
    if (f(lll) > f(rrr))
      r = rrr;
    else
      l = lll;
  }
  ll ans = -INF;
  for (ll i = (l); i <= (r); i++) {
    chmax(ans, f(i));
  }
  cout << ans << '\n';
}
int main() {
  ll t;
  cin >> t;
  for (ll i = (0); i <= (t - 1); i++) {
    solve();
  }
  return 0;
}
