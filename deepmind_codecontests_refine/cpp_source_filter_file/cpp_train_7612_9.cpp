#include <bits/stdc++.h>
long long dp[3][200005];
int main() {
  int n;
  long long l, r;
  scanf("%d %lld %lld", &n, &l, &r);
  int ml, mr;
  ml = l % 3;
  mr = r % 3;
  long long n0, n1, n2;
  long long mn = r - l + 1 - (3 - ml) - (mr + 1);
  n0 = mn / 3;
  n1 = n0;
  n2 = n0;
  if (ml == 0) {
    n0++;
    n1++;
    n2++;
  } else if (ml == 1) {
    n1++;
    n2++;
  } else {
    n2++;
  }
  if (mr == 0) {
    n0++;
  } else if (mr == 1) {
    n0++;
    n1++;
  } else {
    n0++;
    n1++;
    n2++;
  }
  dp[0][1] = n0;
  dp[1][1] = n1;
  dp[2][1] = n2;
  int i;
  for (i = 2; i <= n; i++) {
    dp[0][i] = (dp[0][i - 1] * n0 + dp[1][i - 1] * n2 + dp[2][i - 1] * n1) %
               1000000009;
    dp[1][i] = (dp[0][i - 1] * n1 + dp[1][i - 1] * n0 + dp[2][i - 1] * n2) %
               1000000009;
    dp[2][i] = (dp[0][i - 1] * n2 + dp[1][i - 1] * n1 + dp[2][i - 1] * n0) %
               1000000009;
  }
  printf("%lld\n", dp[0][n]);
}
