#include <bits/stdc++.h>
using namespace std;
const int N = 63;
const int M = 17;
const long long INF = 1e18;
int dig[M], t;
long long dp[M][N];
long long C[N][N];
long long solve(int len, int f) {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1, x = 16; i <= 16; i++, x--)
    for (int j = 0; j <= len; j++) {
      dp[i][j] = dp[i - 1][j];
      for (int k = 1; k <= min(j, dig[x]); k++) {
        dp[i][j] += dp[i - 1][j - k] * C[j - f * (x == 1)][k];
      }
    }
  return dp[16][len];
}
char hex(int x) {
  if (x < 10) return '0' + x;
  return 'a' + x - 10;
}
long long k;
int main() {
  for (int i = 1; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }
  cin >> k >> t;
  for (int i = 1; i <= 16; i++) dig[i] = t;
  int len = 1;
  for (;; len++) {
    long long v = solve(len, 1);
    if (k <= v) break;
    k -= v;
  }
  for (int i = 1; i <= len; i++) {
    for (int j = (i == 1 ? 2 : 1); j <= 16; j++)
      if (dig[j]) {
        dig[j]--;
        long long v = solve(len - i, 0);
        if (k <= v) {
          cout << hex(j - 1);
          break;
        }
        k -= v;
        dig[j]++;
      }
  }
  return 0;
}
