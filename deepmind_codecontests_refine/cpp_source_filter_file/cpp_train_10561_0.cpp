#include <bits/stdc++.h>
using namespace std;
int dp[10005];
int main() {
  int k, n1, n2, n3, t1, t2, t3, i;
  while (scanf("%d %d %d %d %d %d %d", &k, &n1, &n2, &n3, &t1, &t2, &t3) !=
         EOF) {
    memset(dp, 0, sizeof(dp));
    for (i = 1; i <= k; i++) {
      if (i >= n3) dp[i] = max(dp[i], dp[i - n3] + t3);
      if (i >= n2) dp[i] = max(dp[i], dp[i - n2] + t2);
      if (i >= n1) dp[i] = max(dp[i], dp[i - n1] + t1);
    }
    printf("%d\n", dp[k] + t1 + t2 + t3);
  }
  return 0;
}
