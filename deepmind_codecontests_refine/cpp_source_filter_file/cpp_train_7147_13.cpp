#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k, i, j, ans = 0, c = 0;
  cin >> n >> k;
  long long int a[n], t[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> t[i];
  for (i = 0; i < n; i++) {
    if (t[i] == 1) ans += a[i];
  }
  long long int dp[n];
  if (t[0] == 0)
    dp[0] = a[i];
  else
    dp[0] = 0;
  for (i = 1; i < n; i++) {
    if (t[i] == 1)
      dp[i] = dp[i - 1];
    else
      dp[i] = dp[i - 1] + a[i];
  }
  c = max(c, ans + dp[k - 1]);
  for (i = 1; i < n - k + 1; i++) {
    if (i != 0) c = max(c, ans + dp[i + k - 1] - dp[i - 1]);
  }
  cout << c;
  return 0;
}
