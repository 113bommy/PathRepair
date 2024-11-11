#include <bits/stdc++.h>
using namespace std;
const long long Maxn = 5e5 + 5, Maxm = 4e6 + 5;
const long long inf = 1e6 + 1;
long long n, q, a[Maxn], mn[Maxm], cnt[Maxm], lz[Maxm];
void pushup(long long k) {
  if (mn[k << 1] == mn[k << 1 | 1])
    mn[k] = mn[k << 1], cnt[k] = cnt[k << 1] + cnt[k << 1 | 1];
  else if (mn[k << 1] < mn[k << 1 | 1])
    mn[k] = mn[k << 1], cnt[k] = cnt[k << 1];
  else
    mn[k] = mn[k << 1 | 1], cnt[k] = cnt[k << 1 | 1];
}
void pushdown(long long k) {
  if (lz[k]) {
    lz[k << 1] += lz[k];
    mn[k << 1] += lz[k];
    lz[k << 1 | 1] += lz[k];
    mn[k << 1 | 1] += lz[k];
    lz[k] = 0;
  }
}
void modify(long long k, long long l, long long r, long long x, long long y) {
  if (l == r) {
    cnt[k] += y;
    return;
  }
  pushdown(k);
  long long mid = (l + r) >> 1;
  if (x <= mid)
    modify(k << 1, l, mid, x, y);
  else
    modify(k << 1 | 1, mid + 1, r, x, y);
  pushup(k);
}
void modify(long long k, long long l, long long r, long long x, long long y,
            long long z) {
  if (x <= l && r <= y) {
    lz[k] += z;
    mn[k] += z;
    return;
  }
  pushdown(k);
  long long mid = (l + r) >> 1;
  if (x <= mid) modify(k << 1, l, mid, x, y, z);
  if (y > mid) modify(k << 1 | 1, mid + 1, r, x, y, z);
  pushup(k);
}
long long query(long long k, long long l, long long r, long long x,
                long long y) {
  if (x <= l && r <= y) {
    if (mn[k] == 1) return cnt[k];
    return 0;
  }
  pushdown(k);
  long long mid = (l + r) >> 1, res = 0;
  if (x <= mid) res += query(k << 1, l, mid, x, y);
  if (y > mid) res += query(k << 1 | 1, mid + 1, r, x, y);
  pushup(k);
  return res;
}
void update(long long l, long long r, long long x) {
  if (l == r) return;
  if (l > r) swap(l, r);
  modify(1, 0, inf, l, r - 1, x);
}
int main() {
  scanf("%lld%lld", &n, &q);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  a[0] = inf;
  a[n + 1] = 0;
  for (long long i = 0; i <= n; i++) {
    update(a[i], a[i + 1], 1);
    modify(1, 0, inf, a[i], 1);
  }
  while (q--) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    update(a[x - 1], a[x], -1);
    update(a[x], a[x + 1], -1);
    modify(1, 0, inf, a[x], -1);
    a[x] = y;
    update(a[x - 1], a[x], 1);
    update(a[x], a[x + 1], 1);
    modify(1, 0, inf, a[x], 1);
    printf("%lld\n", query(1, 0, inf, 1, inf - 1));
  }
  return 0;
}
