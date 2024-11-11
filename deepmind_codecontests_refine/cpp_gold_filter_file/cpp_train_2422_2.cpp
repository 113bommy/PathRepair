#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int N = 4e5 + 5;
int i2x[N], icnt;
int x2i(int x) { return lower_bound(i2x + 1, i2x + 1 + icnt, x) - i2x; }
struct Node {
  int l, r, m, mush, z;
  double e;
} seg[N * 3];
struct Tree {
  int a, h, l, r;
} trees[N];
struct Mush {
  int b, z;
} mu[N];
void build(int l, int r, int idx) {
  int m = (l + r) / 2;
  seg[idx].l = l, seg[idx].r = r, seg[idx].m = m;
  seg[idx].e = 1, seg[idx].mush = 0, seg[idx].z = 0;
  if (r - l == 1) return;
  build(l, m, idx * 2);
  build(m, r, idx * 2 + 1);
}
void insertMush(int b, int z, int idx) {
  if (seg[idx].r - seg[idx].l == 1) {
    seg[idx].mush = 1;
    seg[idx].z += z;
    return;
  }
  if (b < seg[idx].m)
    insertMush(b, z, idx * 2);
  else
    insertMush(b, z, idx * 2 + 1);
  seg[idx].mush = (seg[idx * 2].mush || seg[idx * 2 + 1].mush);
}
void pushdown(int idx) {
  seg[idx * 2].e *= seg[idx].e;
  seg[idx * 2 + 1].e *= seg[idx].e;
  seg[idx].e = 1;
}
void insertTree(int l, int r, double p, int idx) {
  if (seg[idx].l == l && seg[idx].r == r) {
    seg[idx].e *= p;
    return;
  }
  if (r <= seg[idx].m)
    insertTree(l, r, p, idx * 2);
  else if (l >= seg[idx].m)
    insertTree(l, r, p, idx * 2 + 1);
  else {
    insertTree(l, seg[idx].m, p, idx * 2);
    insertTree(seg[idx].m, r, p, idx * 2 + 1);
  }
}
double ans = 0;
void solve(double e, int idx) {
  if (seg[idx].r - seg[idx].l == 1) {
    ans += 1.0 * seg[idx].z * e * seg[idx].e;
    return;
  }
  if (seg[idx * 2].mush) solve(e * seg[idx].e, idx * 2);
  if (seg[idx * 2 + 1].mush) solve(e * seg[idx].e, idx * 2 + 1);
}
int main() {
  int n, m, i;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &trees[i].a, &trees[i].h, &trees[i].l, &trees[i].r);
    i2x[++icnt] = trees[i].a;
    i2x[++icnt] = trees[i].a + trees[i].h;
    i2x[++icnt] = trees[i].a - trees[i].h;
  }
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &mu[i].b, &mu[i].z);
    i2x[++icnt] = mu[i].b;
  }
  sort(i2x + 1, i2x + 1 + icnt);
  icnt = unique(i2x + 1, i2x + 1 + icnt) - i2x - 1;
  build(1, icnt + 1, 1);
  for (i = 1; i <= m; i++) insertMush(x2i(mu[i].b), mu[i].z, 1);
  for (i = 1; i <= n; i++) {
    insertTree(x2i(trees[i].a - trees[i].h), x2i(trees[i].a),
               1.0 - 0.01 * trees[i].l, 1);
    insertTree(x2i(trees[i].a) + 1, x2i(trees[i].a + trees[i].h) + 1,
               1.0 - 0.01 * trees[i].r, 1);
  }
  solve(1, 1);
  printf("%lf\n", ans);
  return 0;
}
