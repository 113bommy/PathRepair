#include <bits/stdc++.h>
using namespace std;
int a[500000 + 1], ans[500000 + 1], prv[500000 + 1], laspos[500000 + 1];
struct query {
  int l, r, id;
} qry[500000 + 1];
bool operator<(query x, query y) { return x.r < y.r; }
struct node {
  int l, r;
  pair<int, int> mn;
} nd[500000 << 2];
void bld(int l, int r, int p = 1) {
  nd[p].l = nd[p].mn.second = l;
  nd[p].r = r;
  if (l == r) return;
  int mid = l + r >> 1;
  bld(l, mid, p << 1);
  bld(mid + 1, r, p << 1 | 1);
}
void chg(int x, int v, int p = 1) {
  if (nd[p].l == nd[p].r) {
    nd[p].mn.first = v;
    return;
  }
  int mid = nd[p].l + nd[p].r >> 1;
  chg(x, v, p << 1 | (x > mid));
  nd[p].mn = min(nd[p << 1].mn, nd[p << 1 | 1].mn);
}
pair<int, int> ask(int l, int r, int p = 1) {
  if (l <= nd[p].l && r >= nd[p].r) return nd[p].mn;
  int mid = nd[p].l + nd[p].r >> 1;
  pair<int, int> res;
  res.first = 0x3f3f3f3f;
  if (l <= mid) res = ask(l, r, p << 1);
  if (r > mid) res = min(res, ask(l, r, p << 1 | 1));
  return res;
}
int main() {
  int n, qu, i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", a + i);
  scanf("%d", &qu);
  for (i = 1; i <= qu; i++) scanf("%d%d", &qry[i].l, &qry[i].r), qry[i].id = i;
  sort(qry + 1, qry + qu + 1);
  bld(1, n);
  for (i = 1; i <= qu; i++) {
    for (int j = qry[i - 1].r + 1; j <= qry[i].r; j++) {
      if (laspos[a[j]]) chg(j, laspos[a[j]]), chg(laspos[a[j]], 0x3f3f3f3f);
      laspos[a[j]] = j;
    }
    pair<int, int> mn = ask(qry[i].l, qry[i].r);
    if (mn.first >= qry[i].l)
      ans[qry[i].id] = 0;
    else
      ans[qry[i].id] = a[mn.second];
  }
  for (i = 1; i <= qu; i++) printf("%d\n", ans[i]);
  return 0;
}
