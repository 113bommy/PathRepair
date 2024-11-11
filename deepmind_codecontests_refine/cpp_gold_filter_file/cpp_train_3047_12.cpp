#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
long long n, m, k, t, mx, mi, idx, cnt, tot, sum, res, flag, st;
long long a[maxn], dp[maxn][2];
long long minn(long long a, long long b, long long c) {
  return min(a, min(b, c));
}
int main() {
  long long r1, r2, r3, d;
  scanf("%lld %lld %lld %lld %lld", &n, &r1, &r2, &r3, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  memset(dp, inf, sizeof dp);
  dp[1][0] = a[1] * r1 + r3;
  dp[1][1] = min(a[1] * r1 + r1, r2);
  for (int i = 2; i <= n; i++) {
    dp[i][1] = min(dp[i - 1][0] + min(a[i] * r1 + r1, r2),
                   dp[i - 1][1] + 2 * d + r1 + min(a[i] * r1 + r1, r2)) +
               d;
    dp[i][0] = minn(dp[i - 1][1] + 2 * d + r1 + a[i] * r1 + r3,
                    dp[i - 1][0] + a[i] * r1 + r3,
                    dp[i - 1][1] + 2 * r1 + 2 * d + min(a[i] * r1 + r1, r2)) +
               d;
  }
  printf("%lld\n", min(dp[n][0], dp[n - 1][1] + 2 * d + r1 + a[n] * r1 + r3));
  return 0;
}
