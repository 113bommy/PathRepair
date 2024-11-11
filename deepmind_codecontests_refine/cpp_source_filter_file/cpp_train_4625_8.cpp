#include <bits/stdc++.h>
int n, m, a[100010] = {0};
struct node {
  int x, sum;
} tree[100010 << 2] = {0};
struct segment {
  inline void pushup(int rt) {
    tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
  }
  inline void add(int l, int r, int rt, int p, int a) {
    if (l == r) {
      tree[rt].x = a;
      tree[rt].sum = 1;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      add(l, mid, rt << 1, p, a);
    else
      add(mid + 1, r, rt << 1 | 1, p, a);
    pushup(rt);
    return;
  }
  inline void print(int l, int r, int rt) {
    if (l == r) {
      if (tree[rt].sum == 1) printf("%d", tree[rt].x);
      return;
    }
    int mid = (l + r) >> 1;
    print(l, mid, rt << 1);
    print(mid + 1, r, rt << 1 | 1);
  }
  inline void del(int l, int r, int rt, int p) {
    if (l == r) {
      tree[rt].sum = 0;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= tree[rt << 1].sum)
      del(l, mid, rt << 1, p);
    else
      del(mid + 1, r, rt << 1 | 1, p - tree[rt << 1].sum);
    pushup(rt);
  }
} segtree;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  int k = 0;
  while (n--) {
    int x;
    scanf("%d", &x);
    if (x == -1) {
      for (int i = 1; i <= m && a[i] - i + 1 <= tree[1].sum; i++)
        segtree.del(1, 100010, 1, a[i] - i + 1);
    } else {
      k++;
      segtree.add(1, 100010, 1, k, x);
    }
  }
  if (tree[1].sum)
    segtree.print(1, 100010, 1);
  else
    printf("Poor stack!");
  return 0;
}
