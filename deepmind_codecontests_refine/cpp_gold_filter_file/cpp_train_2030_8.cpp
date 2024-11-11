#include <bits/stdc++.h>
using namespace std;
const int N = 1007;
int dp[N][N];
int br[N];
int n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (n > m) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> br[i];
    br[i] %= m;
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  int b = 0;
  for (int i = 1; i <= n; i++)
    for (int j = m - 1; j >= 0; j--) {
      int x = ((j - br[i]) % m + m) % m;
      if (dp[i - 1][x]) {
        dp[i][j] = 1;
        if (j == 0) b = true;
      }
      if (dp[i - 1][j]) dp[i][j] = 1;
    }
  if (b)
    cout << ("YES");
  else
    cout << ("NO");
  return 0;
}
