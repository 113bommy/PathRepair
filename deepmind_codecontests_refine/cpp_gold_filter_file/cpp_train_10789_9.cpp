#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int INF = 1000 * 1000 * 1000 + 7;
const long long LINF = INF * (long long)INF;
const int MAX1 = 1000 + 47;
const int MAX2 = 10000 + 47;
long long dp[MAX1][MAX2];
long long CNT[MAX1];
long long C[MAX1];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long w, b, x;
  cin >> n >> w >> b >> x;
  for (int i = (0); i < (n); i++) {
    cin >> CNT[i];
  }
  for (int i = (0); i < (n); i++) cin >> C[i];
  memset(dp, -1, sizeof(dp));
  dp[0][0] = w;
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (MAX2); j++) {
      if (dp[i][j] == -1) continue;
      for (int k = (0); k < (CNT[i] + 1); k++) {
        if (dp[i][j] - k * C[i] < 0) break;
        long long newVal = min(dp[i][j] - k * C[i] + x, w + b * (j + k));
        dp[i + 1][j + k] = max(dp[i + 1][j + k], newVal);
      }
    }
  }
  int ans = 0;
  for (int i = (0); i < (n + 1); i++) {
    for (int j = (0); j < (MAX2); j++) {
      if (dp[i][j] == -1) continue;
      ans = max(ans, j);
    }
  }
  cout << ans << endl;
  return 0;
}
