#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
long long sum[maxn << 2];
long long add[maxn << 2];
long long a[maxn];
int n, m;
int col[maxn << 2];
void push_up(int rt) {
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
  if (col[rt << 1] && col[rt << 1] == col[rt << 1 | 1])
    col[rt] = col[rt << 1];
  else
    col[rt] = 0;
}
void push_down(int rt, int mid) {
  if (add[rt]) {
    add[rt << 1] += add[rt];
    add[rt << 1 | 1] += add[rt];
    col[rt << 1] = col[(rt << 1) | 1] = col[rt];
    sum[rt << 1] += add[rt] * (mid - (mid >> 1));
    sum[rt << 1 | 1] += add[rt] * (mid >> 1);
    add[rt] = 0;
  }
}
void build(int l, int r, int rt) {
  if (l == r) {
    col[rt] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  push_up(rt);
  return;
}
void update(int L, int R, long long c, int l, int r, int rt) {
  if (L <= l && r <= R && col[rt]) {
    add[rt] += abs(col[rt] - c);
    sum[rt] += (long long)abs(col[rt] - c) * (r - l + 1);
    col[rt] = c;
    return;
  }
  push_down(rt, r - l + 1);
  int mid = (l + r) >> 1;
  if (L <= mid) update(L, R, c, l, mid, rt << 1);
  if (R > mid) update(L, R, c, mid + 1, r, rt << 1 | 1);
  push_up(rt);
  return;
}
long long query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) return sum[rt];
  push_down(rt, r - l + 1);
  int mid = (l + r) >> 1;
  long long ans = 0;
  if (L <= mid) ans += query(L, R, l, mid, rt << 1);
  if (R > mid) ans += query(L, R, mid + 1, r, rt << 1 | 1);
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  memset(col, 0, sizeof(col));
  build(1, n, 1);
  int op, l, r;
  long long x;
  while (m--) {
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      scanf("%lld", &x);
      update(l, r, x, 1, n, 1);
    } else {
      printf("%lld\n", query(l, r, 1, n, 1));
    }
  }
}
