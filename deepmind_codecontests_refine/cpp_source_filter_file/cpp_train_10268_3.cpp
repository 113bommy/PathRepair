#include <bits/stdc++.h>
using namespace std;
int dp[201000], x[201000], p[201000], n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &p[i]);
    dp[i] = x[i] + p[i];
  }
  for (int i = 1; i < n; i++) {
    dp[i] = min(dp[i], dp[i - 1] + 1);
  }
  for (int i = n - 2; i >= 0; i--) {
    dp[i] = min(dp[i], dp[i + 1] + 1);
  }
  long long flag = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] < x[i]) flag = 1;
    sum += dp[i] - x[i];
  }
  if (flag)
    printf("-1\n");
  else {
    printf("%d\n", sum);
    for (int i = 0; i < n; i++) printf("%d ", dp[i]);
    printf("\n");
  }
  return 0;
}
