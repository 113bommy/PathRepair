#include <bits/stdc++.h>
using namespace std;
long long num[5005];
int two[5005];
int dp[5005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) {
    scanf("%lld", &num[i]);
    while (~num[i] & 1) ++two[i], num[i] >>= 1;
  }
  int mn = n - 1;
  for (int i = (1); i <= (n); i++) {
    dp[i] = 1;
    for (int j = (1); j <= (i - 1); j++) {
      if (two[i] && (two[i] <= two[j] || two[i] - two[j] > i - j) ||
          num[j] % num[i] != 0)
        continue;
      dp[i] = max(dp[i], dp[j] + 1);
    }
    mn = min(mn, n - dp[i]);
  }
  printf("%d\n", mn);
  return 0;
}
