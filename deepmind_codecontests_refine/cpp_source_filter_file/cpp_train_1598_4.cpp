#include <bits/stdc++.h>
using namespace std;
int p[222];
double arr[222];
double dp[222][222][444];
int main() {
  int n, k, l;
  double ans = 0;
  scanf("%d%d%d", &n, &l, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lf", arr + i);
    arr[i] /= 100;
  }
  for (int i = 0; i < n; i++) scanf("%d", p + i);
  dp[0][0][min(n, k) + n] = 1;
  for (int i = 0; i < n; i++) {
    for (int pick = 0; pick <= l; pick++) {
      for (int cap = 0; cap < n * 2; cap++) {
        if (cap + p[i] < 0) continue;
        dp[i + 1][min(pick + 1, l)][min(cap + p[i], 2 * n)] +=
            dp[i][pick][cap] * arr[i];
        dp[i + 1][min(pick, l)][min(cap, 2 * n)] +=
            dp[i][pick][cap] * (1 - arr[i]);
      }
    }
  }
  for (int i = 0; i <= n; i++) ans += dp[n][l][i + n];
  printf("%lf\n", ans);
  return 0;
}
