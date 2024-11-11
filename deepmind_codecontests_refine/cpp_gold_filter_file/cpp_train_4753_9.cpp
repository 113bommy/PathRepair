#include <bits/stdc++.h>
using namespace std;
int dp[505][505], nm[505][505];
int pre[505][505], nclass[505][505];
int h[505], lcnt[505];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  string str[n];
  int i, j, l;
  for (i = 0; i < n; i++) {
    cin >> str[i];
    lcnt[i] = 0;
    for (j = 0; j < m; j++) {
      lcnt[i] += (str[i][j] == '1');
      for (l = j; l < m; l++) {
        if (l == j) {
          pre[j][l] = 1;
          nclass[j][l] = (str[i][l] == '1');
        } else {
          pre[j][l] = pre[j][l - 1] + 1;
          nclass[j][l] = nclass[j][l - 1] + (str[i][l] == '1');
        }
      }
    }
    for (j = 0; j <= m; j++) h[j] = 10000000;
    for (j = 0; j < m; j++)
      for (l = j; l < m; l++) {
        h[nclass[j][l]] = min(h[nclass[j][l]], pre[j][l]);
      }
    h[0] = 0;
    for (j = 0; j <= m; j++) {
      nm[i][j] = h[j];
    }
  }
  for (i = 0; i < n; i++)
    for (j = 0; j <= k; j++) {
      dp[i][j] = 10000000;
    }
  for (j = 0; j <= k; j++) dp[0][j] = nm[0][max(0, lcnt[0] - j)];
  for (l = 0; l <= k; l++) {
    for (i = 0; i < n - 1; i++)
      for (j = 0; j + l <= k; j++) {
        dp[i + 1][j + l] = min(dp[i + 1][j + l],
                               dp[i][l] + nm[i + 1][max(0, lcnt[i + 1] - j)]);
      }
  }
  cout << dp[n - 1][k] << endl;
  return 0;
}
