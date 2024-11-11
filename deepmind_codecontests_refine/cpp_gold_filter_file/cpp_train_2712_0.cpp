#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;

struct SegmentTree {
  size_t n;
  vector<int> v;

  SegmentTree(size_t size) : n(1 << (32 - __builtin_clz(size - 1))), v(2 * n - 1, inf) {}

  void update(int k, int x) {
    k += n - 1;
    v[k] = x;
    while (k) {
      k = (k - 1) / 2;
      v[k] = min(v[2 * k + 1], v[2 * k + 2]);
    }
  }

  int query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return inf;
    if (a <= l && r <= b) return v[k];
    return min(query(a, b, 2 * k + 1, l, (l + r) / 2), query(a, b, 2 * k + 2, (l + r) / 2, r));
  }

  int query(int l, int r) {
    return query(l, r, 0, 0, n);
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  SegmentTree seg(n);
  while (q--) {
    int c, x, y;
    cin >> c >> x >> y;

    if (c) {
      cout << seg.query(x, y + 1) << endl;
    } else {
      seg.update(x, y);
    }
  }
}