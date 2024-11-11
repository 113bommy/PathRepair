#include <bits/stdc++.h>
using namespace std;
int dp[401][401][401];
int a[410];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n + 1; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      dp[i][j][0] = a[j] - a[i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int k = 0; k <= n; ++k) {
      int j = i;
      int cur = i;
      while (cur <= n) {
        if (dp[i][j][k] > a[cur] - a[j]) {
          dp[i][cur][k + 1] = max(a[cur] - a[j], dp[i][j][k]);
          cur++;
        } else {
          while (j + 1 < cur) {
            if (max(dp[i][j][k], a[cur] - a[j]) <
                max(dp[i][j + 1][k], a[cur] - a[j + 1])) {
              break;
            }
            j++;
          }
          int t = max(dp[i][j][k], a[cur] - a[j]);
          dp[i][cur][k + 1] = t;
          cur++;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    int s, f, c, k;
    scanf("%d%d%d%d", &s, &f, &c, &k);
    long long t = (long long)dp[s][f][k] * c;
    ans = max(ans, t);
  }
  cout << ans << endl;
}
