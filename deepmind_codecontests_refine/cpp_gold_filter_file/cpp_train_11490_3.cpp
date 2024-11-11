#include <bits/stdc++.h>
using namespace std;
const int maxn = 6000;
const int inf = 1e9;
int a[maxn];
int dp[maxn][maxn];
int main() {
  int n, uk, sum;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(dp, 63, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    uk = i + 1;
    sum = a[i];
    for (int j = 0; j < n; j++)
      if (dp[i][j] < inf) {
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + a[i]);
        while (uk < n && sum < dp[i][j]) sum += a[uk++];
        if (sum >= dp[i][j]) {
          dp[uk][j + uk - i - 1] = min(sum, dp[uk][j + uk - i - 1]);
        }
      }
  }
  for (int i = 0; i < n; i++) {
    if (dp[n][i] < inf) {
      cout << i << endl;
      cerr << i << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}
