#include <bits/stdc++.h>
using namespace std;
const long long mod = 999983;
const long long mxi = 10005;
long long dp[1000005][2], sm[1000005];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  ;
  long long n, m, x, y;
  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      if (ch == '#') {
        sm[j + 1]++;
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    sm[j] = sm[j] + sm[j - 1];
  }
  memset(dp, 0x3f3f3f3f, sizeof dp);
  dp[0][0] = dp[0][1] = 0;
  for (int i = 0; i < m; i++) {
    for (int j = x; j <= y; j++) {
      if (i + j > m) break;
      dp[i + j][0] = min(dp[i + j][0], dp[i][1] + sm[i + j] - sm[i]);
      dp[i + j][1] = min(dp[i + j][1], dp[i][0] + n * j - (sm[i + j] - sm[i]));
    }
  }
  cout << min(dp[m][0], dp[m][1]);
}
