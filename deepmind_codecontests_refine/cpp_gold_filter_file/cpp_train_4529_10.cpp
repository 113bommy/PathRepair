#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
long long total, a[300005], k, dp[5005][5005];
int main() {
  scanf("%d%d", &total, &k);
  for (int i = 0; i < total; i++) scanf("%I64d", a + i);
  sort(a, a + total);
  int end1 = total % k, end2 = k - end1, mul = total / k;
  for (int i = 0; i <= end2; i++)
    for (int j = 0; j <= end1; j++) {
      if (i == 0 && j == 0) continue;
      dp[i][j] = (long long)1 << 62;
      if (i) {
        int l = (i - 1) * mul + j * (mul + 1);
        dp[i][j] = dp[i - 1][j] + a[l + mul - 1] - a[l];
      }
      if (j) {
        int l = i * mul + (j - 1) * (mul + 1);
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[l + mul] - a[l]);
      }
    }
  printf("%I64d", dp[end2][end1]);
  return 0;
}
