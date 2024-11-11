#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
bool comp(long long a, long long b) { return a > b; }
void sol() {}
int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<long long>> wave(n, vector<long long>(3));
  for (int i = 0; i < n; i++) {
    cin >> wave[i][0];
    cin >> wave[i][1];
    cin >> wave[i][2];
  }
  vector<long long> dp(n + 1);
  for (int i = 0; i <= n; i++) {
    dp[i] = -1;
  }
  dp[0] = 0;
  long long ans = 1ll << 62;
  for (int i = 0; i <= n; i++) {
    if (dp[i] != -1) {
      long long rem = k, cur = dp[i];
      for (int j = i; j < n; j++) {
        long long cntrel = ((max(0ll, wave[j][2] - rem) + k - 1) / k);
        if (cntrel > wave[j][1] - wave[j][0]) {
          break;
        }
        rem = rem + cntrel * k - wave[j][2];
        cur += wave[j][2];
        if (j + 1 < n) {
          if (wave[j][1] + cntrel < wave[j + 1][1]) {
            if (dp[j + 1] != -1)
              dp[j + 1] = min(dp[j + 1], cur + rem);
            else
              dp[j + 1] = cur + rem;
          }
        } else {
          ans = min(ans, cur);
        }
      }
    }
  }
  if (ans != 1ll << 62)
    cout << ans;
  else
    cout << -1;
}
