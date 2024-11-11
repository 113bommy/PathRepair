#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
struct Tree {
  int rt[N + 5], sum[N * 40], ls[N * 40], rs[N * 40], cnt;
  void ins(int& k, int y, int l, int r, int pos) {
    k = ++cnt;
    sum[k] = sum[y] + 1;
    ls[k] = ls[y];
    rs[k] = rs[y];
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid)
      ins(ls[k], ls[y], l, mid, pos);
    else
      ins(rs[k], rs[y], mid + 1, r, pos);
  }
  int BS(int k, int l, int r, int b) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (sum[rs[k]] >= b) return BS(rs[k], mid + 1, r, b);
    return BS(ls[k], l, mid, b - sum[rs[k]]);
  }
  int query(int k, int l, int r, int ql, int qr) {
    if (!k) return 0;
    if (ql <= l && qr >= r) return sum[k];
    int mid = (l + r) >> 1;
    int res = 0;
    if (ql <= mid) res += query(ls[k], l, mid, ql, qr);
    if (qr > mid) res += query(rs[k], mid + 1, r, ql, qr);
    return res;
  }
  Tree() {}
} T;
int n, q, g[N], a[N], b[N];
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i < a[i]) {
      T.rt[i] = T.rt[i - 1];
      b[i] = g[i] = -1;
      continue;
    }
    b[i] = i - a[i];
    if (T.sum[T.rt[i - 1]] < b[i]) {
      T.rt[i] = T.rt[i - 1];
      g[i] = -1;
      continue;
    }
    if (!b[i])
      g[i] = i - 1;
    else
      g[i] = T.BS(T.rt[i - 1], 0, n - 1, b[i]);
    T.ins(T.rt[i], T.rt[i - 1], 0, n - 1, g[i]);
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << T.query(T.rt[n - y], 0, n - 1, x, n - 1) << endl;
  }
  return 0;
}
