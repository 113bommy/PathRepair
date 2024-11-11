#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int t, n;
long long a[MAXN], p[MAXN];
int dp[MAXN][500];
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      p[i] = p[i - 1] + a[i];
      for (int j = 1; j < 500; ++j) {
        dp[i][j] = 0;
      }
    }
    int ans = 1;
    for (int i = n; i >= 1; --i) {
      dp[i][1] = a[i];
      if (i != n and dp[i + 1][1] > dp[i][1]) dp[i][1] = dp[i + 1][1];
    }
    for (int j = 2; j < 500; ++j) {
      for (int i = n - j; i >= 1; --i) {
        if (dp[i + j][j - 1] > p[i + j - 1] - p[i - 1])
          dp[i][j] = p[i + j - 1] - p[i - 1];
        if (dp[i + 1][j] != 0 and dp[i + 1][j] > dp[i][j])
          dp[i][j] = dp[i + 1][j];
        if (dp[i][j] != 0) ans = j;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
