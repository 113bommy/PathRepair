#include <bits/stdc++.h>
static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;
template <class T>
constexpr T INF = ::numeric_limits<T>::max() / 32 * 15 + 208;
template <class M>
struct LazySegmentTree {
  using T = typename M::T;
  using L = typename M::L;
  int sz, height{};
  vector<T> seg;
  vector<L> lazy;
  explicit LazySegmentTree(int n) {
    sz = 1;
    while (sz < n) sz <<= 1, height++;
    seg.assign(2 * sz, M::e());
    lazy.assign(2 * sz, M::l());
  }
  void set(int k, const T &x) { seg[k + sz] = x; }
  void build() {
    for (int i = sz - 1; i > 0; --i)
      seg[i] = M::f(seg[i << 1], seg[(i << 1) | 1]);
  }
  T reflect(int k) {
    return lazy[k] == M::l() ? seg[k] : M::g(seg[k], lazy[k]);
  }
  void eval(int k) {
    if (lazy[k] == M::l()) return;
    lazy[(k << 1) | 0] = M::h(lazy[(k << 1) | 0], lazy[k]);
    lazy[(k << 1) | 1] = M::h(lazy[(k << 1) | 1], lazy[k]);
    seg[k] = reflect(k);
    lazy[k] = M::l();
  }
  void thrust(int k) {
    for (int i = height; i; --i) eval(k >> i);
  }
  void recalc(int k) {
    while (k >>= 1) seg[k] = M::f(reflect((k << 1) | 0), reflect((k << 1) | 1));
  }
  void update(int a, int b, const L &x) {
    thrust(a += sz);
    thrust(b += sz - 1);
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lazy[l] = M::h(lazy[l], x), l++;
      if (r & 1) --r, lazy[r] = M::h(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }
  T query(int a, int b) {
    thrust(a += sz);
    thrust(b += sz - 1);
    T ll = M::e(), rr = M::e();
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ll = M::f(ll, reflect(l++));
      if (r & 1) rr = M::f(reflect(--r), rr);
    }
    return M::f(ll, rr);
  }
};
struct Monoid {
  using T = ll;
  using L = ll;
  static T f(T a, T b) { return max(a, b); }
  static T g(T a, L b) { return a + b; }
  static L h(L a, L b) { return a + b; }
  static T e() { return -INF<ll>; }
  static L l() { return 0; }
};
int main() {
  int n, m, p;
  cin >> n >> m >> p;
  vector<pair<int, int>> A(n), B(m);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &A[i].first, &A[i].second);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &B[i].first, &B[i].second);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  vector<tuple<int, int, int>> v(p);
  for (int i = 0; i < p; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    v[i] = {a, b, c};
  }
  sort(v.begin(), v.end());
  int M = 1000001;
  vector<int> dp(M + 1, -INF<ll>);
  int cur = m - 1;
  LazySegmentTree<Monoid> seg(M);
  for (int i = M; i >= 0; --i) {
    if (i != M) dp[i] = max(dp[i], dp[i + 1]);
    while (cur >= 0 && B[cur].first > i) {
      dp[i] = max(dp[i], -B[cur].second);
      cur--;
    }
    seg.set(i, dp[i]);
  }
  seg.build();
  ll ans = -INF<ll>;
  cur = 0;
  for (int i = 0; i < n; ++i) {
    while (cur < p && get<0>(v[cur]) < A[i].first) {
      seg.update(get<1>(v[cur]), M + 1, get<2>(v[cur]));
      cur++;
    }
    ans = max(ans, seg.query(0, M + 1) - A[i].second);
  }
  cout << ans << "\n";
  return 0;
}
