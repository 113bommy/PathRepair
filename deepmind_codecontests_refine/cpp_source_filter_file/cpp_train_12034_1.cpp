#include <bits/stdc++.h>
using namespace std;
int a[100010];
long long sum[10][400010], to[10][400010];
void pushup(int rt) {
  int i;
  for (i = 1; i <= 9; ++i) sum[i][rt] = sum[i][rt << 1] + sum[i][rt << 1 | 1];
}
void build(int l, int r, int rt) {
  int i;
  for (i = 0; i <= 9; ++i) to[i][rt] = i;
  if (l == r) {
    long long mul = 1;
    while (mul <= a[l]) {
      sum[a[l] / mul % 10][rt] += mul;
      mul = mul * 10;
    }
    return;
  }
  int m = l + r >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  pushup(rt);
}
void pushdown(int rt) {
  int i;
  long long tmp[10];
  for (i = 0; i < 10; ++i) tmp[i] = 0;
  for (i = 0; i < 10; ++i) tmp[to[i][rt]] += sum[i][rt << 1];
  for (i = 0; i < 10; ++i) sum[i][rt << 1] = tmp[i];
  for (i = 0; i < 10; ++i) to[i][rt << 1] = to[to[i][rt << 1]][rt];
  for (i = 0; i < 10; ++i) tmp[i] = 0;
  for (i = 0; i < 10; ++i) tmp[to[i][rt]] += sum[i][rt << 1 | 1];
  for (i = 0; i < 10; ++i) sum[i][rt << 1 | 1] = tmp[i];
  for (i = 0; i < 10; ++i) to[i][rt << 1 | 1] = to[to[i][rt << 1 | 1]][rt];
  for (i = 0; i < 10; ++i) to[i][rt] = i;
}
void update(int L, int R, int x, int y, int l, int r, int rt) {
  int i;
  if (L <= l && r <= R) {
    if (x != y) {
      sum[y][rt] += sum[x][rt];
      sum[x][rt] = 0;
    }
    for (i = 0; i < 10; ++i) {
      if (to[i][rt] == x) to[i][rt] = y;
    }
    return;
  }
  int m = l + r >> 1;
  pushdown(rt);
  if (m >= L) update(L, R, x, y, l, m, rt << 1);
  if (m < R) update(L, R, x, y, m + 1, r, rt << 1 | 1);
  pushup(rt);
}
long long query(int L, int R, int l, int r, int rt) {
  int i;
  if (L <= l && r <= R) {
    long long rv = 0;
    for (i = 0; i < 10; ++i) {
      rv += i * sum[i][rt];
    }
    return rv;
  }
  int m = l + r >> 1;
  pushdown(rt);
  long long ans = 0;
  if (m >= L) ans += query(L, R, l, m, rt << 1);
  if (m < R) ans += query(L, R, m + 1, r, rt << 1 | 1);
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int i;
  for (i = 1; i <= n; ++i) cin >> a[i];
  build(1, n, 1);
  int op, l, r, x, y;
  for (i = 0; i < m; ++i) {
    cin >> op >> l >> r;
    if (op == 1) {
      cin >> x >> y;
      update(l, r, x, y, 1, n, 1);
    } else
      cout << query(l, r, 1, n, 1) << '\n';
  }
  return 0;
}
