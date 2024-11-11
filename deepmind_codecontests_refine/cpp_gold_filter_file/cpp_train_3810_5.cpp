#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n, b[maxn], rmq[maxn * 2][19], Log[maxn];
void init() {
  Log[1] = 0;
  for (int i = 2; i < maxn; ++i) Log[i] = Log[i >> 1] + 1;
}
int rmquery(int l, int r) {
  if (l > r) return (0x7fffffff);
  int k = Log[r - l + 1];
  return (min(rmq[l][k], rmq[r - (1 << k) + 1][k]));
}
int rquery(int l, int r) {
  if (l > r) return (0x7fffffff);
  if (r - l + 1 >= n) return (rmquery(1, n));
  int ll = (l - 1) % n + 1, rr = (r - 1) % n + 1;
  if ((l - 1) / n == (r - 1) / n)
    return (rmquery(ll, rr));
  else
    return (min(rmquery(ll, n), rmquery(1, rr)));
}
struct SegmT {
  int ls[maxn * 100], rs[maxn * 100], lazy[maxn * 100], mini[maxn * 100], tot;
  void init() { tot = 0; }
  int newnode() {
    ls[tot] = rs[tot] = lazy[tot] = -1;
    mini[tot] = 0x7fffffff;
    return (tot++);
  }
  void pushdown(int rt) {
    if (lazy[rt] != -1) {
      if (ls[rt] == -1) ls[rt] = newnode();
      lazy[ls[rt]] = lazy[rt];
      mini[ls[rt]] = lazy[rt];
      if (rs[rt] == -1) rs[rt] = newnode();
      mini[rs[rt]] = lazy[rt];
      lazy[rs[rt]] = lazy[rt];
      lazy[rt] = -1;
    }
  }
  void pushup(int rt, int l, int mid, int r) {
    mini[rt] = 0x7fffffff;
    if (ls[rt] != -1)
      mini[rt] = min(mini[rt], mini[ls[rt]]);
    else
      mini[rt] = min(mini[rt], rquery(l, mid));
    if (rs[rt] != -1)
      mini[rt] = min(mini[rt], mini[rs[rt]]);
    else
      mini[rt] = min(mini[rt], rquery(mid + 1, r));
  }
  void update(int& rt, int tl, int tr, int l, int r, int x) {
    if (rt == -1) rt = newnode();
    if (l <= tl && tr <= r) {
      lazy[rt] = mini[rt] = x;
      return;
    }
    pushdown(rt);
    int mid = (tl + tr) >> 1;
    if (l <= mid) update(ls[rt], tl, mid, l, r, x);
    if (r > mid) update(rs[rt], mid + 1, tr, l, r, x);
    pushup(rt, tl, mid, tr);
    return;
  }
  int query(int rt, int tl, int tr, int l, int r) {
    if (rt == -1) {
      return (rquery(max(l, tl), min(tr, r)));
    } else {
      if (l <= tl && tr <= r) return (mini[rt]);
      pushdown(rt);
      int mid = (tl + tr) >> 1, ans = 0x7fffffff;
      if (l <= mid) ans = min(ans, query(ls[rt], tl, mid, l, r));
      if (r > mid) ans = min(ans, query(rs[rt], mid + 1, tr, l, r));
      pushup(rt, tl, mid, tr);
      return (ans);
    }
  }
} segm;
int main() {
  std::ios::sync_with_stdio(false);
  int k, q, l, r, op, x;
  init();
  segm.init();
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]), rmq[i][0] = b[i];
  for (int j = 1; j <= 17; ++j)
    for (int i = 1; i <= n; ++i)
      rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
  int rt = -1;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      scanf("%d", &x);
      segm.update(rt, 1, n * k, l, r, x);
    } else if (op == 2) {
      printf("%d\n", segm.query(rt, 1, n * k, l, r));
    }
  }
  return 0;
}
