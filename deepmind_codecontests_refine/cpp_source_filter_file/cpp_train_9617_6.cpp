#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, tot;
long long sum[N << 2], size[N << 2], dt[N << 2];
inline void pushup(int x) {
  sum[x] = sum[x << 1] + sum[x << 1 | 1];
  size[x] = size[x << 1] + size[x << 1 | 1];
}
inline void modify(int x, int c) {
  dt[x] += c;
  sum[x] += size[x] * c;
}
inline void pushdown(int x) {
  if (dt[x]) {
    modify(x << 1, dt[x]);
    modify(x << 1 | 1, dt[x]);
    dt[x] = 0;
  }
}
inline void build(int l, int r, int rt) {
  if (l == r) {
    size[rt] = 1;
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  pushup(rt);
}
inline void update_s(int L, int R, int c, int l, int r, int rt) {
  if (L <= l && r <= R) {
    modify(rt, c);
    return;
  }
  pushdown(rt);
  int mid = l + r >> 1;
  if (L <= mid) update_s(L, R, c, l, mid, rt << 1);
  if (mid < R) update_s(L, R, c, mid + 1, r, rt << 1 | 1);
  pushup(rt);
}
inline void update_d(int p, int c, int l, int r, int rt) {
  if (l == r) {
    sum[rt] = c;
    return;
  }
  pushdown(rt);
  int mid = l + r >> 1;
  if (p <= mid)
    update_d(p, c, l, mid, rt << 1);
  else
    update_d(p, c, mid + 1, r, rt << 1 | 1);
  pushup(rt);
}
int main() {
  scanf("%d", &n);
  tot = 1;
  build(1, N, 1);
  for (int i = 1; i <= n; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      update_s(1, x, y, 1, n, 1);
    } else if (op == 2) {
      int x;
      scanf("%d", &x);
      tot++;
      update_d(tot, x, 1, n, 1);
    } else {
      update_d(tot, 0, 1, n, 1);
      tot--;
    }
    printf("%lf\n", 1.0 * sum[1] / tot);
  }
  return 0;
}
