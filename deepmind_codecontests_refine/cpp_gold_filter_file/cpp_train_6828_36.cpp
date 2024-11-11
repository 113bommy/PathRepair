#include <bits/stdc++.h>
using namespace std;
int a[100005], dp[100005][355];
int n, q;
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (int p = n; p >= 1; p--) {
      for (int k = 1; k <= 350; k++) {
        if (p + a[p] + k > n)
          dp[p][k] = 1;
        else
          dp[p][k] = dp[p + a[p] + k][k] + 1;
      }
    }
    scanf("%d", &q);
    while (q--) {
      int p, k;
      scanf("%d %d", &p, &k);
      if (k <= 350) {
        printf("%d\n", dp[p][k]);
        continue;
      }
      int count = 0;
      while (p <= n) {
        p = p + a[p] + k;
        count++;
      }
      printf("%d\n", count);
    }
  }
  return 0;
}
