#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int M = 100005;
struct Seg_Tree {
  int left, right;
  double p;
} L[N << 2];
struct Tree {
  int x, h, l, r;
} tree[M];
int n, m, k;
int b[N], z[N];
int x[N], s[N];
void bulid(int step, int l, int r) {
  L[step].left = l;
  L[step].right = r;
  L[step].p = 1.0;
  if (l == r) return;
  int m = (l + r) >> 1;
  bulid(step << 1, l, m);
  bulid(step << 1 | 1, m + 1, r);
}
void update(int step, int l, int r, double val) {
  if (L[step].left == l && L[step].right == r) {
    L[step].p *= val;
    return;
  }
  int m = (L[step].left + L[step].right) >> 1;
  if (r <= m)
    update(step << 1, l, r, val);
  else if (l > m)
    update(step << 1 | 1, l, r, val);
  else {
    update(step << 1, l, m, val);
    update(step << 1 | 1, m + 1, r, val);
  }
}
void modify(int l, int r, double val) {
  l = lower_bound(x, x + k, l) - x;
  r = upper_bound(x, x + k, r) - x - 1;
  if (l <= r) update(1, l, r, val);
}
double query(int step) {
  if (L[step].left == L[step].right) return s[L[step].left] * L[step].p;
  L[step << 1].p *= L[step].p;
  L[step << 1 | 1].p *= L[step].p;
  return query(step << 1) + query(step << 1 | 1);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d%d%d%d", &tree[i].x, &tree[i].h, &tree[i].l, &tree[i].r);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &b[i], &z[i]);
    x[i] = b[i];
  }
  sort(x, x + m);
  k = unique(x, x + m) - x;
  for (int i = 0; i < m; i++) {
    b[i] = lower_bound(x, x + k, b[i]) - x;
    s[b[i]] += z[i];
  }
  bulid(1, 0, k - 1);
  for (int i = 0; i < n; i++) {
    modify(tree[i].x - tree[i].h, tree[i].x - 1, 0.01 * tree[i].l);
    modify(tree[i].x + 1, tree[i].x + tree[i].h, 0.01 * tree[i].r);
  }
  printf("%.10f\n", query(1));
  return 0;
}
