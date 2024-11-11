#include <bits/stdc++.h>
using namespace std;
struct Node {
  int l, r;
  int minv, maxv, tar;
  int mindp;
} nde[100010 << 2];
int a[100010];
void up(int p) {
  nde[p].minv = min(nde[p << 1].minv, nde[p << 1 | 1].minv);
  nde[p].maxv = min(nde[p << 1].maxv, nde[p << 1 | 1].maxv);
  nde[p].tar = max(max(nde[p << 1].maxv - nde[p << 1 | 1].minv,
                       nde[p << 1 | 1].maxv - nde[p << 1].minv),
                   max(nde[p << 1].tar, nde[p << 1 | 1].tar));
  nde[p].mindp = min(nde[p << 1].mindp, nde[p << 1 | 1].mindp);
}
void build(int l, int r, int p) {
  nde[p].l = l, nde[p].r = r;
  if (l >= r) {
    nde[p].minv = nde[p].maxv = a[l];
    nde[p].tar = 0;
    return;
  }
  int m = (l + r) >> 1;
  build(l, m, p << 1);
  build(m + 1, r, p << 1 | 1);
  up(p);
}
Node query(int l, int r, int p) {
  if (l <= nde[p].l && r >= nde[p].r) return nde[p];
  if (r <= nde[p << 1].r)
    return query(l, r, p << 1);
  else if (l >= nde[p << 1 | 1].l)
    return query(l, r, p << 1 | 1);
  else {
    Node t1 = query(l, r, p << 1), t2 = query(l, r, p << 1 | 1), t;
    t.maxv = max(t1.maxv, t2.maxv);
    t.minv = min(t1.minv, t2.minv);
    t.tar = max(max(t1.maxv - t2.minv, t2.maxv - t1.minv), max(t1.tar, t2.tar));
    return t;
  }
}
void update(int k, int p, int v) {
  if (nde[p].l >= nde[p].r) {
    nde[p].mindp = v;
    return;
  }
  if (k <= nde[p << 1].r)
    update(k, p << 1, v);
  else
    update(k, p << 1 | 1, v);
  up(p);
}
int Q(int l, int r, int p) {
  if (l > r) return 0x3f3f3f3f;
  if (l <= nde[p].l && r >= nde[p].r) return nde[p].mindp;
  if (l > nde[p].r || r < nde[p].l) return 0x3f3f3f3f;
  return min(Q(l, r, p << 1), Q(l, r, p << 1 | 1));
}
int dp[100010];
int main() {
  int n, S, L;
  scanf("%d%d%d", &n, &S, &L);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  build(1, n, 1);
  if (L > n) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i < L; ++i) {
    dp[i] = 0x3f3f3f3f;
    update(i, 1, 0x3f3f3f3f);
  }
  int maxv = query(1, L, 1).tar;
  if (maxv > S) {
    puts("-1");
    return 0;
  }
  dp[L] = 1;
  dp[0] = 0;
  update(L, 1, 1);
  int minv = 0x3f3f3f3f;
  int lft = 1;
  for (int i = L + 1; i <= n; ++i) {
    while (lft < i) {
      maxv = query(lft, i, 1).tar;
      if (maxv > S)
        ++lft;
      else
        break;
    }
    int tmp = Q(max(lft - 1, 1), i - L, 1);
    if (lft == 1) tmp = 0;
    if (tmp != 0x3f3f3f3f) ++tmp;
    dp[i] = tmp;
    update(i, 1, dp[i]);
  }
  if (dp[n] == 0x3f3f3f3f) dp[n] = -1;
  printf("%d\n", dp[n]);
}
