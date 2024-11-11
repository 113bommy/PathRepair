#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 10;
long long n, pre, ans;
struct fenwick {
  long long c[maxn];
  inline void add(long long x, long long v) {
    for (; x <= maxn; x += x & (-x)) c[x] += v;
  }
  inline long long sum(long long x) {
    long long res = 0;
    for (; x; x -= x & (-x)) res += c[x];
    return res;
  }
} q, p;
signed main() {
  scanf("%lld", &n);
  for (long long i = 1, x; i <= n; i++) {
    scanf("%lld", &x);
    ans += pre + (i - 1) * x - p.sum(x);
    pre += x;
    for (long long d = 1; d * x <= maxn; d++)
      ans -= x * d * (q.sum(min((d + 1) * x, maxn) - 1) - q.sum(d * x - 1));
    printf("%lld%c", ans, i ^ n ? ' ' : '\n');
    q.add(x, 1);
    for (long long d = 1; d * x <= maxn; d++) {
      p.add(d * x, d * x);
      p.add(min((d + 1) * x, maxn) + 1, -d * x);
    }
  }
  return 0;
}
