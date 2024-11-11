#include <bits/stdc++.h>
using namespace std;
long long int dp[1005];
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  int i;
  int mod = 1000000007;
  for (i = 1; i <= n; i++) cin >> a[i];
  dp[1] = 0;
  for (i = 1; i <= n; i++) {
    dp[i + 1] = (2 * dp[i] - dp[a[i]] + 2) % mod;
  }
  cout << dp[n + 1] << endl;
  return 0;
}
