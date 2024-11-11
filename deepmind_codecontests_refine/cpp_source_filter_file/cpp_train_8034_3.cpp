#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const int maxn = 2e5 + 5;
int a[maxn];
struct node {
  int l, r, ans, b[15];
} tree[maxn * 8];
void change(int k, int x) {
  int tmp = x;
  for (int i = 1; i <= 10; i++) tree[k].b[i] = inf;
  for (int i = 1; i <= 10; i++) {
    if (tmp % 10) tree[k].b[i] = min(tree[k].b[i], x);
    tmp /= 10;
  }
}
void pushup(int k) {
  int ls = k << 1, rs = k << 1 | 1;
  tree[k].ans = min(tree[ls].ans, tree[rs].ans);
  for (int i = 1; i <= 10; i++) {
    tree[k].b[i] = min(tree[ls].b[i], tree[rs].b[i]);
    if (tree[ls].b[i] < inf && tree[rs].b[i] < inf) {
      tree[k].ans = min(tree[k].ans, tree[ls].b[i] + tree[rs].b[i]);
    }
  }
}
void build(int k, int l, int r) {
  tree[k].l = l;
  tree[k].r = r;
  tree[k].ans = inf;
  for (int i = 1; i <= 10; i++) tree[k].b[i] = inf;
  if (l == r) {
    change(k, a[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  pushup(k);
}
void update(int k, int p, int x) {
  if (tree[k].l == tree[k].r) {
    change(k, x);
    return;
  }
  int mid = (tree[k].l + tree[k].r) >> 1;
  if (mid >= p)
    update(k << 1, p, x);
  else
    update(k << 1 | 1, p, x);
  pushup(k);
}
node query(int k, int l, int r) {
  if (tree[k].l == l && tree[k].r == r) {
    return tree[k];
  }
  int mid = (tree[k].l + tree[k].r) >> 1;
  node res;
  if (mid >= r)
    res = query(k << 1, l, r);
  else if (mid < l)
    res = query(k << 1 | 1, l, r);
  else {
    node tmp1 = query(k << 1, l, mid);
    node tmp2 = query(k << 1 | 1, mid + 1, r);
    res.ans = min(tmp1.ans, tmp2.ans);
    for (int i = 1; i <= 10; i++) {
      res.b[i] = min(tmp1.b[i], tmp2.b[i]);
      if (tmp1.b[i] < inf && tmp2.b[i] < inf) {
        res.ans = min(res.ans, tmp1.b[i] + tmp2.b[i]);
      }
    }
  }
  return res;
}
int main() {
  int n, m, op, x, y;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  build(1, 1, n);
  while (m--) {
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      update(1, x, y);
    } else {
      node res = query(1, x, y);
      if (res.ans == inf)
        printf("-1\n");
      else
        printf("%d\n", res.ans);
    }
  }
  return 0;
}
