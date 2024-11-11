#include <bits/stdc++.h>
using namespace std;
int a[4][4], w[77780];
long long f[77780][4], nt[77780][4][4];
struct node {
  int l, r, ls, rs;
  long long w;
};
struct segtree {
  node tr[77780];
  void up(int rt) { tr[rt].w = tr[tr[rt].ls].w * tr[tr[rt].rs].w % 777777777; }
  void mk(int rt) {
    int l = tr[rt].l, r = tr[rt].r, m = (l + r) >> 1;
    tr[rt].w = 1;
    if (l == r) return;
    tr[rt].ls = rt << 1;
    tr[tr[rt].ls].l = l;
    tr[tr[rt].ls].r = m;
    mk(tr[rt].ls);
    tr[rt].rs = rt << 1 | 1;
    tr[tr[rt].rs].l = m + 1;
    tr[tr[rt].rs].r = r;
    mk(tr[rt].rs);
  }
  void updt(int a, int b, int rt) {
    int l = tr[rt].l, r = tr[rt].r, m = (l + r) >> 1;
    if (l == r) {
      tr[rt].w = b;
      return;
    }
    if (a <= m)
      updt(a, b, tr[rt].ls);
    else
      updt(a, b, tr[rt].rs);
    up(rt);
  }
} tree;
set<int> st;
int main() {
  int i, j, k, s, n, q, v, t;
  scanf("%d %d", &n, &q);
  for (i = 1; i <= 3; ++i)
    for (j = 1; j <= 3; ++j) scanf("%d", &a[i][j]);
  a[0][1] = a[0][2] = a[0][3] = 1;
  for (s = 0; s <= 3; ++s) {
    memset(f, 0, sizeof(f));
    for (i = 1; i <= 3; ++i) f[1][i] = a[s][i];
    for (i = 1; i <= n; ++i) {
      for (j = 1; j <= 3; ++j)
        for (k = 1; k <= 3; ++k)
          if (a[j][k]) (f[i + 1][k] += f[i][j]) %= 777777777;
      for (j = 1; j <= 3; ++j) nt[i][s][j] = f[i + 1][j];
      nt[i][s][0] = (f[i][1] + f[i][2] + f[i][3]) % 777777777;
    }
  }
  for (i = 1; i <= 3; ++i) nt[0][0][i] = nt[0][i][0] = 1;
  for (i = 1; i <= 3; ++i)
    for (j = 1; j <= 3; ++j) nt[0][i][j] = a[i][j];
  tree.tr[1].l = 1;
  tree.tr[1].r = n + 1;
  tree.mk(1);
  tree.updt(1, nt[n][0][0], 1);
  st.insert(0);
  st.insert(n + 1);
  int l, r;
  while (q--) {
    scanf("%d %d", &v, &t);
    l = *(--st.lower_bound(v));
    r = *st.upper_bound(v);
    if (!w[v] && t) st.insert(v);
    if (w[v] && !t) st.erase(v);
    if (w[v]) {
      tree.updt(l + 1, nt[v - l - 1][w[l]][w[v]], 1);
      tree.updt(v + 1, nt[r - v - 1][w[v]][w[r]], 1);
    } else {
      tree.updt(l + 1, nt[r - l - 1][w[l]][w[r]], 1);
      tree.updt(v + 1, 1, 1);
    }
    w[v] = t;
    if (w[v]) {
      tree.updt(l + 1, nt[v - l - 1][w[l]][w[v]], 1);
      tree.updt(v + 1, nt[r - v - 1][w[v]][w[r]], 1);
    } else {
      tree.updt(l + 1, nt[r - l - 1][w[l]][w[r]], 1);
      tree.updt(v + 1, 1, 1);
    }
    printf("%lld\n", tree.tr[1].w);
  }
  return 0;
}
