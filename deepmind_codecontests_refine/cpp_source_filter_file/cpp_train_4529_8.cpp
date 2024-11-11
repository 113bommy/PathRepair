#include <bits/stdc++.h>
using namespace std;
const unsigned int INF = 2e9 + 239;
const int MAXN = 3e5 + 239;
const int MAXK = 5e3 + 239;
int a[MAXN];
int dp[MAXK][MAXK];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int len = n / k;
  for (int i = 0; i < MAXK; i++) {
    for (int j = 0; j < MAXK; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < MAXK; i++) {
    for (int j = 0; j < MAXK; j++) {
      int st = len * i + j;
      if (st + len <= n) {
        int end = st + len;
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[end - 1] - a[st]);
      }
      if (st + len + 1 <= n) {
        int end = st + len + 1;
        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + a[end - 1] - a[st]);
      }
    }
  }
  cout << dp[k][n % k] << endl;
}
