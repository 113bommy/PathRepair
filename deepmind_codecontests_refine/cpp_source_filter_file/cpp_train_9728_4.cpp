#include <bits/stdc++.h>
using namespace std;
const long long M = 1e5 + 5;
long long n, m, a[M];
long long read() {
  register long long x = 0, y = 1;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') y = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c ^ 48), c = getchar();
  }
  return y ? x : -x;
}
struct ed {
  long long l, r, mid, sum, len, lazy, Max;
} tree[M << 2];
void f(long long p, long long sum) {
  tree[p].sum += tree[p].len * sum;
  tree[p].lazy += sum;
}
void push_up(long long p) {
  tree[p].sum = tree[(p) << 1].sum + tree[(p) << 1 | 1].sum;
  tree[p].Max = (tree[(p) << 1].Max) > (tree[(p) << 1 | 1].Max)
                    ? (tree[(p) << 1].Max)
                    : (tree[(p) << 1 | 1].Max);
}
void push_down(long long p) {
  if (tree[p].lazy) {
    f((p) << 1, tree[p].lazy);
    f((p) << 1 | 1, tree[p].lazy);
  }
  tree[p].lazy = 0;
}
void buildtree(long long p, long long l, long long r) {
  tree[p].l = l, tree[p].r = r, tree[p].len = r - l + 1,
  tree[p].mid = (l + r) >> 1;
  if (l == r) {
    tree[p].sum = a[l];
    tree[p].Max = a[l];
    return;
  }
  buildtree((p) << 1, l, tree[p].mid);
  buildtree((p) << 1 | 1, tree[p].mid + 1, r);
  push_up(p);
}
void modify_mod(long long p, long long l, long long r, long long mod) {
  if (tree[p].Max < mod) return;
  if (tree[p].l == tree[p].r) {
    tree[p].sum %= mod;
    tree[p].Max %= mod;
    return;
  }
  if (l <= tree[p].mid) modify_mod((p) << 1, l, r, mod);
  if (r > tree[p].mid) modify_mod((p) << 1 | 1, l, r, mod);
  push_up(p);
}
void modify(long long p, long long x, long long sum) {
  if (tree[p].l == tree[p].r) {
    tree[p].sum = tree[p].Max = sum;
    return;
  }
  if (x <= tree[p].mid) modify((p) << 1, x, sum);
  if (x > tree[p].mid) modify((p) << 1 | 1, x, sum);
  push_up(p);
}
long long query(long long p, long long l, long long r) {
  if (l <= tree[p].l && r >= tree[p].r) return tree[p].sum;
  long long sum = 0;
  push_down(p);
  if (l <= tree[p].mid) sum += query((p) << 1, l, r);
  if (r > tree[p].mid) sum += query((p) << 1 | 1, l, r);
  return sum;
}
signed main() {
  n = read(), m = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  buildtree(1, 1, n);
  for (long long i = 1, l, r, k, x, op, mod; i <= m; i++) {
    op = read();
    if (op == 1) l = read(), r = read(), printf("%d\n", query(1, l, r));
    if (op == 2) l = read(), r = read(), mod = read(), modify_mod(1, l, r, mod);
    if (op == 3) k = read(), x = read(), modify(1, k, x);
  }
  return 0;
}
