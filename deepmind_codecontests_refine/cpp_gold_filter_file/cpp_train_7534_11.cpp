#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005], b[100005], x[100005], y[100005], st[400005];
int update(int l, int r, int ind, int qs, int qe, int si) {
  if (l > qe || r < qs) return 0;
  if (l >= qs && r <= qe) {
    st[si] = ind;
    return 0;
  }
  int mid = (l + r) / 2;
  update(l, mid, ind, qs, qe, 2 * si + 1);
  update(mid + 1, r, ind, qs, qe, 2 * si + 2);
}
int query(int l, int r, int pos, int si) {
  if (l == r) return st[si];
  int ret = 0;
  int mid = (l + r) / 2;
  if (pos <= mid)
    ret = max(st[si], query(l, mid, pos, 2 * si + 1));
  else
    ret = max(st[si], query(mid + 1, r, pos, 2 * si + 2));
  return ret;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  int t, k, v;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d %d", &x[i], &y[i], &k);
      x[i]--;
      y[i]--;
      update(0, n - 1, i, y[i], y[i] + k - 1, 0);
    } else {
      scanf("%d", &v);
      v--;
      int q = query(0, n - 1, v, 0);
      if (q == 0)
        printf("%d\n", b[v]);
      else
        printf("%d\n", a[x[q] + v - y[q]]);
    }
  }
}
