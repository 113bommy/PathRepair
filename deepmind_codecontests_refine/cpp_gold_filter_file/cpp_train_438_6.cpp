#include <bits/stdc++.h>
using namespace std;
#pragma GCC push_options
#pragma GCC optimize("unroll-loops")
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long dp[n];
    for (long long i = 0; i < n; i++) {
      if (a[i] + i >= 0) {
        dp[i] = (i + a[i]) % n;
      } else {
        dp[i] = ((i + a[i]) % n + n) % n;
      }
    }
    sort(dp, dp + n);
    bool b = true;
    for (long long i = 0; i < n - 1; i++) {
      if (dp[i] == dp[i + 1]) {
        b = false;
        cout << "NO" << endl;
        break;
      }
    }
    if (b == true) {
      cout << "YES" << endl;
    }
  }
  return 0;
}
