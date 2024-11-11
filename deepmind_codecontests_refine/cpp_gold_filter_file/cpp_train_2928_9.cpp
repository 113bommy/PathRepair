#include <bits/stdc++.h>
using namespace std;
const int N = 203;
int n, k, x;
int val[N];
long long dp[N][N];
int main() {
  scanf("%d %d %d", &n, &k, &x);
  if (x < n / k) return puts("-1") & 0;
  for (int i = 1; i <= n; i++) scanf("%d", val + i);
  for (int i = 1; i <= n; i++)
    for (int j = (i + k - 1) / k; j <= min(x, i); j++)
      for (int w = max(i - k, 0); w < i; w++)
        dp[i][j] = max(dp[i][j], dp[w][j - 1] + val[i]);
  long long ans = 0;
  for (int i = n; i > n - k; i--) ans = max(ans, dp[i][x]);
  cout << ans << endl;
}
