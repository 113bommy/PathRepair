#include<bits/stdc++.h>

using namespace std;
  
int main() {
  int n, s, mod(998244353);
  cin >> n >> s;
  int arr[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  long long ans(0);
  vector<long long> dp(s + 1);
  
  for (int i = 0; i < n; ++i) {
    long long prev(dp[s]);
    for (int j = s; j >= 0; --j) {
      if ((dp[j] || j == 0) && j + arr[i] <= s) {
        dp[j + arr[i]] += j == 0 ? i + 1 : dp[j];
        dp[j + arr[i]] %= mod;
      }
    }
    ans += (dp[s] + mod - prev) * (n - i);
    ans %= mod;
  }
  
  cout << ans << '\n';
  return 0;
}
