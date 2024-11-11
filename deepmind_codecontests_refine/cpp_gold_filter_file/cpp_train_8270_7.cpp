#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long dp[200005];
long long getn(int n) {
  long long k = 1;
  while (k * (k + 1) / 2 <= n) k++;
  return k - 1;
}
int main() {
  long long n, a, b;
  cin >> a >> b;
  n = a + b;
  long long g = getn(a + b);
  n = g * (g + 1) / 2;
  dp[0] = 1;
  g = getn(n);
  for (int i = 1; i <= g; i++) {
    for (int j = 200000; j >= i; j--) {
      dp[j] = (dp[j] + dp[j - i]) % mod;
    }
  }
  long long ans = 0;
  for (int i = 0; i <= a; i++) {
    if (i + b < n) continue;
    ans = (ans + dp[i]) % mod;
  }
  cout << ans;
}
