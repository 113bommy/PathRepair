#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int n;
int dp[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) dp[i] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] <= a[i - 1] * 2) dp[i] += dp[i - 1];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(dp[i], ans);
  }
  printf("%d\n", ans);
  return 0;
}
