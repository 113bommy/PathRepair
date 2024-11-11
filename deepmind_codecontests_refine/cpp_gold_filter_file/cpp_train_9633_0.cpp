#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const int N = 1e6 + 5;
int n, k;
int ans[N];
int a[N], b[N];
const int TERM = 0;
struct Segtree {
  vector<int> t;
  Segtree() { t.assign(4 * N, 0); }
  int combine(const int& x, const int& y) { return (x > y ? x : y); }
  void build(int v, int s, int e) {
    if (s == e) {
      t[v] = a[s];
    } else {
      int mid = (s + e) >> 1;
      build(v << 1, s, mid);
      build(v << 1 | 1, mid + 1, e);
      t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }
  }
  int get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return TERM;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    int p1 = get(v << 1, s, mid, l, r);
    int p2 = get(v << 1 | 1, mid + 1, e, l, r);
    return combine(p1, p2);
  }
} sgt;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] *= 100;
  }
  sgt.build(1, 1, n);
  vector<pair<int, int>> v(n);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    v[i - 1] = make_pair(b[i], i);
  }
  sort(v.begin(), v.end());
  debug() << "["
          << "v"
             ": "
          << (v) << "] ";
  set<int> st = {n + 1};
  for (int i = 0; i < n; i++) {
    int L = v[i].second;
    int R = *st.upper_bound(L);
    ans[L] = min(sgt.get(1, 1, n, L, R - 1), v[i].first);
    ans[L] = max(ans[L], ans[R]);
    st.emplace(L);
    debug() << "["
            << "L"
               ": "
            << (L)
            << "] "
               "["
            << "R"
               ": "
            << (R)
            << "] "
               "["
            << "ans[L]"
               ": "
            << (ans[L]) << "] ";
  }
  debug() << "["
          << "range(ans + 1, ans + 1 + n)"
             ": "
          << (range(ans + 1, ans + 1 + n)) << "] ";
  sort(ans + 1, ans + 1 + n);
  long double answer = 0;
  long double F = (long double)k / n;
  for (int i = 1; i <= n; i++) {
    answer += (long double)ans[i] * F;
    if (n > i) F = (F * (long double)(n - k - i + 1) / (n - i));
  }
  cout << fixed << setprecision(12) << answer << '\n';
  return 0;
}
