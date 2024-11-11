#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 10;
const long long INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 1e9 + 7;
long long segtree[MAXN << 2];
long long lazy[MAXN << 2];
long long arr[MAXN];
long long ans[MAXN];
void pushup(long long rt) {
  segtree[rt] = min(segtree[rt << 1], segtree[rt << 1 | 1]);
}
void pushdown(long long rt) {
  if (lazy[rt]) {
    segtree[rt << 1] = max(0ll, segtree[rt << 1] - lazy[rt]);
    segtree[rt << 1 | 1] = max(0ll, segtree[rt << 1 | 1] - lazy[rt]);
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
  }
}
void build(long long l, long long r, long long rt) {
  lazy[rt] = 0;
  if (l == r) {
    segtree[rt] = arr[l];
    return;
  }
  long long m = l + r >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  pushup(rt);
}
long long query(long long l, long long r, long long rt) {
  if (l == r) {
    return l;
  }
  long long m = l + r >> 1;
  pushdown(rt);
  if (!segtree[rt << 1 | 1])
    return query(m + 1, r, rt << 1 | 1);
  else
    return query(l, m, rt << 1);
}
void update(long long l, long long r, long long L, long long R, long long C,
            long long rt) {
  if (L <= l && r <= R) {
    segtree[rt] = max(0ll, segtree[rt] - C);
    lazy[rt] += C;
    return;
  }
  long long m = l + r >> 1;
  pushdown(rt);
  if (L <= m) update(l, m, L, R, C, rt << 1);
  if (R > m) update(m + 1, r, L, R, C, rt << 1 | 1);
  pushup(rt);
}
void update(long long l, long long r, long long pos, long long rt) {
  if (l == r && l == pos) {
    segtree[rt] = INF;
    return;
  }
  long long m = l + r >> 1;
  pushdown(rt);
  if (pos <= m)
    update(l, m, pos, rt << 1);
  else
    update(m + 1, r, pos, rt << 1 | 1);
  pushup(rt);
}
signed main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 1; i <= n; ++i) {
    scanf("%lld", &arr[i]);
  }
  build(1, n, 1);
  long long now = 0;
  for (long long i = n; i > 0; --i) {
    long long index = query(1, n, 1);
    ans[index] = ++now;
    if (index + 1 <= n) update(1, n, index + 1, n, now, 1);
    update(1, n, index, 1);
  }
  for (long long i = 1; i <= n; ++i) printf("%lld ", ans[i]);
  return 0;
}
