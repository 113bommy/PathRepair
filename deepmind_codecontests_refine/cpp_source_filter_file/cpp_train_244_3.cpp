#include <bits/stdc++.h>
using namespace std;
int n;
long long a[10010];
int dp[10010], b[10010];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    while (a[i] % 2 == 0) {
      b[i]++;
      a[i] /= 2;
    }
  }
  dp[0] = 1;
  int ans = n;
  for (int i = 0; i < n; i++) {
    dp[i] = i;
    for (int j = 0; j < i; j++)
      if (a[j] % a[i] == 0 && (b[j] + i - j >= b[i] || b[i] <= i - j - 1))
        dp[i] = min(dp[j] + i - j - 1, dp[i]);
    ans = min(ans, n - i - 1 + dp[i]);
  }
  printf("%d\n", ans);
  return 0;
}
