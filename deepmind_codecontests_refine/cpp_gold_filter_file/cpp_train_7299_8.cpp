#include <bits/stdc++.h>
using namespace std;
int n, m, k, ct, va[300010 << 6], lc[300010 << 6], rc[300010 << 6], rt[300010];
struct no {
  int l, r, v;
} a[300010];
int operator<(no x, no y) { return x.l > y.l; }
void ins(int &o, int p, int l, int r, int x, int y) {
  if (!o) o = ++ct;
  if (l == r) {
    va[o] = min(va[p], y);
    return;
  }
  int md = (l + r) / 2;
  if (x <= md) {
    rc[o] = rc[p];
    ins(lc[o], lc[p], l, md, x, y);
  } else {
    lc[o] = lc[p];
    ins(rc[o], rc[p], md + 1, r, x, y);
  }
  va[o] = max(va[lc[o]], va[rc[o]]);
}
int q(int o, int l, int r, int x, int y) {
  if (r < x || y < l) return -2e9;
  if (x <= l && r <= y) return va[o];
  int md = (l + r) / 2;
  return max(q(lc[o], l, md, x, y), q(rc[o], md + 1, r, x, y));
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].v);
  sort(a + 1, a + k + 1);
  memset(va, 127, sizeof(va));
  for (int i = 1; i <= k; i++) ins(rt[i], rt[i - 1], 1, n, a[i].v, a[i].r);
  while (m--) {
    int c, d, x, y;
    scanf("%d%d%d%d", &c, &d, &x, &y);
    int l = 1, r = k, ans = -1;
    while (l <= r) {
      int md = (l + r) / 2;
      if (a[md].l >= x)
        l = md + 1, ans = md;
      else
        r = md - 1;
    }
    int v = q(rt[ans], 1, n, c, d);
    printf("%s\n", v <= y ? "yes" : "no");
    fflush(stdout);
  }
}
