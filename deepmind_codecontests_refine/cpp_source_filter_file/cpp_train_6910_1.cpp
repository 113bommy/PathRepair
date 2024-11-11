#include <bits/stdc++.h>
using namespace std;
long long T, n, m, s;
long long tag[200010 << 2], sum[200010 << 2];
void build(long long o, long long l, long long r) {
  long long mid = l + r >> 1;
  if (l == r) {
    sum[o] = tag[o] = 0;
    return;
  }
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
  sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
void pushdown(long long o, long long l, long long r) {
  long long mid = l + r >> 1;
  sum[o << 1] += 1LL * (mid - l + 1) * tag[o];
  tag[o << 1] += tag[o];
  sum[o << 1 | 1] += 1LL * (r - mid) * tag[o];
  tag[o << 1 | 1] += tag[o];
  tag[o] = 0;
}
void update(long long o, long long l, long long r, long long L, long long R,
            long long x) {
  long long mid = l + r >> 1;
  if (L <= l && r <= R) {
    sum[o] += (r - l + 1) * x;
    tag[o] += x;
    return;
  }
  if (tag[o] && l != r) pushdown(o, l, r);
  if (L <= mid) update(o << 1, l, mid, L, R, x);
  if (R > mid) update(o << 1 | 1, mid + 1, r, L, R, x);
  sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
long long query(long long o, long long l, long long r, long long L,
                long long R) {
  long long mid = l + r >> 1;
  long long ans = 0;
  if (L <= l && r <= R) return sum[o];
  if (tag[o]) pushdown(o, l, r);
  if (L <= mid) ans += query(o << 1, l, mid, L, R);
  if (R > mid) ans += query(o << 1 | 1, mid + 1, r, L, R);
  return ans;
}
signed main() {
  scanf("%lld", &T);
  s = 1;
  n = 200005;
  while (T--) {
    long long t, a, x, k;
    scanf("%lld", &t);
    if (t == 1) {
      scanf("%lld%lld", &a, &x);
      update(1, 1, n, 1, a, x);
    } else if (t == 2) {
      scanf("%lld", &k);
      s++;
      update(1, 1, n, s, s, k);
    } else {
      update(1, 1, n, s, s, -query(1, 1, n, 1, s));
      s--;
    }
    printf("%.6Lf\n", query(1, 1, n, 1, s) / (long double)s);
  }
}
