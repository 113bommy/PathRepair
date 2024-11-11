#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int a[3];
int sum[1 << 24];
int dp[1 << 24];
int main() {
  int n, k;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    for (int j = 0; j < (1 << i); j++) {
      sum[(1 << i) + j] = sum[j] + t;
      if (sum[(1 << i) + j] > mod) sum[(1 << i) + j] = mod;
    }
  }
  scanf("%d", &k);
  for (int i = 0; i < k; i++) scanf("%d", a + i);
  for (int i = 0; i < 1 << n; i++)
    if (sum[i] == a[0] || sum[i] == a[1])
      sum[i] = 0;
    else
      sum[1] = 1;
  dp[0] = 1;
  for (int i = 1; i < 1 << n; i++) {
    if (sum[i] == 0) continue;
    for (int j = i; j; j -= j & -j) {
      dp[i] += dp[i - (j & -j)];
      if (dp[i] > mod) dp[i] -= mod;
    }
  }
  printf("%d\n", dp[(1 << n) - 1]);
  return 0;
}
