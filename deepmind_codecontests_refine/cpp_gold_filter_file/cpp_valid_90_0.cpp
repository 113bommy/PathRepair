#include <bits/stdc++.h>
namespace atcoder {
namespace internal {
int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n)) x++;
  return x;
}
int bsf(unsigned int n) { return __builtin_ctz(n); }
}  // namespace internal
}  // namespace atcoder
namespace atcoder {
template <class S, S (*op)(S, S), S (*e)()>
struct segtree {
 public:
  segtree() : segtree(0) {}
  explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
  explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
    log = internal::ceil_pow2(_n);
    size = 1 << log;
    d = std::vector<S>(2 * size, e());
    for (int i = 0; i < _n; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }
  void set(int p, S x) {
    assert(0 <= p && p < _n);
    p += size;
    d[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }
  S get(int p) const {
    assert(0 <= p && p < _n);
    return d[p + size];
  }
  S prod(int l, int r) const {
    assert(0 <= l && l <= r && r <= _n);
    S sml = e(), smr = e();
    l += size;
    r += size;
    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }
    return op(sml, smr);
  }
  S all_prod() const { return d[1]; }
  template <bool (*f)(S)>
  int max_right(int l) const {
    return max_right(l, [](S x) { return f(x); });
  }
  template <class F>
  int max_right(int l, F f) const {
    assert(0 <= l && l <= _n);
    assert(f(e()));
    if (l == _n) return _n;
    l += size;
    S sm = e();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!f(op(sm, d[l]))) {
        while (l < size) {
          l = (2 * l);
          if (f(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }
  template <bool (*f)(S)>
  int min_left(int r) const {
    return min_left(r, [](S x) { return f(x); });
  }
  template <class F>
  int min_left(int r, F f) const {
    assert(0 <= r && r <= _n);
    assert(f(e()));
    if (r == 0) return 0;
    r += size;
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!f(op(d[r], sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (f(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

 private:
  int _n, size, log;
  std::vector<S> d;
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
}  // namespace atcoder
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
inline ll popcnt(ull a) { return __builtin_popcountll(a); }
ll intpow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b /= 2;
  }
  return ans;
}
ll intpow(ll a, ll b, ll m) {
  ll ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= m;
    (a *= a) %= m;
    b /= 2;
  }
  return ans;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
void scan(T& a) {
  cin >> a;
}
template <class T>
void scan(vector<T>& a) {
  for (auto&& i : a) scan(i);
}
void in() {}
template <class Head, class... Tail>
void in(Head& head, Tail&... tail) {
  scan(head);
  in(tail...);
}
void print() { cout << ' '; }
template <class T>
void print(const T& a) {
  cout << a;
}
template <class T>
void print(const vector<T>& a) {
  if (a.empty()) return;
  print(a[0]);
  for (auto i = a.begin(); ++i != a.end();) {
    cout << ' ';
    print(*i);
  }
}
int out() {
  cout << '\n';
  return 0;
}
template <class T>
int out(const T& t) {
  print(t);
  cout << '\n';
  return 0;
}
template <class Head, class... Tail>
int out(const Head& head, const Tail&... tail) {
  print(head);
  cout << ' ';
  out(tail...);
  return 0;
}
const ll inf = 1LL << 45;
ll op(ll a, ll b) { return min(a, b); }
ll e() { return inf; }
void solve() {
  long long n, m;
  in(n, m);
  vector<long long> a(n);
  in(a);
  a.push_back(-inf);
  a.push_back(inf);
  n += 2;
  sort(a.begin(), a.end());
  vc<long long> l, r;
  map<long long, long long> mp;
  for (long long i = 0; i < m; ++i) {
    long long x, y;
    in(x, y);
    long long id = distance((a).begin(), lower_bound(a.begin(), a.end(), (x))),
              id2 = distance((a).begin(), upper_bound(a.begin(), a.end(), (y)));
    if (id == id2) {
      if (mp.count(x))
        chmin(mp[x], y);
      else
        mp[x] = y;
    }
  }
  for (auto [x, y] : mp) {
    l.push_back(x);
    r.push_back(y);
  }
  m = (long long)(l).size();
  vc<long long> ids(m);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(),
       [&](long long i, long long j) { return l[i] < l[j]; });
  vc<long long> nl(m), nr(m);
  for (long long i = 0; i < m; ++i) {
    nl[i] = l[ids[i]];
    nr[i] = r[ids[i]];
  }
  swap(nl, l);
  swap(nr, r);
  atcoder::segtree<ll, op, e> seg(r);
  vc<long long> dp(3, inf);
  vc<long long> ndp(3, inf);
  dp[0] = 0;
  for (long long i = 1; i < n; ++i) {
    long long mi =
        distance((l).begin(), lower_bound(l.begin(), l.end(), (a[i - 1])));
    long long ma =
        distance((l).begin(), upper_bound(l.begin(), l.end(), (a[i])));
    ndp.assign(3, inf);
    if (mi == ma) {
      ndp[0] = min({dp[0], dp[1], dp[2]});
    } else {
      long long len = l[ma - 1] - a[i - 1];
      ndp[0] = min({dp[0] + len, dp[1] + len * 2, dp[2] + len});
      long long rlen = a[i] - seg.prod(mi, ma);
      ndp[1] = min({dp[0], dp[1], dp[2]}) + rlen;
      ndp[2] = min({dp[0], dp[1], dp[2]}) + rlen * 2;
      for (long long f = mi; f < ma - 1; ++f) {
        for (long long rcost = 1; rcost <= 2; ++rcost) {
          for (long long j = 0; j <= 2; ++j) {
            long long lcost = (j == 1 ? 2 : 1);
            chmin(ndp[rcost], dp[j] + lcost * (l[f] - a[i - 1]) +
                                  rcost * (a[i] - seg.prod(f + 1, ma)));
          }
        }
      }
    }
    swap(dp, ndp);
  }
  ll ans = inf;
  for (long long j = 0; j < 3; ++j) {
    chmin(ans, dp[j]);
  }
  out(ans);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  in(t);
  for (long long i = 0; i < t; ++i) solve();
  return 0;
}
