#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const long long mod = 1e9 + 7;
long long n, m, p[maxn * 2];
struct node1 {
  long long l, r;
} c[maxn];
bool cmp(node1 a, node1 b) {
  if (a.r != b.r) return a.r < b.r;
  return a.l < b.l;
}
struct node {
  long long left, right, mid;
  long long x;
} tree[maxn * 4];
void build(long long l, long long r, int rt) {
  tree[rt].left = l;
  tree[rt].right = r;
  tree[rt].mid = (l + r) >> 1;
  if (l == r) return;
  build(l, tree[rt].mid, rt << 1);
  build(tree[rt].mid + 1, r, rt << 1 | 1);
}
long long query(long long l, long long r, int rt) {
  if (l <= tree[rt].left && r >= tree[rt].right) return tree[rt].x % mod;
  long long ans = 0;
  if (l <= tree[rt].mid) ans += query(l, r, rt << 1);
  ans %= mod;
  if (r > tree[rt].mid) ans += query(l, r, rt << 1 | 1);
  return ans % mod;
}
void add(long long L, long long C, int rt) {
  if (tree[rt].left == tree[rt].right) {
    tree[rt].x = (tree[rt].x + C) % mod;
    return;
  }
  if (L <= tree[rt].mid)
    add(L, C, rt << 1);
  else
    add(L, C, rt << 1 | 1);
  tree[rt].x = (tree[rt << 1].x + tree[rt << 1 | 1].x) % mod;
}
int main() {
  scanf("%lld%lld", &n, &m);
  int tol = 1;
  for (int i = 0; i < m; i++) {
    scanf("%lld%lld", &c[i].l, &c[i].r);
    p[tol++] = c[i].l;
    p[tol++] = c[i].r;
  }
  sort(p + 1, p + tol + 1);
  sort(c, c + m, cmp);
  build(1, tol, 1);
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    long long ans = 0;
    long long l = lower_bound(p + 1, p + tol + 1, c[i].l) - p;
    long long r = lower_bound(p + 1, p + tol + 1, c[i].r) - p;
    if (c[i].l == 0) ans++;
    if (r >= l) ans += query(l, r - 1, 1);
    add(r, ans, 1);
    if (c[i].r == n) sum = query(r, r, 1);
  }
  printf("%lld\n", sum);
  return 0;
}
