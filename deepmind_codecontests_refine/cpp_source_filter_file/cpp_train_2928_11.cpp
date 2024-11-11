#include <bits/stdc++.h>
using namespace std;
const long long N = 201;
const long long K = 201;
const long long X = 201;
long long dp[N][X];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k, x;
  cin >> n >> k >> x;
  vector<long long> picBeauty;
  picBeauty.push_back(-1);
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    picBeauty.push_back(x);
  }
  long long minimumPosts = n / k;
  if (x < minimumPosts) {
    cout << -1 << endl;
    return 0;
  }
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= x; j++) {
      dp[i][j] = 0;
    }
  }
  for (long long i = 1; i <= n; i++) {
    dp[i][1] = picBeauty[i];
  }
  long long flag = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 2; j <= i && j <= x; j++) {
      long long tempFlag = 0;
      long long backAllowed = i - k;
      for (long long y = i - 1; y >= 1 && y >= backAllowed; y--) {
        if (dp[y][j - 1] > 0)
          dp[i][j] = max(dp[i][j], dp[y][j - 1] + picBeauty[i]);
      }
    }
  }
  long long ans = 0;
  for (long long i = n - k + 1; i <= n; i++) {
    ans = max(ans, dp[i][x]);
  }
  cout << ans << endl;
  return 0;
}
