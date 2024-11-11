#include <bits/stdc++.h>
int main(void) {
  int n, i, a[100005], dp[100005] = {0}, verif1[100005] = {0},
                       verif2[100005] = {0};
  long long int ans = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (verif1[a[i]])
      dp[i] = dp[i - 1];
    else {
      verif1[a[i]]++;
      dp[i] = dp[i - 1] + 1;
    }
  }
  for (i = n - 1; i > 0; i--) {
    if (!verif2[a[i]]) {
      verif2[a[i]]++;
      ans += dp[i - 1];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
