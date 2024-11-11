#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn], b[maxn], seg[maxn << 2], lazy[maxn << 2];
void pushdown(int rt) {
  if (lazy[rt] == 0) return;
  int &x = lazy[rt];
  lazy[(rt << 1)] += x;
  lazy[(rt << 1 | 1)] += x;
  seg[(rt << 1)] += x;
  seg[(rt << 1 | 1)] += x;
  x = 0;
}
void update(int l, int r, int rt, int L, int R, int x) {
  if (L <= l && R >= r) {
    seg[rt] += x;
    lazy[rt] += x;
    return;
  }
  pushdown(rt);
  int m = l + r >> 1;
  if (L <= m) update(l, m, (rt << 1), L, R, x);
  if (m + 1 <= R) update(m + 1, r, (rt << 1 | 1), L, R, x);
  seg[rt] = min(seg[(rt << 1)], seg[(rt << 1 | 1)]);
}
int query(int l, int r, int rt) {
  if (seg[rt] >= 0) return -1;
  if (l == r) return l;
  pushdown(rt);
  int m = l + r >> 1;
  if (seg[(rt << 1 | 1)] < 0)
    return query(m + 1, r, (rt << 1 | 1));
  else
    return query(l, m, (rt << 1));
}
int main() {
  int n, m, q;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i), update(1, maxn, 1, 1, a[i], -1);
  for (int i = 1; i <= m; i++)
    scanf("%d", b + i), update(1, maxn, 1, 1, b[i], 1);
  scanf("%d", &q);
  while (q--) {
    int op, p, x;
    scanf("%d%d%d", &op, &p, &x);
    if (op == 1) {
      update(1, maxn, 1, 1, a[p], 1);
      a[p] = x;
      update(1, maxn, 1, 1, a[p], -1);
    } else {
      update(1, maxn, 1, 1, b[p], -1);
      b[p] = x;
      update(1, maxn, 1, 1, b[p], 1);
    }
    printf("%d\n", query(1, maxn, 1));
  }
}
