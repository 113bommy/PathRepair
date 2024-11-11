#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150005;
struct seg {
  int l, r;
  double sum, maxl, maxr, _max;
} tree[MAXN * 4];
double A[MAXN];
void update(int fa) {
  if (tree[fa].l + 1 >= tree[fa].r) return;
  tree[fa].sum = tree[2 * (fa)].sum + tree[2 * (fa) + 1].sum;
  tree[fa].maxl =
      max(tree[2 * (fa)].maxl, tree[2 * (fa)].sum + tree[2 * (fa) + 1].maxl);
  tree[fa].maxr = max(tree[2 * (fa) + 1].maxr,
                      tree[2 * (fa) + 1].sum + tree[2 * (fa)].maxr);
  tree[fa]._max = max(tree[2 * (fa)]._max, tree[2 * (fa) + 1]._max);
  tree[fa]._max =
      max(tree[fa]._max, tree[2 * (fa)].maxr + tree[2 * (fa) + 1].maxl);
}
void buildTree(int fa, int l, int r) {
  int mid = (l + r) >> 1;
  tree[fa].l = l;
  tree[fa].r = r;
  if (r - l <= 1) {
    tree[fa].sum = A[l];
    tree[fa].maxl = tree[fa].maxr = tree[fa]._max = A[l];
    return;
  }
  buildTree(2 * (fa), l, mid);
  buildTree(2 * (fa) + 1, mid, r);
  update(fa);
}
seg combine(seg a, seg b) {
  seg res;
  res.l = a.l;
  res.r = b.r;
  res.sum = a.sum + b.sum;
  res.maxl = max(a.maxl, a.sum + b.maxl);
  res.maxr = max(b.maxr, b.sum + a.maxr);
  res._max = max(a._max, b._max);
  res._max = max(res._max, a.maxr + b.maxl);
  return res;
}
seg query(int fa, int l, int r) {
  int mid = (tree[fa].l + tree[fa].r) >> 1;
  if (tree[fa].l == l && tree[fa].r == r) {
    seg res;
    res.l = tree[fa].l;
    res.r = tree[fa].r;
    res.sum = tree[fa].sum;
    res.maxl = tree[fa].maxl;
    res.maxr = tree[fa].maxr;
    res._max = tree[fa]._max;
    return res;
  }
  if (r <= mid) {
    return query(2 * (fa), l, r);
  } else if (l >= mid) {
    return query(2 * (fa) + 1, l, r);
  } else {
    seg segL = query(2 * (fa), l, mid);
    seg segR = query(2 * (fa) + 1, mid, r);
    seg res = combine(segL, segR);
    return res;
  }
}
int N, M, C;
double P[MAXN], D[MAXN];
int main() {
  scanf("%d %d %d", &N, &M, &C);
  for (int i = 1; i <= N; ++i) {
    scanf("%lf", &D[i]);
  }
  for (int i = 1; i < N; ++i) {
    scanf("%lf", &P[i]);
  }
  for (int i = 1; i < N; ++i) {
    A[i] = (D[i + 1] - D[i]) / 2 - P[i] / 100 * C;
  }
  buildTree(1, 1, N);
  int l, r;
  double ans = 0;
  for (int i = 1; i <= M; ++i) {
    scanf("%d %d", &l, &r);
    seg s = query(1, l, r);
    ans += max(s._max, 0.0);
  }
  printf("%.9lf\n", ans);
}
