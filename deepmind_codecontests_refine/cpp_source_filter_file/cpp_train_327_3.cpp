#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Segtree {
  int n;
  T e;
  vector<T> dat;
  typedef function<T(T a, T b)> Func;
  Func f;
  Segtree() {}
  Segtree(int n_input, Func f_input, T e_input) {
    initialize(n_input, f_input, e_input);
  }
  void initialize(int n_input, Func f_input, T e_input) {
    f = f_input;
    e = e_input;
    n = 1;
    while (n < n_input) n <<= 1;
    dat.resize(2 * n - 1, e);
  }
  void update(int k, T a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }
  T get(int k) { return dat[k + n - 1]; }
  T between(int a, int b) { return query(a, b + 1, 0, 0, n); }
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return dat[k];
    T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return f(vl, vr);
  }
};
void solve() {
  string T;
  cin >> T;
  int N = T.size();
  int x = 0, y = 0;
  Segtree<int> xmax(
      N + 1, [](int a, int b) { return max(a, b); }, -1e9);
  Segtree<int> ymax(
      N + 1, [](int a, int b) { return max(a, b); }, -1e9);
  Segtree<int> xmin(
      N + 1, [](int a, int b) { return min(a, b); }, 1e9);
  Segtree<int> ymin(
      N + 1, [](int a, int b) { return min(a, b); }, 1e9);
  for (int i = 0; i <= N; i++) {
    xmax.update(i, x);
    xmin.update(i, x);
    ymax.update(i, y);
    ymin.update(i, y);
    if (i == N) break;
    if (T[i] == 'W') y++;
    if (T[i] == 'S') y--;
    if (T[i] == 'A') x--;
    if (T[i] == 'D') x++;
  }
  int64_t x0 = xmax.between(0, N) - xmin.between(0, N) + 1;
  int64_t y0 = ymax.between(0, N) - ymin.between(0, N) + 1;
  int64_t x1 = 1e9, y1 = 1e9;
  for (int i = 0; i <= N; i++) {
    for (int d = -1; d <= 1; d++) {
      int64_t xmx = max(xmax.between(0, i), xmax.between(i, N) + d);
      int64_t xmn = min(xmin.between(0, i), xmin.between(i, N) + d);
      x1 = min(x1, xmx - xmn + 1);
      int64_t ymx = max(ymax.between(0, i), ymax.between(i, N) + d);
      int64_t ymn = min(ymin.between(0, i), ymin.between(i, N) + d);
      y1 = min(y1, ymx - ymn + 1);
    }
  }
  int ans = min(x0 * y1, x1 * y0);
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
