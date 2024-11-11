#include <bits/stdc++.h>
using namespace std;
long long mask = 0;
struct SegTree {
  int size;
  vector<long long> seg;
  SegTree() {}
  SegTree(int size) {
    this->size = size;
    seg.resize(1 << (size + 1));
  }
  void init() {
    for (int i = 0; i < (1 << (size + 1)); i++) seg[i] = 0;
  }
  void update(int i, long long val) {
    long long l = 0, r = (1 << size) - 1;
    for (int d = size; d >= 0; d--) {
      long long m = (l + r) / 2;
      if (!(mask & (1 << d))) {
        if (i <= m)
          r = m;
        else
          l = m + 1;
      } else {
        if (i <= m)
          i = i - l + m + 1, l = m + 1;
        else
          i = i - (m + 1) + l, r = m;
      }
    }
    i += (1 << size);
    seg[i] = val;
    while (i > 1) {
      i /= 2;
      seg[i] = (seg[i * 2] + seg[i * 2 + 1]);
    }
  }
  long long query(int a, int b, int k, int l, int r, int d) {
    if (a > b || a < 0 || b >= (1 << size)) return 0;
    if (b < l || r < a) return 0;
    if (a <= l && r <= b) return seg[k];
    if (!(mask & (1 << d))) {
      long long lval = query(a, b, k * 2, l, (l + r) / 2, d - 1);
      long long rval = query(a, b, k * 2 + 1, (l + r) / 2 + 1, r, d - 1);
      return (lval + rval);
    } else {
      if (a <= (l + r) / 2 && b >= (l + r) / 2 + 1) {
        long long lval =
            query(l, b - ((l + r) / 2 + 1) + l, k * 2, l, (l + r) / 2, d - 1);
        long long rval = query(a - l + ((l + r) / 2 + 1), r, k * 2 + 1,
                               (l + r) / 2 + 1, r, d - 1);
        return (lval + rval);
      } else if (b <= (l + r) / 2) {
        return query(a - l + ((l + r) / 2 + 1), b - l + ((l + r) / 2 + 1),
                     k * 2 + 1, (l + r) / 2 + 1, r, d - 1);
      } else if (a >= (l + r) / 2 + 1) {
        return query(a - ((l + r) / 2 + 1) + l, b - ((l + r) / 2 + 1) + l,
                     k * 2, l, (l + r) / 2, d - 1);
      }
    }
  }
  long long query(int a, int b) {
    return query(a, b, 1, 0, (1 << size) - 1, size);
  }
};
long long n, Q;
long long a[1 << 18];
SegTree seg(18);
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> Q;
  long long N = 1 << n;
  for (int i = 0; i < N; i++) cin >> a[i];
  seg.init();
  for (int i = 0; i < N; i++) seg.update(i, a[i]);
  long long t, x, k, l, r;
  for (int q = 0; q < Q; q++) {
    cin >> t;
    if (t == 1) {
      cin >> x >> k;
      x--;
      seg.update(x, k);
    }
    if (t == 2) {
      cin >> k;
      for (int j = 0; j <= k; j++) mask ^= 1 << j;
    }
    if (t == 3) {
      cin >> k;
      mask ^= 1 << (k + 1);
    }
    if (t == 4) {
      cin >> l >> r;
      l--, r--;
      cout << seg.query(l, r) << "\n";
    }
  }
  flush(cout);
  return 0;
}
