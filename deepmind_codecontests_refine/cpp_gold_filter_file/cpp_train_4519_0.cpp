#include <bits/stdc++.h>
using namespace std;
int mtr[2010][2010];
long long sm[2010];
long long cn[2010];
long long dp[2010][2010];
long long ncr(long long n, long long r) {
  if (n == r) return 1;
  if (r == 0) return 1;
  if (dp[n][r] != -1) return dp[n][r];
  dp[n][r] = ncr(n - 1, r - 1) + ncr(n - 1, r);
  return dp[n][r];
}
int main() {
  memset(dp, -1, sizeof dp);
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  int i;
  for (i = 0; i < n; i++) {
    mtr[i][i] = -1;
  }
  int j, x;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      scanf("%d", &x);
      if (x != -1) {
        cn[i]++;
        cn[j]++;
        sm[i] += x;
        sm[j] += x;
      }
    }
  }
  long long rs = 0, dv = 0;
  for (i = 0; i < n; i++) {
    rs += sm[i] * ncr(cn[i] - 1, k - 1);
    dv += ncr(cn[i], k);
  }
  printf("%I64d\n", rs / dv);
}
