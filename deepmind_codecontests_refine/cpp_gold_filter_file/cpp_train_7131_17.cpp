#include <bits/stdc++.h>
using namespace std;
const int maxn = 155;
int dp[maxn][maxn * maxn];
int n, K, s;
inline void up(int &x, int y) {
  if (x == -1 || x > y) x = y;
}
int main() {
  cin.ios_base::sync_with_stdio(false);
  cin >> n >> K >> s;
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  int x;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    for (int j = i - 1; j >= 0; j--) {
      for (int k = 0; k <= i * j; k++) {
        if (dp[j][k] >= 0) {
          up(dp[j + 1][k + i - (j + 1)], dp[j][k] + x);
        }
      }
    }
  }
  int ans = 1e9;
  for (int i = 0; i <= min(s, n * n); i++) {
    if (dp[K][i] >= 0) {
      ans = min(ans, dp[K][i]);
    }
  }
  cout << ans << endl;
  return 0;
}
