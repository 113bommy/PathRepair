#include <bits/stdc++.h>
using namespace std;
long long dp[200][20], res;
int k, x[20][20];
long long solve(int rem, int diff) {
  if (rem == 0) {
    if (diff == 0)
      return 0LL;
    else
      return 1e18;
  }
  if (rem < 0) return 0;
  if (dp[rem][diff] != -1LL) return dp[rem][diff];
  long long ansmin = 1e18;
  int i, j, baad;
  for (i = 9; i >= 0; i--) {
    if (i == 0 && diff == 0) break;
    baad = (k + 1 - diff) * i + diff * ((i + 1) % 10);
    if (baad > rem) continue;
    if (i == 9)
      j = diff;
    else
      j = 0;
    long long x = solve(rem - baad, j);
    if (x >= 1e18 || x * 10LL >= 1e18) continue;
    ansmin = min(ansmin, x * 10LL + (long long)i);
  }
  return dp[rem][diff] = ansmin;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int i, j, n, l, t;
  for (i = 0; i < 10; i++) {
    x[i][0] = i;
    for (j = 1; j < 10; j++) x[i][j] = x[i][j - 1] + (i + j) % 10;
  }
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (i = 0; i <= n; i++) {
      for (j = 0; j <= k; j++) dp[i][j] = -1LL;
    }
    long long ansmin = 1e18;
    for (i = 9; i >= 0; i--) {
      if (x[i][k] > n) continue;
      int rem = n - x[i][k];
      int diff = 0;
      if ((i + k) >= 10) diff = (i + k) - 9;
      long long x = solve(rem, diff);
      if (x >= 1e18) continue;
      ansmin = min(ansmin, x * 10LL + (long long)i);
    }
    if (ansmin == 1e18) ansmin = -1LL;
    cout << ansmin << endl;
  }
}
