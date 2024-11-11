#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long a[maxn];
long long b[maxn];
long long dp[2][maxn];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
  for (int i = 1; i <= n; i++) {
    dp[0][i] = max(dp[1][i - 1] + a[i], dp[0][i - 1]);
    dp[1][i] = max(dp[1][i - 1] + b[i], dp[1][i - 1]);
  }
  printf("%lld\n", max(dp[0][n], dp[1][n]));
  return 0;
}
