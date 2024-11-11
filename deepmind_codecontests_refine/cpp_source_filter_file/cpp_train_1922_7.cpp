#include <bits/stdc++.h>
using namespace std;
long long dp[5010][5010], sum[5010], n, m, k, t;
long long rec(int i, int j) {
  if (j < 0 || i <= 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = max(rec(i - 1, j - m) + sum[j] - sum[j - m], rec(i, j - 1));
}
int main() {
  cin >> n >> m >> k;
  long long a[n + 1];
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  for (int i = 1; i < n + 1; i++) sum[i] = sum[i - 1] + a[i];
  memset(dp, -1, sizeof(dp));
  cout << rec(k, n);
  return 0;
}
