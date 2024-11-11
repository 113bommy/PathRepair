#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
long long arr[N], dp[N], dp2[N];
int32_t main() {
  long long n;
  cin >> n;
  long long mx = 0;
  dp[0] = dp2[n - 1] = 1;
  for (long long i = 0; i < n; i++) cin >> arr[i];
  for (long long i = 1; i < n; i++) dp[i] = min(dp[i - 1] + 1, arr[i]);
  for (long long i = n - 2; i >= 0; i--) dp2[i] = min(dp2[i + 1] + 1, arr[i]);
  for (long long i = 0; i < n; i++) mx = max(mx, min(dp[i], dp2[i]));
  cout << mx;
  return 0;
}
