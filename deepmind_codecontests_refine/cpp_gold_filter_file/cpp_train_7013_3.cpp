#include <bits/stdc++.h>
using namespace std;
double ans;
int n, p;
int arr[100];
double dp[52][52];
double f[52];
int main() {
  scanf("%d", &n);
  memset(dp, 0, sizeof(dp));
  f[0] = 1;
  for (int i = 1; i <= 50; i++) f[i] = f[i - 1] * i;
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
  scanf("%d", &p);
  for (int i = 0; i < n; i++) {
    for (int j = n; j >= 1; j--) {
      for (int k = arr[i]; k <= p; k++) dp[j][k] += dp[j - 1][k - arr[i]];
    }
  }
  ans = 0;
  for (int j = 1; j <= n; j++)
    for (int k = 1; k <= p; k++) ans += dp[j][k] * f[j] * f[n - j];
  printf("%.6lf\n", ans / f[n]);
}
