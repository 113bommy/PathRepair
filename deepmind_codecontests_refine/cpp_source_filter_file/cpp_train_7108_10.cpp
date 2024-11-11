#include <bits/stdc++.h>
using namespace std;
long long sb[5050], dp[5050], sum[5050], num[5050], tmp;
int n, i, j, k;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &sb[i]);
  }
  sort(sb + 1, sb + n + 1);
  for (i = n, j = n; i >= 1; i--) {
    dp[i] = 1;
    for (; j >= 1; j--) {
      if (sb[j] * 2 <= sb[i]) {
        num[i] = j;
        break;
      }
    }
    num[i] += 2;
  }
  for (i = 2; i <= n; i++) {
    for (j = i - 1; j <= n; j++) {
      tmp = dp[j];
      dp[j] = tmp * max(num[j] - i, 0ll) % 998244353;
      dp[j] = (dp[j] + sum[num[j] - 2]) % 998244353;
      sum[j] = sum[j - 1] + tmp;
    }
  }
  printf("%lld", dp[n]);
}
