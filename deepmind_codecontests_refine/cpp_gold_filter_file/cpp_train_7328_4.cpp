#include <bits/stdc++.h>
using namespace std;
long dp[1100000];
long func(long n) {
  if (n == 0) {
    return 0;
  }
  if (n % 10 == n) {
    return 1;
  }
  if (n < 0) {
    return 1e9;
  }
  if (dp[n] != -1) {
    return dp[n];
  }
  long rc = 1e9;
  long tmp = n;
  while (tmp > 0) {
    long digit = tmp % 10;
    tmp /= 10;
    if (digit != 0) {
      rc = min(rc, func(n - digit) + 1);
    }
  }
  dp[n] = rc;
  return rc;
}
int main() {
  memset(dp, -1, sizeof(dp));
  long n;
  scanf("%ld", &n);
  printf("%ld", func(n));
  return 0;
}
