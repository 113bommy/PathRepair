#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000006;
unsigned long long a, b, c;
unsigned long long x[maxn], y[maxn], z[maxn];
unsigned long long dp[202][202][202], ans;
int main() {
  cin >> a >> b >> c;
  for (int i = 1; i <= a; i++) cin >> x[i];
  for (int i = 1; i <= b; i++) cin >> y[i];
  for (int i = 1; i <= c; i++) cin >> z[i];
  sort(x + 1, x + 1 + a, greater<unsigned long long>());
  sort(y + 1, y + 1 + b, greater<unsigned long long>());
  sort(z + 1, z + 1 + b, greater<unsigned long long>());
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= a; i++)
    for (int j = 0; j <= b; j++)
      for (int k = 0; k <= c; k++) {
        if (i && j)
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + x[i] * y[j]);
        if (i && k)
          dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + x[i] * z[k]);
        if (j && k)
          dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + y[j] * z[k]);
      }
  ans = 0;
  for (int i = 0; i <= a; i++)
    for (int j = 0; j <= b; j++)
      for (int k = 0; k <= c; k++) ans = max(ans, dp[i][j][k]);
  cout << ans << "\n";
  return 0;
}
