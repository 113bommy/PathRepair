#include <bits/stdc++.h>
const long long MAX_N = 3e5 + 10;
const long long MOD = 1e9 + 7;
using namespace std;
int a[MAX_N];
int dp[5001][5001];
int n, k, x;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  int x = ceil(n / (double)k);
  for (int i = 0; i <= 5000; ++i) {
    if (x * i > n) break;
    for (int j = 0; j <= 5000; ++j) {
      if ((x - 1) * j + x * i > n) break;
      if (!i and !j) continue;
      int p = (x - 1) * j + x * i;
      dp[i][j] = 1e9;
      if (i) dp[i][j] = min(dp[i][j], a[p] - a[p - x + 1] + dp[i - 1][j]);
      if (j) dp[i][j] = min(dp[i][j], a[p] - a[p - x + 2] + dp[i][j - 1]);
    }
  }
  if (n % k == 0)
    cout << dp[k][0];
  else
    cout << dp[n % k][k - (n % k)];
  return 0;
}
