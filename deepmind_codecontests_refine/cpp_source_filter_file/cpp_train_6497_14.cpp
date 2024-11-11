#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
int n, k, dp[N + 2];
long long m, a[N + 1];
bool check() {
  for (int i = 0; i <= n; i++) dp[i] = i;
  for (int i = 0; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (abs((j == n ? a[i] : a[j]) - a[i]) <= ((long long)(j - i)) * m)
        dp[j] = min(dp[j], dp[i] + j - i - 1);
    }
  }
  return dp[n] <= k;
}
int main() {
  std::ios::sync_with_stdio(false);
  scanf("%d%d", &n, &k);
  if (n <= 1 || k == n) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  long long l = 0, r = 1e9 + 1;
  long long ans = r;
  while (l <= r) {
    m = (l + r) / 2;
    if (check()) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  printf("%d\n", ans);
  return 0;
}
