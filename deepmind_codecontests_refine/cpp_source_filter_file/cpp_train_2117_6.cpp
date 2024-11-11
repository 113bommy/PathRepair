#include <bits/stdc++.h>
using namespace std;
int n, m, ans[100005], d[100005], dd[100005], tot;
pair<int, int> c[100005 * 2];
struct Tnode {
  int s, t, f;
} a[100005];
struct node {
  int l, r, b;
} b[100005];
set<pair<int, int> > tree[100005 * 4];
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i].s, &a[i].f, &a[i].t);
  for (int i = 1; i <= m; i++) scanf("%d%d%d", &b[i].l, &b[i].r, &b[i].b);
}
void ins(int step, int l, int r, int s, int t, int num) {
  tree[step].insert(make_pair(t, num));
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (s <= mid)
    ins(step << 1, l, mid, s, t, num);
  else
    ins(step << 1 | 1, mid + 1, r, s, t, num);
}
void del(int step, int l, int r, int s, int t, int num) {
  tree[step].erase(make_pair(t, num));
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (s <= mid)
    del(step << 1, l, mid, s, t, num);
  else
    del(step << 1 | 1, mid + 1, r, s, t, num);
}
int query(int step, int l, int r, int ll, int rr, int x) {
  if (ll <= l && rr >= r) {
    set<pair<int, int> >::iterator p =
        tree[step].lower_bound(make_pair(b[x].b, 0));
    if (p == tree[step].end())
      return -1;
    else
      return (*p).second;
  }
  int mid = (l + r) >> 1, t1 = -1, t2 = -1;
  if (ll <= mid) t1 = query(step << 1, l, mid, ll, rr, x);
  if (rr > mid) t2 = query(step << 1 | 1, mid + 1, r, ll, rr, x);
  if (t1 == -1)
    return t2;
  else if (t2 == -1)
    return t1;
  else if (b[t1].b < b[t2].b)
    return t1;
  else
    return t2;
}
int bsearch(int x) {
  int l, r, mid;
  if (d[1] > x) return 0;
  l = 1;
  r = tot;
  while (l < r) {
    mid = (l + r + 1) >> 1;
    if (d[mid] > x)
      r = mid - 1;
    else
      l = mid;
  }
  return l;
}
void work() {
  int i, j, k, x;
  for (i = 1; i <= n; i++) dd[i] = a[i].s;
  sort(dd + 1, dd + n + 1);
  d[1] = dd[1];
  tot = 1;
  for (i = 2; i <= n; i++)
    if (dd[i] != dd[i - 1]) d[++tot] = dd[i];
  for (i = 1; i <= n; i++)
    ins(1, 1, tot, lower_bound(d + 1, d + tot + 1, a[i].s) - d, a[i].t, i);
  for (i = 1; i <= n; i++) c[i] = make_pair(a[i].f, i + m);
  for (i = 1; i <= m; i++) c[i + n] = make_pair(b[i].r, i);
  sort(c + 1, c + n + m + 1);
  for (i = 1; i <= n + m; i++)
    if (c[i].second > m)
      del(1, 1, tot, lower_bound(d + 1, d + tot + 1, a[c[i].second - m].s) - d,
          a[c[i].second - m].t, c[i].second - m);
    else {
      x = bsearch(b[c[i].second].l);
      if (x)
        ans[c[i].second] = query(1, 1, tot, 1, x, c[i].second);
      else
        ans[c[i].second] = -1;
    }
  for (i = 1; i < m; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[m]);
}
int main() {
  init();
  work();
  return 0;
}
