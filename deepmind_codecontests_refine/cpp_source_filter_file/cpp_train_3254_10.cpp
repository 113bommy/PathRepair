#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long power(long long a, long long b);
long long a[4001];
long long dp[4000][1001];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= 2 * n; i++) cin >> a[i];
    vector<long long> b;
    long long prev = 1;
    long long val = (a[1]);
    for (long long i = 2; i <= 2 * n; i++) {
      if (a[i] > val) {
        b.push_back(i - prev);
        prev = i;
        val = a[i];
      }
    }
    b.push_back(2 * n + 1 - prev);
    if (b.size() > n) {
      cout << "YES"
           << "\n";
      continue;
    }
    sort(b.begin(), b.end());
    for (long long i = 0; i < b.size(); i++) {
      for (long long j = 0; j <= n; j++) {
        if (j == 0)
          dp[i][j] = 1;
        else
          dp[i][j] = 0;
      }
    }
    dp[0][b[0]] = 1;
    for (long long i = 1; i < b.size(); i++) {
      for (long long j = 1; j <= n; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= b[i]) {
          dp[i][j] |= dp[i - 1][j - b[i]];
        }
      }
    }
    if (dp[b.size() - 1][n])
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2)
      b--, res = res * a;
    else
      b = b / 2, a *= a;
  }
  return res;
}
