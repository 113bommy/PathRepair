#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll mod = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;
ll mod_sum() { return 0LL; }
template <typename T, typename... Args>
T mod_sum(T a, Args... args) {
  return ((a + mod_sum(args...)) % mod + mod) % mod;
}
ll mod_prod() { return 1LL; }
template <typename T, typename... Args>
T mod_prod(T a, Args... args) {
  return (a * mod_prod(args...)) % mod;
}
using pii = pair<ll, ll>;
using vi = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vector<ll> >;
using vvb = vector<vector<bool> >;
using vpii = vector<pii>;
using vvpii = vector<vector<pii> >;
struct SegmentTree {
  vi t;
  SegmentTree(ll n) { t.resize(4 * n); }
  void build(ll v, ll tl, ll tr, vi& vec) {
    if (tl == tr) {
      t[v] = vec[tl];
      return;
    }
    ll tm = (tl + tr) >> 1;
    build(v << 1, tl, tm, vec);
    build(v << 1 | 1, tm + 1, tr, vec);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
  }
  void update(ll v, ll tl, ll tr, ll pos, ll val) {
    if (tl == tr) {
      t[v] = val;
      return;
    }
    ll tm = (tl + tr) >> 1;
    if (pos <= tm)
      update(v << 1, tl, tm, pos, val);
    else
      update(v << 1 | 1, tm + 1, tr, pos, val);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
  }
  ll query(ll v, ll tl, ll tr, ll ql, ll qr) {
    if (ql > qr) return 0;
    if (ql <= tl && tr <= qr) return t[v];
    ll tm = (tl + tr) >> 1;
    ll val = 0;
    if (ql <= tm) val = max(val, query(v << 1, tl, tm, ql, qr));
    if (tm + 1 <= qr) val = max(val, query(v << 1 | 1, tm + 1, tr, ql, qr));
    return val;
  }
};
ll solve() {
  ll n;
  cin >> n;
  vpii vec(n);
  for (ll i = 0; i < n; i++) {
    ll r, h;
    cin >> r >> h;
    vec[i] = {r * r * h, -i};
  }
  sort((vec).begin(), (vec).end());
  SegmentTree st(n);
  for (ll i = 0; i < n; i++) {
    ll x = st.query(1, 0, n - 1, 0, -vec[i].second - 1);
    st.update(1, 0, n - 1, -vec[i].second, x + vec[i].first);
  }
  ld ans = 3.14159265358979323846 * (ld)st.query(1, 0, n - 1, 0, n - 1);
  printf("%0.12Lf\n", ans);
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t = 1;
  while (t--) solve();
  return 0;
}
