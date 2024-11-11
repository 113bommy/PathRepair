#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
inline int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline int mul(int x, int y) {
  x = (1LL * x * y) % mod;
  return x;
}
double e[N];
int p[N];
template <typename T>
struct SEGTREE {
  T seg[4 * N];
  T combine(T x, T y) {
    T ret;
    ret = x + y;
    return ret;
  }
  void build(int curr, int l, int r) {
    if (l == r) return void(seg[curr] = 0);
    build((curr << 1), l, ((l + r) >> 1));
    build(((curr << 1) | 1), ((l + r) >> 1) + 1, r);
    seg[curr] = combine(seg[(curr << 1)], seg[((curr << 1) | 1)]);
  }
  void update(int curr, int l, int r, int x, int y, T val) {
    if (x > r || y < l) return;
    if (x <= l && r <= y) return void(seg[curr] = val);
    update((curr << 1), l, ((l + r) >> 1), x, y, val);
    update(((curr << 1) | 1), ((l + r) >> 1) + 1, r, x, y, val);
    seg[curr] = combine(seg[(curr << 1)], seg[((curr << 1) | 1)]);
  }
  T query(int curr, int l, int r, int x, int y) {
    if (x > r || y < l) return 0;
    if (x <= l && r <= y) return seg[curr];
    return combine(query((curr << 1), l, ((l + r) >> 1), x, y),
                   query(((curr << 1) | 1), ((l + r) >> 1) + 1, r, x, y));
  }
};
SEGTREE<long long> st;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  st.build(1, 1, n);
  long long lol = 0;
  for (int i = n; i >= 1; --i) {
    lol += 1LL * i * st.query(1, 1, n, 1, p[i] - 1);
    st.update(1, 1, n, p[i], p[i], n - i + 1);
  }
  st.build(1, 1, n);
  long long an = 0;
  for (int i = n; i >= 1; --i) {
    an += st.query(1, 1, n, 1, p[i] - 1);
    st.update(1, 1, n, p[i], p[i], 1);
  }
  e[0] = 0;
  for (int i = 1; i <= n; ++i) {
    e[i] = e[i - 1] + (i - 1) / 2.0;
  }
  double ans = 0;
  for (int i = 1; i <= n - 1; ++i) {
    double a = e[i + 1];
    a = a * 2 * (n - i);
    a /= n;
    a /= (n + 1);
    ans += a;
  }
  double ret = lol;
  ret /= n;
  ret /= (n + 1);
  ret *= 2;
  cout << fixed << setprecision(12);
  cout << ans + an - ret;
  return 0;
}
