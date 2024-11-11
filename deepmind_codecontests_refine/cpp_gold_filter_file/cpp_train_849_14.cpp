#include <bits/stdc++.h>
using namespace std;
long long int n, i, a[200100], dp[200100], x, ans;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 1; i < n + 1; i++) cin >> a[i];
  dp[0] = 0;
  for (i = 1; i < n + 1; i++)
    if (a[i] < 0)
      dp[i] = dp[i - 1] + 1;
    else
      dp[i] = dp[i - 1];
  x = 0;
  for (i = 0; i < n + 1; i++)
    if (dp[i] % 2 == 0) x = x + 1;
  ans = (x * (x - 1)) / 2;
  x = n - x + 1;
  ans = ans + (x * (x - 1)) / 2;
  cout << (n * (n + 1)) / 2 - ans << " " << ans;
}
