#include <bits/stdc++.h>
using namespace std;
long long n, r1, r2, r3, d;
long long a[1000001];
long long p1[1000001], p2[1000001], dp[1000001];
int main() {
  scanf("%lld %lld %lld %lld %lld", &n, &r1, &r2, &r3, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    p1[i] = r1 * a[i] + r3;
    p2[i] = min(r1 + r2, r1 * (a[i] + 2));
  }
  dp[0] = p1[0];
  dp[1] = min(p1[0] + p1[1] + d, p2[0] + p2[1] + d * 3);
  for (int i = 2; i < n - 1; ++i)
    dp[i] = min(dp[i - 1] + p1[i] + d, dp[i - 2] + p2[i - 1] + p2[i] + d * 4);
  if (n > 2) {
    dp[n - 1] = min(dp[n - 2] + p1[n - 1] + d,
                    dp[n - 3] + p2[n - 2] + p1[n - 1] + d * 3);
    dp[n - 1] = min(dp[n - 1], dp[n - 3] + p2[n - 2] + p2[n - 1] + d * 4);
    dp[n - 1] = min(dp[n - 1], dp[n - 2] + p2[n - 1] + d * 2);
  }
  printf("%lld\n", dp[n - 1]);
  return 0;
}
