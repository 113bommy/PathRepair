#include <bits/stdc++.h>
using namespace std;
int n, dp[3000][2], a[3000], b[3000], c[3000], i;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) scanf("%d", &b[i]);
  for (i = 0; i < n; i++) scanf("%d", &c[i]);
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[1][0] = max(a[0] + b[1], a[1] + b[0]);
  dp[1][1] = max(b[0] + b[1], a[0] + c[1]);
  for (i = 2; i < n; i++) {
    dp[i][0] = max(dp[i - 1][0] + b[i], dp[i - 1][1] + a[i]);
    dp[i][1] = max(dp[i - 1][0] + c[i], dp[i - 1][1] + b[i]);
  }
  printf("%d", dp[n - 1][0]);
  return 0;
}
