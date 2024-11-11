#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (long long j = 0; j < n; j++) {
      cin >> a[j];
      sum += a[j];
    }
    long long ret = INT_MIN;
    vector<long long> dp(n, INT_MIN);
    for (long long j = 0; j < n - 1; j++) {
      if (j == 0) {
        dp[j] = a[j];
      } else {
        dp[j] = max(a[j], dp[j - 1] + a[j]);
      }
      ret = max(ret, dp[j]);
    }
    vector<long long> dp1(n, INT_MIN);
    for (long long j = 1; j < n; j++) {
      if (j == 1) {
        dp1[j] = a[j];
      } else
        dp1[j] = max(a[j], dp1[j - 1] + a[j]);
      ret = max(ret, dp1[j]);
    }
    if (ret >= sum)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
