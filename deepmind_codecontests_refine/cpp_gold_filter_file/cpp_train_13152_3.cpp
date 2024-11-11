#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, k = 0;
  cin >> n;
  std::vector<long long int> v(3, 0);
  for (i = 0; i < 3; i++) cin >> v[i];
  sort(v.begin(), v.end());
  long long int a = v[0];
  long long int b = v[1];
  long long int c = v[2];
  vector<long long int> dp(n + 3, -99);
  dp[0] = 0;
  for (i = 1; i <= n; i++) {
    dp[i] = -99999999;
    if (i - a >= 0) dp[i] = max(dp[i], dp[i - a] + 1);
    if (i - b >= 0) dp[i] = max(dp[i], dp[i - b] + 1);
    if (i - c >= 0) dp[i] = max(dp[i], dp[i - c] + 1);
  }
  cout << dp[n] << endl;
  return 0;
}
