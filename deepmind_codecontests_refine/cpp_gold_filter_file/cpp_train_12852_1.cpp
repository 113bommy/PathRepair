#include <bits/stdc++.h>
using namespace std;
int a[3000];
int dp[3000];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  dp[1] = 2 * (a[1] - 1);
  for (int i = 2; i <= n; i++) {
    dp[i] = 100000;
  }
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= min(i, k); j++) {
      dp[i] = min(dp[i], dp[i - j] + 2 * (a[i] - 1));
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
