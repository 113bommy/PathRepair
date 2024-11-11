#include <bits/stdc++.h>
using namespace std;
const long long infin = 1000000000000000;
long long llabs(long long a) { return (a < 0 ? -a : a); }
long long dp[5101], Min[5101];
long long a[5101], b[5101];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
  for (int i = 0; i < n; i++) b[i] = a[i];
  sort(b, b + n);
  int m = unique(b, b + n) - b;
  for (int i = 0; i < m; i++) {
    dp[i] = llabs(b[i] - a[0]);
    if (i == 0)
      Min[i] = dp[i];
    else
      Min[i] = min(dp[i], Min[i - 1]);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[j] = Min[j] + llabs(a[i] - b[j]);
      if (j == 0)
        Min[j] = dp[j];
      else
        Min[j] = min(dp[j], Min[j - 1]);
    }
  }
  long long ans = Min[m - 1];
  printf("%I64d", ans);
}
