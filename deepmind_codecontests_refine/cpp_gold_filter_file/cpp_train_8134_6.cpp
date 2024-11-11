#include <bits/stdc++.h>
using namespace std;
const long long N = (long long)3e5 + 1;
long long arr[N];
long long offers[N];
long long dp[5005];
long long n, m, k;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  sort(arr + 1, arr + n + 1);
  n = k;
  for (long long i = 0; i < N; i++) offers[i] = -1;
  for (long long i = 1; i <= m; i += 1) {
    long long a, b;
    cin >> a >> b;
    offers[a] = max(offers[a], b);
  }
  long long sum[5005];
  sum[0] = 0;
  for (long long i = 1; i <= n; i += 1) {
    sum[i] = sum[i - 1] + arr[i];
  }
  dp[0] = 0;
  for (long long i = 1; i <= n; i += 1) {
    dp[i] = sum[i];
    for (long long j = 1; j <= i; j += 1) {
      if (offers[j] != -1)
        dp[i] = min(dp[i], dp[i - j] + sum[i] - sum[i - j + offers[j]]);
    }
  }
  cout << dp[n];
}
