#include <bits/stdc++.h>
using namespace std;
const int N5 = 1e5 + 15;
int n, m, sz, y[N5], x[N5], t[N5 << 2], a[N5], b[N5], type;
void upd(int v, int tl, int tr, int l, int r, int x) {
  if (l <= tl && tr <= r) {
    t[v] = x;
    return;
  }
  int tm = (tl + tr) >> 1;
  if (l <= tm) upd(v << 1, tl, tm, l, r, x);
  if (r > tm) upd(v << 1 | 1, tm + 1, tr, l, r, x);
}
int get(int v, int tl, int tr, int x) {
  if (tl == tr) return t[v];
  int tm = (tl + tr) >> 1;
  if (x < tm)
    return max(t[v], get(v << 1, tl, tm, x));
  else
    return max(t[v], get(v << 1 | 1, tm + 1, tr, x));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &type, &x[i]);
    if (type == 1) {
      scanf("%d%d", &y[i], &sz);
      upd(1, 1, n, y[i], y[i] + sz - 1, i);
    } else {
      int p = x[i];
      int ind = get(1, 1, n, p);
      printf("%d\n", ind ? a[p + x[ind] - y[ind]] : b[p]);
    }
  }
}
