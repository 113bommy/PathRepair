#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
struct tnode1 {
  int l, r, ls, rs, v, d;
} t[800001];
struct tnode2 {
  int ls, rs, v;
} s[5000001];
struct data {
  int n, l, r;
} b[600001];
int mv, i, j, k, n, m, sz, tot, a[200001], ans[600001];
bool cmp(data a, data b) { return a.r < b.r; }
void mt(int l, int r) {
  int m, p = ++tot;
  t[p].l = l;
  t[p].r = r;
  t[p].v = t[p].d = inf;
  if (l < r) {
    m = (l + r) >> 1;
    t[p].ls = tot + 1;
    mt(l, m);
    t[p].rs = tot + 1;
    mt(m + 1, r);
  } else
    t[p].ls = t[p].rs = 0;
}
void down(int p) {
  if (t[p].d == inf) return;
  t[p].v = min(t[p].v, t[p].d);
  if (t[p].ls) {
    t[t[p].ls].d = min(t[t[p].ls].d, t[p].d);
    t[t[p].rs].d = min(t[t[p].rs].d, t[p].d);
  }
  t[p].d = inf;
}
void change1(int p, int l, int r, int v) {
  down(p);
  if (l <= t[p].l && t[p].r <= r) {
    t[p].d = v;
    return;
  }
  int m = (t[p].l + t[p].r) >> 1;
  if (l <= m) change1(t[p].ls, l, r, v);
  if (r >= m + 1) change1(t[p].rs, l, r, v);
  down(t[p].ls);
  down(t[p].rs);
  t[p].v = min(t[t[p].ls].v, t[t[p].rs].v);
}
int query1(int p, int x) {
  down(p);
  if (!t[p].ls) return t[p].v;
  int m = (t[p].l + t[p].r) >> 1, res;
  res = query1((x <= m) ? t[p].ls : t[p].rs, x);
  down(t[p].ls);
  down(t[p].rs);
  t[p].v = min(t[t[p].ls].v, t[t[p].rs].v);
  return res;
}
void change2(int &p, int x, int v, int lc, int rc) {
  if (!p) {
    p = ++sz;
    s[p].ls = s[p].rs = s[p].v = 0;
  }
  s[p].v = max(v, s[p].v);
  if (lc == rc) return;
  int m = (lc + rc) >> 1;
  if (x <= m)
    change2(s[p].ls, x, v, lc, m);
  else
    change2(s[p].rs, x, v, m + 1, rc);
}
int query2(int p, int l, int r, int lc, int rc) {
  if (!p) return 0;
  if (l <= lc && rc <= r) return s[p].v;
  int m = (lc + rc) >> 1, res = 0;
  if (l <= m) res = query2(s[p].ls, l, r, lc, m);
  if (r >= m + 1) res = max(res, query2(s[p].rs, l, r, m + 1, rc));
  return res;
}
void work() {
  int i, j, k, rt = 0;
  tot = sz = 0;
  sort(b + 1, b + 1 + m, cmp);
  mt(1, n);
  for (i = j = 1; i <= n; i++) {
    k = query2(rt, a[i], mv, 1, mv);
    while (k) {
      change1(1, 1, k, a[k] - a[i]);
      if (a[i] <= (a[i] + a[k]) / 2 - 1 + (a[i] + a[k]) % 2)
        k = query2(rt, a[i], (a[i] + a[k]) / 2 - 1 + (a[i] + a[k]) % 2, 1, mv);
      else
        break;
    }
    change2(rt, a[i], i, 1, mv);
    for (; j <= m && b[j].r == i; j++)
      ans[b[j].n] = min(ans[b[j].n], query1(1, b[j].l));
  }
}
int main() {
  scanf("%d", &n);
  for (i = 1, mv = 0; i <= n; i++) scanf("%d", &a[i]), mv = max(mv, a[i]);
  scanf("%d", &m);
  for (i = 1; i <= m; i++)
    scanf("%d%d", &b[i].l, &b[i].r), b[i].n = i, ans[i] = inf;
  work();
  for (i = 1; i <= n / 2; i++) swap(a[i], a[n - i + 1]);
  for (i = 1; i <= m; i++)
    j = b[i].l, k = b[i].r, b[i].l = n - k + 1, b[i].r = n - j + 1;
  work();
  for (i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
