#include <bits/stdc++.h>
using namespace std;
int n, K, Aim, a[2222], dp[2222][2222];
int Trans(int s, int t) {
  bool cover = false;
  for (int i = (0); i <= (t - 1); i++)
    if (s & (1 << (i))) cover = true;
  if (cover) return (1 << (t));
  return min(s + (1 << (t)), Aim);
}
int main() {
  scanf("%d%d", &n, &K);
  Aim = (1 << (K - 1));
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  dp[0][0] = 1;
  for (int i = (0); i <= (n - 1); i++)
    for (int s = (0); s <= (Aim - 1); s++)
      if (dp[i][s]) {
        if (a[i + 1]) {
          int nxtS = Trans(s, a[i + 1] >> 2);
          dp[i + 1][nxtS] = (dp[i + 1][nxtS] + dp[i][s]) % 1000000007;
        } else {
          int nxtS = Trans(s, 0);
          dp[i + 1][nxtS] = (dp[i + 1][nxtS] + dp[i][s]) % 1000000007;
          nxtS = Trans(s, 1);
          dp[i + 1][nxtS] = (dp[i + 1][nxtS] + dp[i][s]) % 1000000007;
        }
      }
  printf("%d\n", dp[n][Aim]);
  return 0;
}
