#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, base = 31, MOD = 20020303;
long long n, m, k, q;
long long a[N], sum[N << 2], tag[N << 2];
long long bin[N], val[10][N];
inline void init() {
  bin[0] = 1;
  for (register long long i = 1; i <= n; ++i)
    bin[i] = (bin[i - 1] * base) % MOD;
  for (register long long i = 0; i <= 9; ++i)
    for (register long long j = 1; j <= n; ++j)
      val[i][j] = (val[i][j - 1] * base % MOD + i) % MOD;
}
void build(long long k, long long l, long long r) {
  if (l == r) {
    sum[k] = val[a[l]][1];
    return;
  }
  long long mid = l + r >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  sum[k] = (sum[k << 1] * bin[r - (mid + 1) + 1] % MOD + sum[k << 1 | 1]) % MOD;
}
inline void pushdown(long long k, long long l, long long r, long long mid) {
  if (~tag[k]) {
    tag[k << 1] = tag[k << 1 | 1] = tag[k];
    sum[k << 1] = val[tag[k]][mid - l + 1];
    sum[k << 1 | 1] = val[tag[k]][r - (mid + 1) + 1];
    tag[k] = -1;
  }
}
void change(long long k, long long l, long long r, long long qx, long long qy,
            long long v) {
  if (qx == l && r == qy) {
    sum[k] = val[v][r - l + 1];
    tag[k] = v;
    return;
  }
  long long mid = l + r >> 1;
  pushdown(k, l, r, mid);
  if (qx <= mid && mid < qy) {
    change(k << 1, l, mid, qx, mid, v);
    change(k << 1 | 1, mid + 1, r, mid + 1, qy, v);
  } else if (qx <= mid)
    change(k << 1, l, mid, qx, qy, v);
  else if (qy < mid)
    change(k << 1 | 1, mid + 1, r, qx, qy, v);
  sum[k] = (sum[k << 1] * bin[r - (mid + 1) + 1] % MOD + sum[k << 1 | 1]) % MOD;
}
long long query(long long k, long long l, long long r, long long qx,
                long long qy) {
  if (qx == l && r == qy) return sum[k];
  long long mid = l + r >> 1;
  pushdown(k, l, r, mid);
  if (qx <= mid && mid < qy)
    return (query(k << 1, l, mid, qx, mid) * bin[qy - (mid + 1) + 1] % MOD +
            query(k << 1 | 1, mid + 1, r, mid + 1, qy)) %
           MOD;
  if (qx <= mid) return query(k << 1, l, mid, qx, qy);
  if (mid < qy) return query(k << 1 | 1, mid + 1, r, qx, qy);
}
signed main() {
  memset(tag, -1, sizeof(tag));
  scanf("%lld%lld%lld", &n, &m, &k);
  q = m + k;
  init();
  for (register long long i = 1; i <= n; ++i) scanf("%1lld", &a[i]);
  build(1, 1, n);
  while (q--) {
    long long opt, x, y, z;
    scanf("%lld", &opt);
    if (opt == 1) {
      scanf("%lld%lld%lld", &x, &y, &z);
      change(1, 1, n, x, y, z);
    }
    if (opt == 2) {
      scanf("%lld%lld%lld", &x, &y, &z);
      if (y - x + 1 < z)
        puts("NO");
      else if (y - x + 1 == z)
        puts("YES");
      else if (query(1, 1, n, x, y - z) == query(1, 1, n, x + z, y))
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
