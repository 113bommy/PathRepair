#include <bits/stdc++.h>
using namespace std;
const int N = 400100;
inline int read() {
  int x = 0, c = getchar(), f = 0;
  for (; c > '9' || c < '0'; f = c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  return f ? -x : x;
}
struct cqz {
  int r1, c1, r2, c2, i;
} q[N];
inline bool operator<(cqz i, cqz j) { return i.r2 < j.r2; }
int lg[N], st[22][N];
int a[N], top, sta[N], m, n, i, c1, c2, r1, r2, ans[N], k;
inline int abs(int x) { return x < 0 ? -x : x; }
inline int min(int x, int y) { return x < y ? x : y; }
inline int getst(int l, int r) {
  if (l > r) swap(l, r);
  int ln = r - l + 1, k;
  k = lg[ln];
  r = r - (1 << k) + 1;
  return min(st[k][l], st[k][r]);
}
inline int calc(int r1, int c1, int r2, int c2, int r) {
  int res = 0;
  c1 = min(c1, getst(r1, r));
  if (c1 < a[r]) res++;
  res += abs(r1 - r) + abs(r2 - r);
  res += abs(c2 - a[r]);
  return res;
}
inline int getpos(int l, int r, int k) {
  l--;
  while (l < r - 1)
    if (sta[l + r >> 1] <= k)
      r = l + r >> 1;
    else
      l = l + r >> 1;
  return r;
}
inline void getans(cqz x, int l, int r) {
  l--;
  r++;
  int res = 2e9, lm, rm, len, ls, rs;
  while (l < r - 10) {
    len = (r - l + 1);
    len /= 3;
    lm = l + len;
    rm = r - len;
    ls = calc(x.r1, x.c1, x.r2, x.c2, sta[lm]);
    rs = calc(x.r1, x.c1, x.r2, x.c2, sta[rm]);
    if (ls > rs)
      l = lm;
    else
      r = rm;
  }
  for (l++; l < r; l++) res = min(res, calc(x.r1, x.c1, x.r2, x.c2, sta[l]));
  ans[x.i] = min(ans[x.i], res);
}
int main() {
  n = read();
  for (i = 1; i <= n; i++) st[0][i] = a[i] = read();
  for (k = 0; k < 20; k++)
    for (i = 1; i <= n; i++) st[k + 1][i] = min(st[k][i], st[k][i + (1 << k)]);
  lg[0] = -1;
  for (i = 1; i <= n; i++) lg[i] = lg[i / 2] + 1;
  m = read();
  for (i = 1; i <= m; i++) {
    r1 = read();
    c1 = read();
    r2 = read();
    c2 = read();
    ans[i] = abs(r1 - r2) + 1 + c2;
    q[i] = (cqz){r1, c1, r2, c2, i};
  }
  sort(q + 1, q + m + 1);
  top = 0;
  k = 1;
  for (i = 1; i <= n; i++) {
    while (top && a[sta[top]] >= a[i]) top--;
    sta[++top] = i;
    for (; k <= m && q[k].r2 == i; k++)
      if (q[k].r1 <= r2) {
        int pos = lower_bound(sta, sta + top + 1, q[k].r1) - sta;
        getans(q[k], pos, top);
        getans(q[k], 1, pos - 1);
        int res = abs(q[k].r2 - q[k].r1);
        int mn = q[k].c1;
        mn = min(mn, getst(q[k].r1, q[k].r2));
        res += abs(mn - q[k].c2);
        ans[q[k].i] = min(ans[q[k].i], res);
      } else
        getans(q[k], 1, top);
  }
  top = 0;
  k = m;
  for (i = n; i; i--) {
    while (top && a[sta[top]] >= a[i]) top--;
    sta[++top] = i;
    for (; k > 0 && q[k].r2 == i; k--)
      if (q[k].r1 > r2) {
        int pos = getpos(1, top, q[k].r1);
        getans(q[k], pos, top);
        getans(q[k], 1, pos - 1);
        int res = abs(q[k].r2 - q[k].r1);
        int mn = q[k].c1;
        mn = min(mn, getst(q[k].r1, q[k].r2));
        res += abs(mn - q[k].c2);
        ans[q[k].i] = min(ans[q[k].i], res);
      } else
        getans(q[k], 1, top);
  }
  for (i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
