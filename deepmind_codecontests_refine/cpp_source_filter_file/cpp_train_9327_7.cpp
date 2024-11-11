#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pair<int, int>>;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vpl = vector<pl>;
using ld = long double;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos((ld)-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
bool ckmax(T &a, const T &b) {
  return b > a ? a = b, 1 : 0;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
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
};
void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
struct Node {
  ll cnt, tl, tr;
};
template <typename T>
struct LazySegTree {
  const T seg_initial = {0, 0, 0};
  const ll seg_lazy_sentinel = 0;
  const T NEUTRAL = {0, 0, 0};
  long long sz;
  vector<T> t;
  vl lazy;
  inline T merge(T a, T b) {
    if (a.tl == 0) return b;
    if (b.tl == 0) return a;
    return {a.cnt + b.cnt, a.tl, b.tr};
  }
  inline ll lazy_apply(ll lazy_val, ll new_val) {
    if (lazy_val == 0 || new_val == 1 || new_val == 2) return new_val;
    if (lazy_val == new_val) return 0;
    return (lazy_val == 1 ? 2 : 1);
  }
  inline ll lazy_func(T nn, ll lazy_val, ll l, ll r) {
    if (lazy_val == 1)
      return nn.tr - nn.tl;
    else if (lazy_val == 2)
      return 0;
    else
      return nn.tr - nn.tl - nn.cnt;
  }
  void init(long long n) {
    sz = 1;
    while (sz < n) sz *= 2;
    t.assign(2 * sz, seg_initial);
    lazy.assign(2 * sz, seg_lazy_sentinel);
  }
  void seg_eval_lazy(long long i, ll l, ll r) {
    if (lazy[i] == seg_lazy_sentinel) return;
    t[i].cnt = lazy_func(t[i], lazy[i], l, r);
    if (r - l > 1) {
      lazy[i * 2 + 1] = lazy_apply(lazy[i * 2 + 1], lazy[i]);
      lazy[i * 2 + 2] = lazy_apply(lazy[i * 2 + 2], lazy[i]);
    }
    lazy[i] = seg_lazy_sentinel;
  }
  void build(vector<Node> &vec, long long x, long long l, long long r) {
    if (r - l == 1) {
      if (l < (long long)vec.size()) t[x] = vec[l];
      return;
    }
    long long mid = (l + r) / 2;
    build(vec, 2 * x + 1, l, mid);
    build(vec, 2 * x + 2, mid, r);
    t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
  }
  void build(vector<Node> &vec) { build(vec, 0, 0, sz); }
  T upd(long long x, long long l, long long r, long long lx, long long rx,
        long long v) {
    seg_eval_lazy(x, lx, rx);
    if (lx >= r || rx <= l) return t[x];
    if (lx >= l && rx <= r) {
      lazy[x] = lazy_apply(lazy[x], v);
      seg_eval_lazy(x, lx, rx);
      return t[x];
    }
    if (rx - lx == 1) return t[x];
    long long mid = (lx + rx) / 2;
    T a = upd(2 * x + 1, l, r, lx, mid, v);
    T b = upd(2 * x + 2, l, r, mid, rx, v);
    return t[x] = merge(a, b);
  }
  void upd(long long l, long long r, long long v) { upd(0, l, r, 0, sz, v); }
  ll query(long long x, long long lx, long long rx) {
    seg_eval_lazy(x, lx, rx);
    if (t[x].cnt == 0) return 1;
    if (t[x].cnt == t[x].tr - t[x].tl) return t[x].cnt;
    long long mid = (lx + rx) / 2;
    seg_eval_lazy(x * 2 + 1, lx, mid);
    seg_eval_lazy(x * 2 + 2, mid, rx);
    if (t[2 * x + 1].cnt == t[2 * x + 1].tr - t[2 * x + 1].tl)
      return t[2 * x + 1].cnt + query(2 * x + 2, mid, rx);
    else
      return query(2 * x + 1, lx, mid);
  }
  ll query() { return query(0, 0, sz); }
};
void solve() {
  long long n;
  cin >> n;
  vector<Node> v;
  vl a;
  vector<array<ll, 3>> q(n);
  for (long long i = (0); i < (n); ++i) {
    ll t, l, r;
    cin >> t >> l >> r;
    q[i] = {t, l, r};
    a.push_back(l), a.push_back(r);
  }
  a.push_back(LINF), a.push_back(1);
  sort((a).begin(), (a).end()),
      a.resize(unique((a).begin(), (a).end()) - a.begin());
  for (long long i = (0); i < (2 * (long long)(a).size() - 1); ++i) {
    if (i & 1) {
      v.push_back({0LL, a[i / 2LL] + 1LL, a[(i + 1LL) / 2LL]});
    } else {
      v.push_back({0LL, a[i / 2LL], a[i / 2LL] + 1LL});
    }
  }
  LazySegTree<Node> st;
  st.init((long long)(v).size());
  st.build(v);
  for (long long i = (0); i < (n); ++i) {
    auto [t, l, r] = q[i];
    l = lower_bound((a).begin(), (a).end(), l) - a.begin(),
    r = lower_bound((a).begin(), (a).end(), r) - a.begin();
    st.upd(2 * l, 2 * r + 1, t);
    cout << st.query() << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long testcase = 1;
  while (testcase--) {
    solve();
  }
}
