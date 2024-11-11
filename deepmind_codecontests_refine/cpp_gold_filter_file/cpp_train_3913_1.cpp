#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, h[100005], fa[100005], cnt, rt, in[100005], siz[100005], rt1[100005];
int se[100005], mx[100005], mn[100005], out[100005], rt2[100005], ans[100005];
struct node {
  int to, next;
} e[100005 << 1];
int ls[100005 * 60], rs[100005 * 60], sum[100005 * 60], tot;
void Insert(int &p, int las, int l, int r, int x) {
  if (!p) p = ++tot;
  if (sum[p] = sum[las] + 1, l == r) return;
  int mid = (l + r) >> 1;
  if (x <= mid)
    rs[p] = rs[las], Insert(ls[p], ls[las], l, mid, x);
  else
    ls[p] = ls[las], Insert(rs[p], rs[las], mid + 1, r, x);
}
int Ask(int p1, int p2, int p3, int p4, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return sum[p1] - sum[p2] - sum[p3] + sum[p4];
  int mid = (l + r) >> 1;
  if (qr <= mid) return Ask(ls[p1], ls[p2], ls[p3], ls[p4], l, mid, ql, qr);
  if (ql > mid) return Ask(rs[p1], rs[p2], rs[p3], rs[p4], mid + 1, r, ql, qr);
  return Ask(ls[p1], ls[p2], ls[p3], ls[p4], l, mid, ql, qr) +
         Ask(rs[p1], rs[p2], rs[p3], rs[p4], mid + 1, r, ql, qr);
}
int Getpre(int p1, int p2, int p3, int p4, int l, int r, int x) {
  if (l == r) return l;
  int mid = (l + r) >> 1,
      tmp = sum[rs[p1]] - sum[rs[p2]] - sum[rs[p3]] + sum[rs[p4]];
  if (tmp <= x) return Getpre(ls[p1], ls[p2], ls[p3], ls[p4], l, mid, x - tmp);
  return Getpre(rs[p1], rs[p2], rs[p3], rs[p4], mid + 1, r, x);
}
int Getsuf(int p1, int p2, int p3, int p4, int l, int r, int x) {
  if (l == r) return l;
  int mid = (l + r) >> 1,
      tmp = sum[ls[p1]] - sum[ls[p2]] - sum[ls[p3]] + sum[ls[p4]];
  if (tmp <= x)
    return Getsuf(rs[p1], rs[p2], rs[p3], rs[p4], mid + 1, r, x - tmp);
  return Getsuf(ls[p1], ls[p2], ls[p3], ls[p4], l, mid, x);
}
inline int read() {
  int s = 0, f = 0;
  char ch = getchar();
  while (ch < 48 || ch > 57) f = (ch == '-'), ch = getchar();
  while (ch > 47 && ch < 58)
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return f ? -s : s;
}
void Addedge(int x, int y) {
  e[++cnt] = (node){y, h[x]}, h[x] = cnt;
  e[++cnt] = (node){x, h[y]}, h[y] = cnt;
}
void Dfs(int x, int p) {
  siz[x] = 1, fa[x] = p, in[x] = ++cnt;
  for (int i = h[x], y; i; i = e[i].next)
    if ((y = e[i].to) != p) {
      Dfs(e[i].to, x), siz[x] += siz[y];
      if (!mn[x] || siz[y] < mn[x]) mn[x] = siz[y];
      if (siz[y] > siz[mx[x]])
        se[x] = mx[x], mx[x] = y;
      else if (siz[y] > siz[se[x]])
        se[x] = y;
    }
  if (out[x] = cnt, x != rt) {
    if (!mn[x] || n - siz[x] < mn[x]) mn[x] = n - siz[x];
    if (n - siz[x] > siz[mx[x]])
      se[x] = mx[x], mx[x] = n + 1;
    else if (n - siz[x] > siz[se[x]])
      se[x] = n + 1;
  }
}
void Dfs2(int x) {
  Insert(rt1[x], rt1[fa[x]], 1, n, siz[x]);
  Insert(rt2[in[x]], rt2[in[x] - 1], 1, n, siz[x]);
  for (int i = h[x]; i; i = e[i].next)
    if (e[i].to != fa[x]) Dfs2(e[i].to);
}
void Solve(int x) {
  if (!se[x])
    ans[x] = (mx[x] == n + 1) ? n - 1 : siz[mx[x]];
  else {
    int mid = (siz[mx[x]] - mn[x]) >> 1, tmp, tt, Tmp = inf;
    if (mx[x] == n + 1) {
      mid = n - siz[x] - mn[x] >> 1;
      tt = (mid < n) ? Ask(rt2[n], rt1[fa[x]], rt2[out[x]], rt2[in[x] - 1], 1,
                           n, mid + 1, n)
                     : 0;
      tmp = Getpre(rt2[n], rt1[fa[x]], rt2[out[x]], rt2[in[x] - 1], 1, n, tt),
      Tmp = min(Tmp, max(tmp + mn[x], n - siz[x] - tmp));
      tt = (mid + siz[x] < n)
               ? Ask(rt1[fa[x]], 0, 0, 0, 1, n, mid + siz[x] + 1, n)
               : 0;
      tmp = Getpre(rt1[fa[x]], 0, 0, 0, 1, n, tt),
      Tmp = min(Tmp, max(tmp - siz[x] + mn[x], n - tmp));
      tt = (mid > 1) ? Ask(rt2[n], rt1[fa[x]], rt2[out[x]], rt2[in[x] - 1], 1,
                           n, 1, mid - 1)
                     : 0;
      tmp = Getsuf(rt2[n], rt1[fa[x]], rt2[out[x]], rt2[in[x] - 1], 1, n, tt),
      Tmp = min(Tmp, max(tmp + mn[x], n - siz[x] - tmp));
      tt = (mid + siz[x] > 1)
               ? Ask(rt1[fa[x]], 0, 0, 0, 1, n, 1, mid + siz[x] - 1)
               : 0;
      tmp = Getsuf(rt1[fa[x]], 0, 0, 0, 1, n, tt),
      Tmp = min(Tmp, max(tmp - siz[x] + mn[x], n - tmp));
    } else {
      if (!mid)
        Tmp = siz[mx[x]];
      else {
        tt = (mid < n) ? Ask(rt2[out[mx[x]]], rt2[in[mx[x]] - 1], 0, 0, 1, n,
                             mid + 1, n)
                       : 0;
        tmp = Getpre(rt2[out[mx[x]]], rt2[in[mx[x]] - 1], 0, 0, 1, n, tt),
        Tmp = min(Tmp, max(tmp + mn[x], siz[mx[x]] - tmp));
        tt = (mid > 1) ? Ask(rt2[out[mx[x]]], rt2[in[mx[x]] - 1], 0, 0, 1, n, 1,
                             mid - 1)
                       : 0;
        tmp = Getsuf(rt2[out[mx[x]]], rt2[in[mx[x]] - 1], 0, 0, 1, n, tt),
        Tmp = min(Tmp, max(tmp + mn[x], siz[mx[x]] - tmp));
      }
    }
    ans[x] = max(se[x] == n + 1 ? n - siz[x] : siz[se[x]], Tmp);
  }
  for (int i = h[x]; i; i = e[i].next)
    if (e[i].to != fa[x]) Solve(e[i].to);
}
int main() {
  n = read();
  for (int i = 1, x, y; i <= n; ++i) {
    if (x = read(), y = read(), x && y)
      Addedge(x, y);
    else
      rt = x | y;
  }
  Dfs(rt, cnt = 0), Dfs2(rt), Solve(rt);
  for (int i = 1; i <= n; ++i) cout << ans[i] << "\n";
  return 0;
}
