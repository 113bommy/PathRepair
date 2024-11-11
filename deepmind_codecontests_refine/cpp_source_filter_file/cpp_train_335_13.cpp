#include <bits/stdc++.h>
using namespace std;
long long dp[2000001];
int sauske() {
  int n;
  cin >> n;
  cout << dp[n] % 1000000009 << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 0;
  dp[3] = 4;
  dp[4] = 4;
  for (int i = 5; i < 2000001; i++) {
    dp[i] = (dp[i - 1] + (2 * dp[i - 2]) % 1000000009 + (i % 3 == 0 ? 4 : 0)) %
            1000000009;
  }
  cin >> t;
  while (t--) sauske();
}
