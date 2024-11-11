#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;
int n;
long long L[1000 | 1];
long long R[1000 | 1];
double ans[1000 | 1];
double dp[1000 | 1][1000 | 1];
long long intersectIt(long long a, long long b, long long c, long long d) {
  if (d < a) {
    return 0;
  }
  if (c > b) {
    return 0;
  }
  if (c >= a && b >= d) {
    return d - c + 1;
  }
  if (c <= a && d <= b) {
    return d - a + 1;
  }
  if (c >= a && d >= b) {
    return b - c + 1;
  }
  if (c <= a && d >= b) {
    return b - a + 1;
  }
}
long long calcOnes(long long l, long long r) {
  long long ret = 0;
  long long powTen = 1;
  for (int i = 0; i < 19; ++i) {
    ret += intersectIt(l, r, powTen, 2LL * powTen - 1LL);
    powTen *= 10LL;
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%I64d%I64d", L + i, R + i);
    ans[i] = (double)calcOnes(L[i], R[i]);
  }
  int k;
  scanf("%d", &k);
  double res = 0.0;
  dp[0][0] = 1.0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i + 1][j + 1] = (ans[i] / (R[i] - L[i] + 1.0)) * dp[i][j];
      dp[i + 1][j] += dp[i][j] * (1 - (ans[i] / (R[i] - L[i] + 1.0)));
    }
  }
  for (int i = 0; i <= n; ++i) {
    if (i * 100 >= k * n) {
      res += dp[n][i];
    }
  }
  printf("%.9lf\n", res);
  return 0;
}
