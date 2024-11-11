#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000000 + 10;
long long dp[maxn], f[maxn];
int main() {
  int n;
  cin >> n;
  f[0] = 0;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = (3 * f[i - 1]) % 1000000007;
    f[i] = ((2 * f[i - 1]) + dp[i - 1]) % 1000000007;
  }
  cout << dp[n] % 1000000007;
}
