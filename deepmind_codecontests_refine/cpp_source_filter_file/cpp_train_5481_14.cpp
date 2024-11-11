#include <bits/stdc++.h>
using namespace std;
const int __ = 2005;
int a[__], dp[__];
int one[__], two[__];
int d[__];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = (1); i <= (n); i++) {
    for (int j = (0); j <= (i - 1); j++)
      if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
    ans = max(ans, dp[i]);
  }
  for (int i = (1); i <= (n); i++)
    if (a[i] == 1)
      one[i] = one[i - 1] + 1;
    else
      one[i] = one[i - 1];
  for (int i = (n); i >= (1); i--)
    if (a[i] == 2)
      two[i] = two[i + 1] + 1;
    else
      two[i] = two[i + 1];
  for (int i = (1); i <= (n); i++) {
    memset((d), (0), sizeof(d)), d[1] = -a[i];
    int idx = 1;
    for (int j = (i + 1); j <= (n); j++) {
      if (-a[j] >= d[idx])
        d[++idx] = -a[j];
      else {
        int k = upper_bound(d + 1, d + idx + 1, a[j]) - d;
        d[k] = -a[j];
      }
      ans = max(ans, idx + one[i - 1] + two[j + 1]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
