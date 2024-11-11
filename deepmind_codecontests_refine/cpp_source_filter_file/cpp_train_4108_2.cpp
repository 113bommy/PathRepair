#include <bits/stdc++.h>
long long N = 100000;
using namespace std;
signed main() {
  long long n;
  cin >> n;
  vector<long long> v(n), fr(N + 5);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    fr[v[i]]++;
  }
  vector<long long> dp(N + 5);
  dp[0] = 0;
  dp[1] = fr[1];
  dp[2] = fr[2];
  for (long long i = 3; i <= N; i++) {
    dp[i] = max(dp[i - 3], dp[i - 2]) + fr[i] * i;
  }
  cout << max(dp[N], dp[N - 1]);
}
