#include <bits/stdc++.h>
using namespace std;
const int mod = 100000007;
const int maxn = 1005;
int n, k;
long long int a[maxn], dp[maxn][maxn] = {0};
long long int answer(int x) {
  dp[0][0] = 1;
  int li = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
    while (a[li] + x <= a[i]) li++;
    if (li != 0) li--;
    for (int j = 1; j <= i && j <= k; j++) {
      dp[i][j] = dp[i - 1][j] + dp[li][j - 1];
      dp[i][j] %= mod;
    }
  }
  return dp[n][k];
}
int main() {
  long long int ans = 0;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i * (k - 1) <= a[n]; i++) {
    ans += answer(i);
    ans %= mod;
  }
  printf("%I64d", ans);
  return 0;
}
