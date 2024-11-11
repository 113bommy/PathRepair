#include <bits/stdc++.h>
using namespace std;
int n, t[100005];
int l1, l2;
int dp[100005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &t[i]);
  l1 = 1;
  l2 = 1;
  for (int i = 1; i <= n; ++i) {
    while (t[i] - t[l1] > 89) ++l1;
    while (t[i] - t[l2] > 1439) ++l2;
    dp[i] = 1e9;
    dp[i] = min(dp[i], dp[i - 1] + 20);
    dp[i] = min(dp[i], dp[l1 - 1] + 50);
    dp[i] = min(dp[i], dp[l2 - 1] + 120);
  }
  for (int i = 1; i <= n; ++i) printf("%d\n", dp[i] - dp[i - 1]);
  return 0;
}
