#include <bits/stdc++.h>
using namespace std;
int n, s, pos = 1, ans = 0, a[85], b[85], dp[85];
int main() {
  scanf("%d%d", &n, &s);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
  dp[0] = 0;
  for (int i = 1; i <= s; i++) {
    dp[i] = i;
    bool flag = 0;
    for (int j = 1; j <= n; j++)
      if (a[j] + b[j] >= i && a[j] - b[j] <= i) flag = 1;
    if (flag) dp[i] = dp[i - 1];
    for (int j = 1; j <= n; j++)
      if (a[j] + b[j] < i)
        dp[i] = min(dp[i], dp[max(0, 2 * a[j] - i - 1)] + i - (a[j] + b[j]));
  }
  printf("%d", dp[s]);
}
