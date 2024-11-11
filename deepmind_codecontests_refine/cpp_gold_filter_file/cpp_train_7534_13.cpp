#include <bits/stdc++.h>
using namespace std;
int a[300003], b[300003];
struct segTree {
  int size;
  int lazy[300003], left[300003], right[300003];
  segTree(int all) {
    size = all;
    build(1, 1, size);
  }
  void build(int n, int l, int r) {
    left[n] = l;
    right[n] = r;
    lazy[n] = -1;
    if (l == r) {
      lazy[n] = -2;
      return;
    }
    int m = (l + r) / 2;
    build(2 * n, l, m);
    build(2 * n + 1, m + 1, r);
  }
  void propagate(int n) {
    if (lazy[n] != -1 && lazy[n] != -2) {
      lazy[2 * n] = lazy[n];
      lazy[2 * n + 1] = lazy[n] + left[2 * n + 1] - left[n];
      lazy[n] = -1;
    }
  }
  int query(int n, int l) {
    if (l > right[n] || l < left[n]) return -1;
    if (l <= left[n] && l >= right[n]) return lazy[n];
    propagate(n);
    int tmp = query(2 * n, l);
    if (tmp == -1)
      return query(2 * n + 1, l);
    else
      return tmp;
  }
  void update(int n, int l, int r, int x) {
    if (l > right[n] || r < left[n]) return;
    if (l <= left[n] && r >= right[n]) {
      lazy[n] = x + left[n] - l;
      return;
    }
    propagate(n);
    update(2 * n, l, r, x);
    update(2 * n + 1, l, r, x);
  }
};
segTree *sg;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  sg = new segTree(n);
  for (int i = 0; i < m; ++i) {
    int q, x, y, k;
    cin >> q;
    if (q == 1) {
      cin >> x >> y >> k;
      sg->update(1, y, y + k - 1, x);
    } else {
      cin >> k;
      int ans = sg->query(1, k);
      if (ans == -2)
        cout << b[k] << endl;
      else
        cout << a[ans] << endl;
    }
  }
  return 0;
}
