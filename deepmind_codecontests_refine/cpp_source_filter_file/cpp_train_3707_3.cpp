#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
const int N = 35010, M = 55;
int n, k, pre[N], dp[N];
struct node {
  int l, r, val;
  node(int l = 0, int r = 0, int val = 0) : l(l), r(r), val(val) {}
} q[N];
inline int max(int a, int b) { return a > b ? a : b; }
namespace SEG {
struct seg {
  int mx, laz;
} tr[N << 2];
void pushup(int o) { tr[o].mx = max(tr[o << 1].mx, tr[o << 1 | 1].mx); }
void pushdown(int o) {
  if (tr[o].laz) {
    tr[o << 1].laz += tr[o].laz;
    tr[o << 1 | 1].laz += tr[o].laz;
    tr[o << 1].mx += tr[o].laz;
    tr[o << 1 | 1].mx += tr[o].laz;
    tr[o].laz = 0;
  }
}
void build(int l, int r, int o) {
  tr[o].laz = 0;
  if (l == r) {
    tr[o].mx = dp[l - 1];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, o << 1);
  build(mid + 1, r, o << 1 | 1);
  pushup(o);
}
void updata(int l, int r, int o, int L, int R, int d) {
  if (l == L && r == R) {
    tr[o].mx += d;
    tr[o].laz += d;
    return;
  }
  pushdown(o);
  int mid = (l + r) >> 1;
  if (L <= mid) updata(l, mid, o << 1, L, min(mid, R), d);
  if (R > mid) updata(mid + 1, r, o << 1 | 1, max(mid + 1, L), R, d);
  pushup(o);
}
int query(int l, int r, int o, int L, int R) {
  if (l == L && r == R) return tr[o].mx;
  pushdown(o);
  int mid = (l + r) >> 1, res = 0;
  if (L <= mid) res = max(res, query(l, mid, o << 1, L, min(L, mid)));
  if (R > mid)
    res = max(res, query(mid + 1, r, o << 1 | 1, max(R, mid + 1), R));
  pushup(o);
  return res;
}
}  // namespace SEG
int main() {
  while (~scanf("%d%d", &n, &k)) {
    memset(pre, 0, sizeof pre);
    for (int i = 1; i <= n; i++) {
      int x = rd();
      q[i] = node(pre[x] + 1, i, x);
      pre[x] = i;
    }
    for (int i = 1; i <= n; i++) dp[i] = dp[i - 1] + (q[i].l == 1 ? 1 : 0);
    for (int j = 2; j <= k; j++) {
      SEG::build(1, n, 1);
      for (int i = 1; i <= n; i++) {
        SEG::updata(1, n, 1, q[i].l, q[i].r, 1);
        dp[i] = SEG::query(1, n, 1, 1, i);
      }
    }
    printf("%d\n", dp[n]);
  }
  return 0;
}
