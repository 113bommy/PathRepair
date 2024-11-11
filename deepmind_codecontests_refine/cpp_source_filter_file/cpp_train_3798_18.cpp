#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> r[N], c[N];
struct query {
  int idx, x1, y1, x2, y2;
  void in(int x) {
    idx = x;
    cin >> x1 >> y1 >> x2 >> y2;
  }
};
vector<query> R[N], C[N];
template <typename T>
struct RMQ {
  using F = function<T(const T&, const T&)>;
  int n;
  const static int inf = 0x3f3f3f3f;
  vector<T> t;
  F f;
  RMQ(int n, F f, T df = 0) : n(n), f(f), t(vector<T>(n << 1, df)) {}
  void modify(int p, T v) {
    for (t[p += n] = v; p > 1; p >>= 1) t[p >> 1] = f(t[p], t[p ^ 1]);
  }
  T query(int l, int r, T res = inf) {
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = f(res, t[l++]);
      if (r & 1) res = f(res, t[--r]);
    }
    return res;
  }
};
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    r[x].push_back(y);
    c[y].push_back(x);
  }
  vector<int> ans(q + 1, false);
  for (int i = 1; i <= q; i++) {
    query x;
    x.in(i);
    R[x.x2].push_back(x);
    C[x.y2].push_back(x);
  }
  RMQ<int> tc(N, [&](int x, int y) { return min(x, y); }),
      tr(N, [&](int x, int y) { return min(x, y); });
  for (int i = 1; i < N; i++) {
    for (int y : r[i]) {
      tr.modify(y, i);
    }
    for (int x : c[i]) {
      tc.modify(x, i);
    }
    for (auto [idx, x1, x2, y1, y2] : R[i]) {
      ans[idx] |= tr.query(y1, y2) >= x1;
    }
    for (auto [idx, x1, x2, y1, y2] : C[i]) {
      ans[idx] |= tc.query(x1, x2) >= y1;
    }
  }
  for (int i = 1; i <= q; i++) cout << (ans[i] ? "YES" : "NO") << "\n";
}
