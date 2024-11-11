#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int a[1005];
int dp[1005];
int sum[1005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  dp[1] = 1;
  sum[1] = 1;
  int ans = 2;
  for (int i = 2; i <= n; i++) {
    if (a[i] == i) {
      dp[i] = 1;
    } else {
      dp[i] = (sum[i - 1] - sum[a[i] - 1] + mod + i - a[i] + 1) % mod;
    }
    sum[i] = (sum[i - 1] + dp[i]) % mod;
    ans = (ans + 1 + dp[i]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
