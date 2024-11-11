#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void oka() {
  long long n, i, j, k, ans = 0, cnt = 1;
  cin >> n;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  long long dp[n + 2], dp1[n + 2];
  for (i = 0; i <= n; i++) dp[i] = 1, dp1[i] = 1;
  for (i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      cnt++;
      dp[i] = dp[i - 1] + 1;
    } else {
      ans = max(ans, cnt);
      cnt = 0;
    }
  }
  ans = max(ans, cnt);
  for (i = n - 1; i >= 1; i--) {
    if (a[i] > a[i - 1]) dp1[i - 1] = dp1[i] + 1;
  }
  for (i = 0; i < n - 2; i++) {
    if (a[i + 2] > a[i]) {
      ans = max(ans, dp[i] + dp1[i + 2]);
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    oka();
  }
}
