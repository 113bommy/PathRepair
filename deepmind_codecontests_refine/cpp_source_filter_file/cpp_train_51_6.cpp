#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct segment_tree {
  int n;
  vector<T> a;
  function<T(T, T)> append;
  T unit;
  template <typename F>
  segment_tree(int a_n, T a_unit, F a_append) {
    n = pow(2, ceil(log2(a_n)));
    a.resize(2 * n - 1, a_unit);
    unit = a_unit;
    append = a_append;
  }
  void point_update(int i, T z) {
    a[i + n - 1] = z;
    for (i = (i + n) / 2; i > 0; i /= 2) {
      a[i - 1] = append(a[2 * i - 1], a[2 * i]);
    }
  }
  T range_concat(int l, int r) { return range_concat(0, 0, n, l, r); }
  T range_concat(int i, int il, int ir, int l, int r) {
    if (l <= il and ir <= r) {
      return a[i];
    } else if (ir <= l or r <= il) {
      return unit;
    } else {
      return append(range_concat(2 * i + 1, il, (il + ir) / 2, l, r),
                    range_concat(2 * i + 2, (il + ir) / 2, ir, l, r));
    }
  }
};
int main() {
  int n, k, a, b, q;
  cin >> n >> k >> a >> b >> q;
  segment_tree<long long> ta(n, 0, [&](int x, int y) { return x + y; });
  segment_tree<long long> tb(n, 0, [&](int x, int y) { return x + y; });
  for (int query = 0; (query) < (q); ++(query)) {
    int type;
    cin >> type;
    if (type == 1) {
      int d, c;
      cin >> d >> c;
      --d;
      ta.point_update(d, min<long long>(a, ta.range_concat(d, d + 1) + c));
      tb.point_update(d, min<long long>(b, ta.range_concat(d, d + 1) + c));
    } else if (type == 2) {
      int p;
      cin >> p;
      --p;
      cout << tb.range_concat(0, p) + ta.range_concat(min(p + k, n), n) << endl;
    }
  }
  return 0;
}
