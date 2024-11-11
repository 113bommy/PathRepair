#include <bits/stdc++.h>
#pragma comment(linker, "/STACK: 1024000000,1024000000")
using namespace std;
inline int getint() {
  int _x = 0;
  char _tc = getchar();
  while (_tc < '0' || _tc > '9') _tc = getchar();
  while (_tc >= '0' && _tc <= '9') _x *= 10, _x += (_tc - '0'), _tc = getchar();
  return _x;
}
const int N = 1e6 + 35;
const int NN = N * 4;
int lazy[NN], mx[NN], a[N], b[N];
void push_down(int rt) {
  if (lazy[rt]) {
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    mx[rt << 1] += lazy[rt];
    mx[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
  }
}
void push_up(int rt) { mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]); }
void update(int rt, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R) {
    lazy[rt] += v;
    mx[rt] += v;
    return;
  }
  int mid = l + r >> 1;
  push_down(rt);
  if (L <= mid) update(rt << 1, l, mid, L, R, v);
  if (R > mid) update(rt << 1 | 1, mid + 1, r, L, R, v);
  push_up(rt);
}
int query(int rt, int l, int r) {
  if (l == r) {
    return l;
  }
  push_down(rt);
  int mid = l + r >> 1;
  if (mx[rt << 1 | 1] > 0) return query(rt << 1 | 1, mid + 1, r);
  return query(rt << 1, l, mid);
}
int main() {
  int n, m, q;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), update(1, 1, N, 1, a[i], 1);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]), update(1, 1, N, 1, b[i], -1);
  scanf("%d", &q);
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      update(1, 1, N, 1, a[x], -1);
      a[x] = y;
      update(1, 1, N, 1, a[x], 1);
    } else {
      update(1, 1, N, 1, b[x], 1);
      b[x] = y;
      update(1, 1, N, 1, b[x], -1);
    }
    if (mx[1] <= 0)
      puts("-1");
    else
      printf("%d\n", query(1, 1, N));
  }
  return 0;
}
