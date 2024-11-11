#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int MAXK = 6;
int n, m;
int a[MAXN], c[MAXK][MAXK], pre[MAXN][MAXK];
int power(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % MOD;
    x = 1ll * x * x % MOD;
    y >>= 1;
  }
  return res;
}
namespace SegmentTree {
struct Tree {
  int l, r;
  int sum[MAXK], tag;
} tree[MAXN << 2];
void update(int k) {
  for (int i = 0; i < MAXK; i++)
    tree[k].sum[i] = (tree[k << 1].sum[i] + tree[k << 1 | 1].sum[i]) % MOD;
}
void apply(int k, int val) {
  tree[k].tag = val;
  for (int i = 0; i < MAXK; i++)
    tree[k].sum[i] =
        1ll * val * (pre[tree[k].r][i] - pre[tree[k].l - 1][i] + MOD) % MOD;
}
void down(int k) {
  if (tree[k].tag != -1) {
    apply(k << 1, tree[k].tag);
    apply(k << 1 | 1, tree[k].tag);
    tree[k].tag = -1;
  }
}
void Build(int k, int l, int r) {
  tree[k].l = l;
  tree[k].r = r;
  tree[k].tag = -1;
  if (l == r) {
    for (int i = 0; i < MAXK; i++)
      tree[k].sum[i] = 1ll * a[l] * power(l, i) % MOD;
    return;
  }
  int mid = (l + r) >> 1;
  Build(k << 1, l, mid);
  Build(k << 1 | 1, mid + 1, r);
  update(k);
}
void Modify(int k, int l, int r, int val) {
  if (tree[k].l >= l && tree[k].r <= r) {
    apply(k, val);
    return;
  }
  down(k);
  int mid = (tree[k].l + tree[k].r) >> 1;
  if (l <= mid) Modify(k << 1, l, r, val);
  if (r > mid) Modify(k << 1 | 1, l, r, val);
  update(k);
}
int Query(int k, int l, int r, int t) {
  if (tree[k].l >= l && tree[k].r <= r) return tree[k].sum[t];
  down(k);
  int mid = (tree[k].l + tree[k].r) >> 1;
  int res = 0;
  if (l <= mid) res = (res + Query(k << 1, l, r, t)) % MOD;
  if (r > mid) res = (res + Query(k << 1 | 1, l, r, t)) % MOD;
  return res;
}
}  // namespace SegmentTree
int main() {
  scanf("%d%d", &n, &m);
  c[0][0] = 1;
  for (int i = 1; i < MAXK; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < MAXK; j++)
      pre[i][j] = (pre[i - 1][j] + power(i, j)) % MOD;
  }
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  SegmentTree::Build(1, 1, n);
  while (m--) {
    char op[5];
    int l, r, x;
    scanf("%s%d%d%d", op, &l, &r, &x);
    if (op[0] == '?') {
      int res = 0;
      for (int j = 0; j <= x; j++) {
        res = (res + 1ll * c[x][j] * power((1 - l + MOD) % MOD, x - j) % MOD *
                         SegmentTree::Query(1, l, r, j) % MOD) %
              MOD;
      }
      printf("%d\n", res);
    } else if (op[0] == '=')
      SegmentTree::Modify(1, l, r, x);
  }
  return 0;
}
