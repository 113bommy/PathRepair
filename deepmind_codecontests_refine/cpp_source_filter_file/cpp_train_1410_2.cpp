#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
struct SegTree {
  int l, r;
  int v;
} tree[100010 << 2];
void PushDown(int rt) {
  if (tree[rt].v) {
    tree[rt << 1].v = tree[rt].v;
    tree[rt << 1 | 1].v = tree[rt].v;
    tree[rt].v = 0;
  }
}
void PushUp(int rt) {
  if (tree[rt << 1].v == tree[rt << 1 | 1].v) tree[rt].v = tree[rt << 1].v;
}
void t_build(int l, int r, int rt) {
  int m = (l + r) >> 1;
  tree[rt].l = l;
  tree[rt].r = r;
  tree[rt].v = 0;
  if (l == r) return;
  t_build(l, m, rt << 1);
  t_build(m + 1, r, rt << 1 | 1);
}
void t_update(int v, int l, int r, int rt) {
  int m = (tree[rt].l + tree[rt].r) >> 1;
  if (l == tree[rt].l && r == tree[rt].r) {
    tree[rt].v = v;
    return;
  }
  PushDown(rt);
  if (m >= r)
    t_update(v, l, r, rt << 1);
  else if (m < l)
    t_update(v, l, r, rt << 1 | 1);
  else {
    t_update(v, l, m, rt << 1);
    t_update(v, m + 1, r, rt << 1 | 1);
  }
  PushUp(rt);
}
int t_query(int pos, int rt) {
  int m = (tree[rt].l + tree[rt].r) >> 1;
  if (tree[rt].l == pos && tree[rt].r == pos) return tree[rt].v;
  PushDown(rt);
  if (m >= pos)
    return t_query(pos, rt << 1);
  else
    return t_query(pos, rt << 1 | 1);
  PushUp(rt);
}
int n;
int a[100010], b[100010], l[100010], r[100010];
map<int, int> mp;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) mp[b[i]] = i;
  for (int i = 1; i <= n; i++) a[i] = mp[a[i]];
  t_build(1, n, 1);
  t_update(a[1], 1, n, 1);
  l[a[1]] = 1;
  r[a[1]] = n;
  for (int i = 2; i <= n; i++) {
    int fa = t_query(a[i], 1);
    printf("%d ", fa);
    if (a[i] < fa) {
      l[a[i]] = l[fa];
      r[a[i]] = fa - 1;
      t_update(a[i], l[a[i]], r[a[i]], 1);
    } else {
      l[a[i]] = fa + 1;
      r[a[i]] = r[fa];
      t_update(a[i], l[a[i]], r[a[i]], 1);
    }
  }
  return 0;
}
