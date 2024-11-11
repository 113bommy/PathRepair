#include <bits/stdc++.h>
using namespace std;
struct Tree {
  int l, r;
  long long key;
} tree[100010 * 4];
struct A {
  int num;
  long long key;
} a[100010 * 4];
int n;
bool cmp(A x, A y) {
  if (x.key == y.key)
    return x.num < y.num;
  else
    return x.key < y.key;
}
void build(int l, int r, int num) {
  tree[num].l = l;
  tree[num].r = r;
  tree[num].key = 0;
  if (l < r) {
    int mid = (l + r) / 2;
    build(l, mid, num * 2);
    build(mid + 1, r, num * 2 + 1);
  }
}
long long findmax(int l, int r, int num) {
  if (l > r) return 0;
  if (tree[num].l == l && tree[num].r == r) return tree[num].key;
  int mid = (tree[num].l + tree[num].r) / 2;
  if (r <= mid) return findmax(l, r, num * 2);
  if (l > mid) return findmax(l, r, num * 2);
  return max(findmax(l, mid, num * 2), findmax(mid + 1, r, num * 2 + 1));
}
void change(int x, long long y, int num) {
  if (tree[num].l == tree[num].r && tree[num].l == x) {
    tree[num].key = y;
    return;
  }
  int mid = (tree[num].l + tree[num].r) / 2;
  if (x <= mid)
    change(x, y, num * 2);
  else
    change(x, y, num * 2 + 1);
  tree[num].key = max(tree[num * 2].key, tree[num * 2 + 1].key);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    long long h, r;
    scanf("%lld%lld", &r, &h);
    a[i].key = r * r * h;
    a[i].num = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    int now = a[i].num;
    long long t = findmax(1, now - 1, 1) + a[i].key;
    change(now, t, 1);
  }
  double ans = 3.141592653589793 * findmax(1, n, 1);
  printf("%lf\n", ans);
  return 0;
}
