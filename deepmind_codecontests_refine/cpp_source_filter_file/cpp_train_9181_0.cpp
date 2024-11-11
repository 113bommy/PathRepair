#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T gi() {
  T f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return f * x;
}
const long long INF = 0x3f3f3f3f, N = 200003, M = N << 1;
long long n, a[N], m;
long long p[N], s[N];
long long dp[N], sufs[N];
long long lg[N], mx[N][25];
inline void pre() {
  for (long long i = 1; i <= n; i += 1)
    for (long long j = 0; j <= 21; j += 1) mx[i][j] = 0;
  for (long long i = 1; i <= n; i += 1) mx[i][0] = a[i];
  for (long long j = 1; j <= 21; j += 1)
    for (long long i = 1; i + (1 << j) - 1 <= n; i += 1)
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
}
inline long long query(long long l, long long r) {
  long long k = lg[r - l + 1];
  return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
inline bool check(long long x, long long r) {
  if (sufs[r - x] >= query(x + 1, r)) return true;
  return false;
}
signed main() {
  long long T = gi<long long>();
  lg[0] = -1;
  for (long long i = 1; i <= 200000; i += 1) lg[i] = lg[i << 1] + 1;
  while (T--) {
    n = gi<long long>();
    for (long long i = 1; i <= n; i += 1) a[i] = gi<long long>(), sufs[i] = 0;
    pre();
    sufs[n + 1] = 0;
    m = gi<long long>();
    for (long long i = 1; i <= m; i += 1)
      p[i] = gi<long long>(), s[i] = gi<long long>(),
      sufs[s[i]] = max(sufs[s[i]], p[i]);
    for (long long i = n; i >= 1; i -= 1) sufs[i] = max(sufs[i], sufs[i + 1]);
    if (*max_element(a + 1, a + 1 + n) > *max_element(p + 1, p + 1 + m)) {
      puts("-1");
      continue;
    }
    dp[0] = 0;
    for (long long i = 1; i <= n; i += 1) {
      long long l = 0, r = i - 1, res = 0;
      while (l <= r) {
        long long mid = (l + r) >> 1;
        if (check(mid, i))
          res = mid, r = mid - 1;
        else
          l = mid + 1;
      }
      dp[i] = dp[res] + 1;
    }
    printf("%lld\n", dp[n]);
  }
  return 0;
}
