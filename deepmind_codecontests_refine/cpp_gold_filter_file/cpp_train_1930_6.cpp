#include <bits/stdc++.h>
using namespace std;
long long const mod = (long long)1e9 + 7;
int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) scanf("%I64d", &a[i]);
  vector<long long> dp(n);
  for (long long i = 0; i < n; i++) a[i]--;
  for (long long i = 0; i < n - 1; i++)
    if (a[i] < a[i + 1])
      dp[i] = a[i];
    else
      dp[i] = a[i + 1];
  vector<long long> d(n);
  vector<long long> ans(n);
  ans[0] = a[0];
  d[0] = dp[0];
  for (long long i = 1; i < n; i++)
    if (a[i] == 0) {
      if (i + 1 < n) {
        ans[i + 1] = a[i + 1];
        d[i + 1] = dp[i + 1];
        i++;
      }
    } else {
      ans[i] = (d[i - 1] * dp[i - 1] + a[i]) % mod;
      if (dp[i - 1] < dp[i])
        d[i] = (mod + (d[i - 1] * dp[i - 1] + dp[i]) % mod) % mod;
      else
        d[i] = (d[i - 1] * dp[i] + dp[i]) % mod;
    }
  long long as = 0;
  for (long long i = 0; i < n; i++) as = (as + ans[i]) % mod;
  cout << as;
  return 0;
}
