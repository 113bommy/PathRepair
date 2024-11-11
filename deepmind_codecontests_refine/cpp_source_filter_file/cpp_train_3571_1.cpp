#include <bits/stdc++.h>
using namespace std;
double dp[1010][1010];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
    dp[0][i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] += double(i) / (i + j);
      if (j >= 3) {
        dp[i][j] += (double)j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) /
                    (i + j - 2) * dp[i][j - 3];
      }
      if (i >= 1 && j >= 2) {
        dp[i][j] += (double)j / (i + j) * (j - 1) / (i + j - 1) * (i) /
                    (i + j - 2) * dp[i - 1][j - 2];
      }
    }
  }
  printf("%.9f", dp[n][m]);
}
