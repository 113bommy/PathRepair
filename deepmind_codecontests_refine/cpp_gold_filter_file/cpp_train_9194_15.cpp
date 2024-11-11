#include <bits/stdc++.h>
using namespace std;
long long int modn(long long int a) {
  while (a + 1000000007 < 0) a += 1000000007;
  return (a + 1000000007) % 1000000007;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long int T;
  cin >> T;
  long long int dp[102][2502];
  dp[0][0] = 1;
  for (long long int i = 1; i <= 101; i++) {
    for (long long int k = 0; k <= 2501; k++)
      for (long long int j = 0; j <= k && j <= 25; j++) {
        dp[i][k] = (dp[i][k] + dp[i - 1][k - j]) % 1000000007;
      }
  }
  for (long long int TC = 1; TC <= T; TC++) {
    string second;
    cin >> second;
    long long int ans = 0;
    for (long long int i = 0; i < second.size(); i++) ans += second[i];
    ans -= second.size() * 'a';
    cout << modn(dp[second.size()][ans] - 1) << "\n";
  }
  return 0;
}
