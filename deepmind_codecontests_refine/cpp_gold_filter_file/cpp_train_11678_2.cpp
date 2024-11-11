#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long a[n + 1];
  long long f = 0;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  a[0] = 0;
  long long dp[n + 1];
  memset(dp, 0, sizeof(dp));
  long long maxx = 0;
  for (int i = 1; i < n + 1; i++) {
    if (i == 1) {
      dp[i] = a[i] - k;
    } else {
      long long l = 1;
      long long ans = 0;
      long long cur = a[i];
      while (l <= m && i - l >= 0) {
        ans = max(ans, cur - k + dp[i - l]);
        ans = max(ans, cur - k);
        cur += a[i - l];
        l++;
      }
      dp[i] = ans;
    }
    maxx = max(dp[i], maxx);
  }
  cout << maxx;
  return 0;
}
