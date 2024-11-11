#include <bits/stdc++.h>
using namespace std;
const long long N = 1000005;
const long long mo = 998244353;
long long n, a, dp[N], ans;
signed main() {
  cin >> n;
  dp[0] = dp[1] = 1;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    if (x == 1) a++;
  }
  for (long long i = 2; i <= a; i++)
    dp[i] = (dp[i - 2] * (i - 1) % mo + dp[i - 1]) % mo;
  ans = dp[a];
  for (long long i = a + 1; i <= n; i++) ans = ans * i % mo;
  cout << ans;
}
