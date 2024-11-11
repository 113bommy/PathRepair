#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int dp[n + 1];
    for (int i = 0; i < n + 1; i++) dp[i] = 1;
    for (int i = n - 1; i > 0; i--) {
      int j = 2;
      while (i * j <= n) {
        if (a[i - 1] < a[i * j - 1]) {
          if (dp[i * j] + 1 > dp[i]) dp[i] = dp[i * j] + 1;
        }
        j += 1;
      }
    }
    int maxans = 0;
    for (int i = 1; i <= n; i++) {
      if (dp[i] > maxans) maxans = dp[i];
    }
    printf("%d", maxans);
    printf("\n");
  }
  return 0;
}
