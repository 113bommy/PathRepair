#include <bits/stdc++.h>
using namespace std;
bool dp[505][505];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  long long a[1000], b[1000];
  cin >> n >> k;
  long long sr = 0, sb = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    sb += a[i];
    sr += b[i];
  }
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      dp[i][j] = dp[i - 1][(j + k - (a[i - 1] % k)) % k];
      for (int l = 0; l <= min(k - 1, a[i - 1]); l++) {
        dp[i][j] |= (dp[i - 1][(k + j - l) % k] and
                     ((a[i - 1] - l) % k + b[i - 1] >= k));
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    if (dp[n][i]) ans = max(ans, (sr + sb - i) / k);
  }
  cout << ans << endl;
  return 0;
}
