#include <bits/stdc++.h>
const int N = 1005;
std::bitset<N> dp[14], tmp;
int main() {
  dp[0][0] = 1;
  for (int i = 1; i <= 13; i++) {
    tmp = dp[i - 1];
    dp[i] |= tmp << 1;
    dp[i] |= tmp << 5;
    dp[i] |= tmp << 10;
    dp[i] |= tmp << 50;
  }
  int n, ans = dp[13].count();
  scanf("%d", &n);
  if (n <= 13)
    printf("%d\n", int(dp[n].count()));
  else
    printf("%lld\n", 1LL * (n - 13) * 49 + ans);
  return 0;
}
