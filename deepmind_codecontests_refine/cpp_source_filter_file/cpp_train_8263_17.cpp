#include <bits/stdc++.h>
using namespace std;
int n, a, b, dp[1000005];
int x;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    if (x == 1)
      ++b;
    else
      ++a;
  }
  dp[1] = 1, dp[2] = 2;
  for (int i = 3; i <= b; ++i)
    dp[i] = (dp[i - 1] + 1LL * (i - 1) * dp[i - 2]) % 1000000007;
  int sol = dp[b];
  for (int i = b + 1; i <= a + b; ++i) sol = 1LL * sol * i % 1000000007;
  printf("%d\n", sol);
  return 0;
}
