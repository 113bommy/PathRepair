#include <bits/stdc++.h>
using namespace std;
int a[(100000 + 10)], dp[(100000 + 10)];
int main() {
  int n, ans = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    dp[a[i]] = dp[a[i] - 1] + 1;
  }
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  printf("%d\n", n - ans);
  return 0;
}
