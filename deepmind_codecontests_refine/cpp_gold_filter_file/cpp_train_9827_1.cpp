#include <bits/stdc++.h>
using namespace std;
int n, a[2000010], i, x;
long long ans, dp[2000010];
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  reverse(a, a + n);
  for (i = 0; i < n; i++) dp[i + 1] = dp[i] + a[i], ans += a[i];
  for (i = 1; i < n; i *= 4) ans += dp[i];
  printf("%I64d\n", ans);
  return 0;
}
