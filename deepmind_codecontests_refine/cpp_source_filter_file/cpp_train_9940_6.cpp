#include <bits/stdc++.h>
int n1, n2, m;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
inline int max(int x, int y) { return x > y ? x : y; }
struct node {
  int lsum, rsum, sum;
} tree1[200010 << 2], tree2[200010 << 2];
inline void build(node tree[], int p, int l, int r) {
  tree[p].lsum = tree[p].rsum = tree[p].sum = r - l + 1;
  if (l == r) return;
  int mid = l + r >> 1;
  build(tree, p << 1, l, mid);
  build(tree, p << 1 | 1, mid + 1, r);
}
inline void pushup(node tree[], int p, int l, int r) {
  int mid = l + r >> 1;
  tree[p].sum = max(tree[p << 1].lsum, tree[p << 1 | 1].rsum);
  tree[p].sum = max(tree[p].sum, tree[p << 1].rsum + tree[p << 1 | 1].lsum);
  tree[p].lsum = tree[p << 1].lsum;
  if (tree[p << 1].sum == mid - l + 1) tree[p].lsum += tree[p << 1 | 1].lsum;
  tree[p].rsum = tree[p << 1 | 1].rsum;
  if (tree[p << 1 | 1].sum == r - mid) tree[p].rsum += tree[p << 1].rsum;
}
inline void change(node tree[], int p, int l, int r, int x) {
  if (l == r) {
    tree[p].lsum = tree[p].rsum = tree[p].sum = 0;
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    change(tree, p << 1, l, mid, x);
  else
    change(tree, p << 1 | 1, mid + 1, r, x);
  pushup(tree, p, l, r);
}
int main() {
  n1 = read();
  n2 = read();
  m = read();
  build(tree1, 1, 1, n1 - 1);
  build(tree2, 1, 1, n2 - 1);
  while (m--) {
    char op[2];
    int x;
    scanf("%s", op);
    x = read();
    if (op[0] == 'V')
      change(tree1, 1, 1, n1 - 1, x);
    else
      change(tree2, 1, 1, n2 - 1, x);
    printf("%lld\n", (long long)(tree1[1].sum + 1) * (tree2[1].sum + 1));
  }
  return 0;
}
