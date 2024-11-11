#include <bits/stdc++.h>
using namespace std;
int a[2111];
long long dp[5000];
double dp2[5000];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      dp[a[j] - a[i]]++;
    }
  }
  for (int sum = 1; sum < 5000; sum++) {
    for (int d = 1; d < sum; d++) {
      dp2[sum] += dp[sum - d] * dp[d];
    }
  }
  for (int i = 1; i < 5000; i++) {
    dp2[i] += dp2[i - 1];
  }
  double fuck = (n - 1) * n / 2;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int del = a[j] - a[i];
      double cur = dp2[del - 1];
      cur /= fuck;
      cur /= fuck;
      ans += cur;
    }
  }
  ans /= fuck;
  printf("%.15lf\n", ans);
}
