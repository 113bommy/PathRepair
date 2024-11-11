#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 7, M = 33;
int n, d, Q, lim;
int a[M], Max[N << 2][M];
int qread() {
  int x = 0, j = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') j = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * j;
}
void PushUp(int rt) {
  for (int i = 0; i <= lim; i++)
    Max[rt][i] = max(Max[rt << 1][i], Max[rt << 1 | 1][i]);
}
void Build(int l, int r, int rt) {
  if (l == r) {
    for (int i = 1; i <= d; i++) a[i] = qread();
    for (int i = 0; i <= lim; i++)
      for (int j = 1; j <= d; j++)
        if (i & (1 << j - 1))
          Max[rt][i] += a[j];
        else
          Max[rt][i] -= a[j];
    return;
  }
  int mid = l + r >> 1;
  Build(l, mid, rt << 1);
  Build(mid + 1, r, rt << 1 | 1);
  PushUp(rt);
}
void Modify(int l, int r, int rt, int p) {
  if (l == r) {
    for (int i = 1; i <= d; i++) a[i] = qread();
    for (int i = 0; i <= lim; i++) Max[rt][i] = 0;
    for (int i = 0; i <= lim; i++)
      for (int j = 1; j <= d; j++)
        if (i & (1 << j - 1))
          Max[rt][i] += a[j];
        else
          Max[rt][i] -= a[j];
    return;
  }
  int mid = l + r >> 1;
  if (p <= mid)
    Modify(l, mid, rt << 1, p);
  else
    Modify(mid + 1, r, rt << 1 | 1, p);
  PushUp(rt);
}
int Query(int l, int r, int rt, int nowl, int nowr, int p) {
  if (nowl <= l && r <= nowr) return Max[rt][p];
  int mid = l + r >> 1, res = -INF;
  if (nowl <= mid) res = Query(l, mid, rt << 1, nowl, nowr, p);
  if (mid < nowr) res = max(res, Query(mid + 1, r, rt << 1 | 1, nowl, nowr, p));
  return res;
}
int main() {
  scanf("%d%d", &n, &d);
  lim = (1 << d) - 1;
  Build(1, n, 1);
  scanf("%d", &Q);
  int p, l, r;
  while (Q--) {
    p = qread();
    l = qread();
    if (p == 1)
      Modify(1, n, 1, l);
    else {
      r = qread();
      int ans = 0;
      for (int i = 0; i <= lim; i++) a[i] = Query(1, n, 1, l, r, i);
      for (int i = 0; i <= lim; i++) ans = max(ans, a[i] + a[lim - i]);
      printf("%d\n", ans);
    }
  }
  return 0;
}
