#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long w = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) w |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  return w ? -x : x;
}
namespace star {
const long long maxn = 1e6 + 10, INF = 0x3f3f3f3f;
long long n, m, p, a[maxn];
struct SegmentTree {
  long long sum[maxn << 2];
  vector<long long> c[maxn << 2];
  inline void pushup(const long long &ro, const long long &len) {
    sum[ro] = sum[(ro << 1)] + sum[(ro << 1 | 1)];
    long long y = 0, rslen = len >> 1, lslen = len - rslen;
    for (long long x = 0; x <= lslen; x++) {
      y -= y > rslen;
      for (; y <= rslen; y++) {
        if (c[(ro << 1)][x + 1] - 1 - 1ll * x * p + sum[(ro << 1)] <
            c[(ro << 1 | 1)][y]) {
          y -= y != 0;
          break;
        }
        c[ro][x + y] = min(c[ro][x + y], max(c[(ro << 1)][x],
                                             c[(ro << 1 | 1)][y] + 1ll * x * p -
                                                 sum[(ro << 1)]));
      }
    }
  }
  void build(const long long &ro = 1, const long long &l = 1,
             const long long &r = n) {
    for (long long i = 1; i <= r - l + 3; i++) c[ro].push_back(INF);
    c[ro][0] = -INF;
    if (l == r) {
      sum[ro] = a[l];
      c[ro][1] = p - a[l];
      return;
    }
    build((ro << 1), l, ((l + r) >> 1)),
        build((ro << 1 | 1), ((l + r) >> 1) + 1, r);
    pushup(ro, r - l + 1);
  }
  long long query(const long long &x, const long long &y, const long long &k,
                  const long long &ro = 1, const long long &l = 1,
                  const long long &r = n) {
    if (x == l and y == r)
      return k + sum[ro] -
             1ll * p *
                 (upper_bound(c[ro].begin(), c[ro].end(), x) - c[ro].begin() -
                  1);
    if (y <= ((l + r) >> 1))
      return query(x, y, k, (ro << 1), l, ((l + r) >> 1));
    if (x > ((l + r) >> 1))
      return query(x, y, k, (ro << 1 | 1), ((l + r) >> 1) + 1, r);
    return query(((l + r) >> 1) + 1, y,
                 query(x, ((l + r) >> 1), k, (ro << 1), l, ((l + r) >> 1)),
                 (ro << 1 | 1), ((l + r) >> 1) + 1, r);
  }
} S;
inline void work() {
  n = read(), m = read(), p = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  S.build();
  while (m--) {
    long long l = read(), r = read();
    printf("%lld\n", S.query(l, r, 0));
  }
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
