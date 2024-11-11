#include <bits/stdc++.h>
using namespace std;
long long dp[25][2][4];
int digit[25];
long long func(int len, int sum, int limit) {
  if (len < 0) return 1;
  if (dp[len][limit][sum]) return dp[len][limit][sum];
  if (sum >= 3) return dp[len][limit][sum] = 0;
  long long cnt = 0;
  int p = limit ? digit[len] : 9;
  for (int i = 0; i <= p; i++) {
    cnt += func(len - 1, sum + (i == 0 ? 0 : 1), (i == p) && limit);
  }
  return dp[len][limit][sum] = cnt;
}
long long solve(long long n) {
  int k = 0;
  memset(dp, 0, sizeof dp);
  while (n) {
    digit[k++] = n % 10;
    n /= 10;
  }
  return func(k - 1, 0, 1);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    printf("%lld\n", solve(r) - solve(l - 1));
  }
  return 0;
}
