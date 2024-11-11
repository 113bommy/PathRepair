#include <bits/stdc++.h>
using namespace std;
int n, m, q, seq[100005], lst[100005][20], bit[100005], tg[10000005],
    vl[10000005], ls[10000005], rs[10000005], tt = 1, mini = 2E9;
int ask(int l, int r) {
  int t = bit[r - l + 1];
  return min(lst[l][t], lst[r - (1 << t) + 1][t]);
}
int qry(int l, int r) {
  if (r - l + 1 >= n) return mini;
  if ((l - 1) / n == (r - 1) / n)
    return ask((l - 1) % n + 1, (r - 1) % n + 1);
  else
    return min(ask((l - 1) % n + 1, n), ask(1, (r - 1) % n + 1));
}
void update(int t, int l, int r) {
  if (~tg[t])
    vl[t] = tg[t] ? tg[t] : qry(l, r);
  else
    vl[t] = min(vl[ls[t]], vl[rs[t]]);
}
void pushdown(int t, int l, int r, int d) {
  if (!ls[t]) ls[t] = ++tt;
  if (!rs[t]) rs[t] = ++tt;
  if (~tg[t]) {
    tg[ls[t]] = tg[t], update(ls[t], l, d);
    tg[rs[t]] = tg[t], update(rs[t], d + 1, r);
  }
}
void edt(int t, int l, int r, int x, int y, int v) {
  if (l == x && y == r)
    tg[t] = v;
  else {
    int d = (l + r) >> 1;
    pushdown(t, l, r, d), tg[t] = -1;
    if (y <= d)
      edt(ls[t], l, d, x, y, v);
    else if (x > d)
      edt(rs[t], d + 1, r, x, y, v);
    else
      edt(ls[t], l, d, x, d, v), edt(rs[t], d + 1, r, d + 1, y, v);
  }
  update(t, l, r);
}
int qry(int t, int l, int r, int x, int y) {
  if (l == x && y == r) return vl[t];
  int d = (l + r) >> 1;
  pushdown(t, l, r, d);
  if (y <= d)
    return qry(ls[t], l, d, x, y);
  else if (x > d)
    return qry(rs[t], d + 1, r, x, y);
  else
    return min(qry(ls[t], l, d, x, d), qry(rs[t], d + 1, r, d + 1, y));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", seq + i), lst[i][0] = seq[i], mini = min(mini, seq[i]);
  for (int i = 2; i <= n; ++i) bit[i] = bit[i >> 1] + 1;
  for (int j = 1; j < 20; ++j)
    for (int i = 1; i <= n; ++i)
      if (i + (1 << j) - 1 <= n)
        lst[i][j] = min(lst[i][j - 1], lst[i + (1 << j - 1)][j - 1]);
  for (scanf("%d", &q), update(1, 1, n * m); q--;) {
    static int k, l, r, v;
    scanf("%d%d%d", &k, &l, &r);
    if (k == 1)
      scanf("%d", &v), edt(1, 1, n * m, l, r, v);
    else
      printf("%d\n", qry(1, 1, n * m, l, r));
  }
}
