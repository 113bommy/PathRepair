#include <bits/stdc++.h>
using namespace std;
template <typename T, typename F>
class SegTree {
  int n;
  T uni;
  F f;
  vector<T> dat;

 public:
  SegTree(int _n, F f, T uni) : f(f), uni(uni) {
    n = 1;
    while (n < _n) n *= 2;
    dat = vector<T>(2 * n, uni);
  }
  void set(int k, const T x) { dat[k + n] = x; }
  void build() {
    for (int i = n - 1; i >= 0; i--) {
      dat[i] = f(dat[2 * i], dat[2 * i + 1]);
    }
  }
  void update(int k, T x) {
    k += n;
    dat[k] = x;
    while (k >>= 1) {
      dat[k] = f(dat[2 * k], dat[2 * k + 1]);
    }
  }
  T query(int a, int b) {
    T l = uni, r = uni;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
      if (a & 1) l = f(l, dat[a++]);
      if (b & 1) r = f(dat[--b], r);
    }
    return f(l, r);
  }
};
int main() {
  int n, k, d;
  scanf("%d %d %d", &n, &k, &d);
  int a[n];
  for (int i = 0; i < (int)n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  auto f = [](int a, int b) { return a + b; };
  SegTree<int, decltype(f)> st(n + 1, f, 0);
  st.set(0, 1);
  for (int i = 0; i < (int)n; i++) {
    int l = lower_bound(a, a + n, a[i] - d) - a;
    int r = max(0, i - k + 2);
    if (st.query(l, r) > 0) st.update(i + 1, 1);
  }
  cout << (st.query(n, n + 1) ? "YES" : "NO") << endl;
  return 0;
}
