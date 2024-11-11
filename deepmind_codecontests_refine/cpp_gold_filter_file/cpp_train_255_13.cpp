#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
char str[100][100];
int f[100][100], dp[1 << 21], sum[100][100];
int statu[100][100];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> str[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> f[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int maxv = 0;
      for (int k = 0; k < n; k++) {
        if (str[i][j] == str[k][j]) {
          sum[i][j] += f[k][j];
          maxv = max(maxv, f[k][j]);
          statu[i][j] |= (1 << k);
        }
      }
      sum[i][j] -= maxv;
    }
  }
  fill(dp, dp + (1 << 21), INF);
  dp[0] = 0;
  for (int i = 0; i < (1 << n) - 1; i++) {
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0) {
        int a = (1 << j);
        for (int k = 0; k < m; k++) {
          int b = statu[j][k];
          dp[i | a] = min(dp[i | a], dp[i] + f[j][k]);
          dp[i | b] = min(dp[i | b], dp[i] + sum[j][k]);
        }
      }
    }
  }
  cout << dp[(1 << n) - 1] << endl;
  return 0;
}
