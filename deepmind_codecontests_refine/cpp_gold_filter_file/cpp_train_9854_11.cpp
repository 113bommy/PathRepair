#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long n = 0, k = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') k = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    n = (n << 1) + (n << 3) + (c ^ 48), c = getchar();
  return n * k;
}
long long n, c, sum;
long long arr[300010];
long long dp[300010];
struct segtree {
  long long val[300010], mi[300010];
  void build(long long rt, long long s, long long t) {
    if (s == t) {
      long long x = read();
      mi[rt] = x;
      sum += x;
      return;
    }
    long long mid = s + t >> 1;
    build(rt << 1, s, mid);
    build(rt << 1 | 1, mid + 1, t);
    mi[rt] = min(mi[rt << 1], mi[rt << 1 | 1]);
  }
  long long ask(long long rt, long long s, long long t, long long l,
                long long r) {
    if (l <= s && t <= r) return mi[rt];
    long long mid = s + t >> 1;
    long long ans = 999999999999;
    if (l <= mid) ans = min(ans, ask(rt << 1, s, mid, l, r));
    if (r > mid) ans = min(ans, ask(rt << 1 | 1, mid + 1, t, l, r));
    return ans;
  }
} myt;
signed main() {
  n = read(), c = read();
  myt.build(1, 1, n);
  for (register long long i = c; i <= n; ++i) {
    long long minans = myt.ask(1, 1, n, i - c + 1, i);
    dp[i] = max(dp[i - 1], dp[i - c] + minans);
  }
  printf("%I64d\n", sum - dp[n]);
  return 0;
}
