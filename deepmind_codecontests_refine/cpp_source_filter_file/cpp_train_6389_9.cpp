#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 11;
int _max(int x, int y) { return x > y ? x : y; }
int _min(int x, int y) { return x < y ? x : y; }
int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * f;
}
struct node {
  int x, p;
} pp[20];
int plen;
struct tnode {
  int lc, rc, l, r, c[2];
} t[410000];
int cnt;
int pos[210000];
int a[210000];
bool cmp1(node a, node b) { return a.p < b.p; }
bool cmp2(node a, node b) { return a.x < b.x; }
int lowbit(int x) { return x & -x; }
void cpos(int x, int c) {
  for (int i = x; i <= maxn; i += lowbit(i)) pos[i] += c;
}
int findkth(int k) {
  int now = 0, sum = 0;
  for (int i = 18; i >= 0; i--) {
    if ((now + (1 << i)) < maxn && sum + pos[now + (1 << i)] < k)
      now += (1 << i), sum += pos[k];
  }
  return now + 1;
}
void bt(int l, int r) {
  int now = ++cnt;
  t[now].l = l, t[now].r = r;
  t[now].lc = t[now].rc = -1;
  if (l < r) {
    int mid = (l + r) / 2;
    t[now].lc = cnt + 1;
    bt(l, mid);
    t[now].rc = cnt + 1;
    bt(mid + 1, r);
  }
}
void change(int now, int p, int c, int opt) {
  if (t[now].l == t[now].r) {
    t[now].c[opt] = c;
    return;
  }
  int mid = (t[now].l + t[now].r) / 2;
  if (p <= mid)
    change(t[now].lc, p, c, opt);
  else
    change(t[now].rc, p, c, opt);
  t[now].c[opt] = _max(t[t[now].lc].c[opt], t[t[now].rc].c[opt]);
}
int findmax(int now, int l, int r, int opt) {
  if (t[now].l == l && t[now].r == r) {
    return t[now].c[opt];
  }
  int mid = (t[now].l + t[now].r) / 2;
  if (r <= mid)
    return findmax(t[now].lc, l, r, opt);
  else if (l > mid)
    return findmax(t[now].rc, l, r, opt);
  else
    return _max(findmax(t[now].lc, l, mid, opt),
                findmax(t[now].rc, mid + 1, r, opt));
}
int main() {
  int n = read(), m = read();
  bt(1, maxn);
  plen = 0;
  for (int i = 1; i <= m; i++) {
    int opt = read(), p, h, now = 0;
    for (int j = 1; j <= plen; j++) {
      if (pp[j].x + i <= 10) pp[++now] = pp[j];
    }
    plen = now;
    if (opt == 1) {
      p = read(), h = read();
      a[p] = h - i + m;
      for (int j = 1; j <= plen; j++)
        if (pp[j].x + i < h) {
          change(1, pp[j].p, 0, 0);
          change(1, pp[j].x + m, 0, 1);
        }
      int hh = findmax(1, p + 1, n + 1, 0) + 1;
      change(1, p, hh, 0), change(1, h + m - i, hh, 1);
      sort(pp + 1, pp + plen + 1, cmp1);
      for (int j = plen; j >= 1; j--)
        if (pp[j].x + i < h) {
          hh = findmax(1, pp[j].p + 1, n + 1, 0) + 1;
          change(1, pp[j].p, hh, 0), change(1, pp[j].x + m, hh, 1);
        }
      pp[++plen].p = p, pp[plen].x = h - i;
      cpos(p, 1);
      printf("%d\n", findmax(1, 1, n + 1, 0));
    } else {
      int p = read();
      for (int j = 1; j < p; j++) {
        int u = findkth(j);
        change(1, u, 0, 0);
        change(1, a[u], 0, 1);
      }
      int q = findkth(p);
      cpos(q, -1);
      change(1, q, 0, 0);
      change(1, a[q], 0, 1);
      a[q] = 0;
      int now = 0;
      for (int j = 1; j <= plen; j++)
        if (pp[j].p != q) pp[++now] = pp[j];
      plen = now;
      for (int j = p - 1; j >= 1; j--) {
        int u = findkth(j);
        int hh = findmax(1, a[u] + 1, maxn, 1) + 1;
        change(1, u, hh, 0), change(1, a[u], hh, 1);
      }
      printf("%d\n", findmax(1, 1, n + 1, 0));
    }
  }
  return 0;
}
