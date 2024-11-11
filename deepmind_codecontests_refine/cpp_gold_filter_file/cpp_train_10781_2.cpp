#include <bits/stdc++.h>
using namespace std;
struct node {
  int left_down, right_up, val, left_val, right_val, size;
  long long al, ar, lazy;
  node() {
    al = ar = 0;
    left_down = right_up = 0;
    val = left_val = right_val = 0;
    size = 0;
    lazy = 0;
  }
  node(int x) {
    al = ar = x;
    left_down = right_up = 1;
    val = left_val = right_val = 1;
    size = 1;
    lazy = 0;
  }
};
node operator+(const node &a, const node &b) {
  node tmp = node();
  tmp.size = a.size + b.size;
  tmp.al = a.al;
  tmp.ar = b.ar;
  tmp.val = max(a.val, b.val);
  if (a.ar > b.al) tmp.val = max(tmp.val, a.right_val + b.left_down);
  if (a.ar < b.al) tmp.val = max(tmp.val, a.right_up + b.left_val);
  tmp.right_up = b.right_up;
  if (a.ar < b.al && b.right_up == b.size) tmp.right_up += a.right_up;
  tmp.left_down = a.left_down;
  if (a.ar > b.al && a.left_down == a.size) tmp.left_down += b.left_down;
  tmp.right_val = b.right_val;
  if (a.ar < b.al && b.right_val == b.size) tmp.right_val += a.right_up;
  if (b.left_down == b.size && a.ar > b.al)
    tmp.right_val = max(tmp.right_val, a.right_val + b.left_down);
  tmp.left_val = a.left_val;
  if (a.ar > b.al && a.left_val == a.size) tmp.left_val += b.left_down;
  if (a.right_up == a.size && a.ar < b.al)
    tmp.left_val = max(tmp.left_val, b.left_val + a.right_up);
  return tmp;
}
node operator+(const node &a, long long x) {
  node tmp = a;
  tmp.al += x;
  tmp.ar += x;
  tmp.lazy += x;
  return tmp;
}
const int T = 524288, B = 19;
node tree[T << 1];
void pushdown(int x) {
  if (tree[x].lazy) {
    tree[x << 1] = tree[x << 1] + tree[x].lazy;
    tree[x << 1 ^ 1] = tree[x << 1 ^ 1] + tree[x].lazy;
    tree[x].lazy = 0;
  }
}
void PTL(int x) {
  for (int i = B; i >= 1; --i) pushdown(x >> i);
}
void add(int l, int r, int c) {
  l = l + T - 1;
  r = r + T + 1;
  PTL(l);
  PTL(r);
  int ll = l, rr = r;
  while (l + 1 < r) {
    if (~l & 1) tree[l ^ 1] = tree[l ^ 1] + c;
    if (r & 1) tree[r ^ 1] = tree[r ^ 1] + c;
    l >>= 1;
    r >>= 1;
  }
  for (ll >>= 1; ll >= 1; ll >>= 1)
    tree[ll] = tree[ll << 1] + tree[ll << 1 ^ 1];
  for (rr >>= 1; rr >= 1; rr >>= 1)
    tree[rr] = tree[rr << 1] + tree[rr << 1 ^ 1];
}
int query(int l, int r) {
  l = l + T - 1;
  r = r + T + 1;
  PTL(l);
  PTL(r);
  node rl = node(), rr = node();
  while (l + 1 < r) {
    if (~l & 1) rl = rl + tree[l ^ 1];
    if (r & 1) rr = tree[r ^ 1] + rr;
    l >>= 1;
    r >>= 1;
  }
  return (rl + rr).val;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    tree[i + T] = node(a);
  }
  for (int i = T - 1; i >= 1; --i) tree[i] = tree[i << 1] + tree[i << 1 ^ 1];
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    add(l, r, d);
    printf("%d\n", query(1, n));
  }
}
