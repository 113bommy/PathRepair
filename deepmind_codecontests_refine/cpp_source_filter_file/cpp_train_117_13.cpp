#include <bits/stdc++.h>
using namespace std;
long long dp[200005][10];
long long arr[200005][2][4];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    long long n;
    cin >> n;
    for (long long i = 0; i < 200005; i++)
      for (long long j = 0; j < 10; j++) dp[i][j] = -1;
    dp[0][0] = 0;
    long long ans = -1e18;
    for (long long i = 0; i < n; i++) {
      vector<long long> co[4];
      long long k;
      cin >> k;
      for (long long j = 0; j < k; j++) {
        long long c, d;
        cin >> c >> d;
        co[c].push_back(d);
      }
      for (long long j = 0; j < 2; j++)
        for (long long l = 1; l < 4; l++) arr[i][j][l] = -1;
      sort((co[1]).begin(), (co[1]).end());
      sort((co[2]).begin(), (co[2]).end());
      sort((co[3]).begin(), (co[3]).end());
      reverse((co[1]).begin(), (co[1]).end());
      reverse((co[2]).begin(), (co[2]).end());
      reverse((co[3]).begin(), (co[3]).end());
      if ((long long)co[1].size()) {
        arr[i][0][1] = co[1][0];
        arr[i][1][1] = 2 * co[1][0];
      }
      if ((long long)co[1].size() > 1) {
        arr[i][0][2] = co[1][0] + co[1][1];
        arr[i][1][2] = 2 * co[1][0] + co[1][1];
      }
      if ((long long)co[2].size()) {
        arr[i][0][1] = max(co[2][0], arr[i][0][1]);
        arr[i][1][1] = max(2 * co[2][0], arr[i][1][1]);
      }
      if ((long long)co[1].size() > 2) {
        arr[i][0][3] = co[1][0] + co[1][1] + co[1][2];
        arr[i][1][3] = 2 * co[1][0] + co[1][1] + co[1][2];
      }
      if ((long long)co[2].size() && ((long long)co[1].size())) {
        arr[i][0][2] = max(co[2][0] + co[1][0], arr[i][0][2]);
        arr[i][1][2] =
            max(co[2][0] + co[1][0] + max(co[2][0], co[1][0]), arr[i][1][2]);
      }
      if ((long long)co[3].size()) {
        arr[i][0][1] = max(co[3][0], arr[i][0][1]);
        arr[i][1][1] = max(2 * co[3][0], arr[i][1][1]);
      }
      for (long long j = 0; j < 10; j++) dp[i + 1][j] = dp[i][j];
      for (long long j = 0; j < 10; j++) {
        for (long long l = 1; l < 4; l++) {
          if (j + l < 10) {
            dp[i + 1][j + l] = max(dp[i][j] + arr[i][0][l], dp[i + 1][j + l]);
          } else {
            dp[i + 1][j + l - 10] =
                max(dp[i][j] + arr[i][1][l], dp[i + 1][j + l - 10]);
          }
        }
      }
    }
    for (long long j = 0; j < 10; j++) ans = max(ans, dp[n][j]);
    cout << ans;
  }
  return 0;
}
