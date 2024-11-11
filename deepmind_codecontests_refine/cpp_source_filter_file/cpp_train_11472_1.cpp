#include <bits/stdc++.h>
using namespace std;
const long long NR = 5e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
void Min(long long& x, long long y) { x = min(x, y); }
void Max(long long& x, long long y) { x = max(x, y); }
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long n, k, len = INF, ans;
long long l[NR], r[NR];
__int128 sl[NR], sr[NR];
long long num[NR], tot = 2;
long long calc(long long L, long long R) {
  if (R < L) return -1;
  long long pr = lower_bound(r + 1, r + n + 1, R) - r;
  __int128 res = 0;
  res += (__int128)R * (pr - 1) - sr[pr - 1];
  long long pl = upper_bound(l + 1, l + n + 1, L) - l;
  res += sl[n] - sl[pl - 1] - (__int128)L * (n - pl + 1);
  if ((__int128)k + 0.01 >= res)
    return 1;
  else
    return 0;
}
signed main() {
  n = read(), k = read();
  for (long long i = 1; i <= n; i++) {
    l[i] = read(), r[i] = read();
    Min(len, r[i] - l[i] + 1);
  }
  sort(l + 1, l + n + 1), sort(r + 1, r + n + 1);
  for (long long i = 1; i <= n; i++) sl[i] = sl[i - 1] + l[i];
  for (long long i = 1; i <= n; i++) sr[i] = sr[i - 1] + r[i];
  num[1] = 4, num[2] = 7;
  long long latt = 1;
  for (long long i = 2; i <= 17; i++) {
    long long tt = tot;
    for (long long j = latt; j <= tt; j++) num[++tot] = num[j] * 10 + 4;
    for (long long j = latt; j <= tt; j++) num[++tot] = num[j] * 10 + 7;
    latt = tt + 1;
  }
  sort(num + 1, num + tot + 1);
  long long R = 0;
  for (long long L = 1; L <= tot; L++) {
    while (R < tot && num[R + 1] - num[L] + 1 <= len &&
           calc(num[L], num[R + 1]))
      R++;
    Max(ans, R - L + 1);
  }
  printf("%lld\n", ans);
  return 0;
}
