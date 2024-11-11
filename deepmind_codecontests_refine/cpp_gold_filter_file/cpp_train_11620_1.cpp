#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[205];
int dp[205][22100];
int c2(long long x) {
  int ans = 0;
  while (x % 2 == 0) {
    ans++;
    x /= 2;
  }
  return ans;
}
int c5(long long x) {
  int ans = 0;
  while (x % 5 == 0) {
    ans++;
    x /= 5;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  int big = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    big += c2(a[i]);
  }
  int x2, x5;
  for (int i = 0; i <= big; i++)
    for (int j = 0; j <= k; j++) dp[j][i] = -1;
  for (int i = 1; i <= n; i++) {
    x2 = c2(a[i]), x5 = c5(a[i]);
    for (int j = min(i, k); j >= 2; j--) {
      for (int l = 0; l <= big; l++) {
        if (l < x2) continue;
        if (dp[j - 1][l - x2] == -1) continue;
        dp[j][l] = max(dp[j][l], dp[j - 1][l - x2] + x5);
      }
    }
    dp[1][x2] = max(dp[1][x2], x5);
  }
  int ans = 0, t;
  for (int i = 0; i <= big; i++) {
    t = min(dp[k][i], i);
    ans = max(ans, t);
  }
  printf("%d\n", ans);
  return 0;
}
