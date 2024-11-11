#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int gcd(long long int A, long long int B) {
  if (!B) return A;
  return gcd(B, A % B);
}
int main() {
  long long int n;
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  vector<long long int> dp(n, 1);
  long long int even_sum = 1;
  long long int odd_sum = 0;
  for (int i = 1; i < n; i++) {
    if (i % 2 == 0) {
      dp[i] += odd_sum;
    } else {
      dp[i] += even_sum;
    }
    dp[i] %= (long long int)(1e9 + 7);
    if (i % 2 == 0)
      even_sum += dp[i];
    else
      odd_sum += dp[i];
    even_sum %= (long long int)(1e9 + 7);
    odd_sum %= (long long int)(1e9 + 7);
  }
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dp[i];
    ans %= (long long int)(1e9 + 7);
  }
  cout << ans;
}
