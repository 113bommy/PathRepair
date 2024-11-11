#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long dp[2][3030];
long long a[3030];
long long b[3030];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= i;
    b[i] = a[i];
  }
  sort(b, b + n);
  int m = unique(b, b + n) - b;
  memset((dp), (0), sizeof(dp));
  for (int i = 0; i < n; i++) {
    long long val = 1e18;
    for (int j = 0; j < m; j++) {
      val = min(val, dp[0][j]);
      dp[1][j] = val + abs(a[i] - b[j]);
    }
    for (int j = 0; j < m; j++) dp[0][j] = dp[1][j];
  }
  long long ans = 1e18;
  for (int j = 0; j < m; j++) {
    ans = min(ans, dp[0][j]);
  }
  cout << ans << endl;
  return 0;
}
