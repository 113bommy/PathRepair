#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, m, a[N + 9], dp[N * 3 + 9][2];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);
  if (!n) {
    puts("0");
    return 0;
  }
  for (int i = m; i >= 1; --i) {
    dp[a[i] + i + N][0] = dp[a[i] + i + 1 + N][0] + 1;
    dp[a[i] - i + N][1] = dp[a[i] - i - 1 + N][1] + 1;
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int l = max(1, i - (m + 1) + dp[i + N][0]),
        r = min(n, i + (m + 1) - dp[i + N][1]);
    ans += r - l + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
