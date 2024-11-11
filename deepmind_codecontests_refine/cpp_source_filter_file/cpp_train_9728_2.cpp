#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10;
long long n, m, rval[MAXN];
struct Node {
  long long maxn, sum;
} nodes[MAXN * 4];
void pushup(long long x) {
  (nodes[x]).maxn = max(nodes[(x << 1)].maxn, nodes[(x << 1 | 1)].maxn);
  (nodes[x]).sum = nodes[(x << 1)].sum + nodes[(x << 1 | 1)].sum;
}
void build(long long x, long long l, long long r) {
  if (l == r)
    (nodes[x]).maxn = (nodes[x]).sum = rval[l];
  else
    build((x << 1), l, ((l + r) >> 1)),
        build((x << 1 | 1), (((l + r) >> 1) + 1), r), pushup(x);
}
void update_range(long long x, long long l, long long r, long long tl,
                  long long tr, long long val) {
  if ((nodes[x]).maxn < val) return;
  if (l == r) {
    (nodes[x]).sum = (nodes[x]).sum % val,
    (nodes[x]).maxn = (nodes[x]).maxn % val;
    return;
  }
  if (tl <= ((l + r) >> 1))
    update_range((x << 1), l, ((l + r) >> 1), tl, tr, val);
  if (tr >= (((l + r) >> 1) + 1))
    update_range((x << 1 | 1), (((l + r) >> 1) + 1), r, tl, tr, val);
  pushup(x);
}
void update_one(long long x, long long l, long long r, long long t,
                long long val) {
  if (l == r) {
    (nodes[x]).sum = (nodes[x]).maxn = val;
    return;
  }
  if (t <= ((l + r) >> 1))
    update_one((x << 1), l, ((l + r) >> 1), t, val);
  else
    update_one((x << 1 | 1), (((l + r) >> 1) + 1), r, t, val);
  pushup(x);
}
long long query(long long x, long long l, long long r, long long tl,
                long long tr) {
  if (tl <= l && r <= tr) return (nodes[x]).sum;
  long long res = 0;
  if (tl <= ((l + r) >> 1)) res += query((x << 1), l, ((l + r) >> 1), tl, tr);
  if (tr >= (((l + r) >> 1) + 1))
    res += query((x << 1 | 1), (((l + r) >> 1) + 1), r, tl, tr);
  return res;
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld", rval + i);
  build(1, 1, n);
  for (long long i = 1, op, x, y, z; i <= n; i++) {
    scanf("%lld", &op);
    switch (op) {
      case 1:
        scanf("%lld%lld", &x, &y), printf("%lld\n", query(1, 1, n, x, y));
        break;
      case 2:
        scanf("%lld%lld%lld", &x, &y, &z), update_range(1, 1, n, x, y, z);
        break;
      case 3:
        scanf("%lld%lld", &x, &y), update_one(1, 1, n, x, y);
    }
  }
  return 0;
}
