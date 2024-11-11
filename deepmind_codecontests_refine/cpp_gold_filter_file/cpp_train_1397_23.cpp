#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
int m, n, k, a[maxn], b[maxn], dp[maxn][maxn * 201];
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    for (int i = 1; i <= n; i++) cin >> a[i];
    ;
    for (int i = 1; i <= n; i++) cin >> b[i];
    ;
    for (int i = 1; i <= n; i++) {
      b[i] *= k;
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= 20000; j++) {
        dp[i][j] = -1;
      }
    }
    dp[0][10000] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 20000; j++) {
        if (dp[i - 1][j] >= 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j]);
          if (j + a[i] - b[i] >= 0 && j + a[i] - b[i] <= 20000)
            dp[i][j + a[i] - b[i]] =
                max(dp[i][j + a[i] - b[i]], dp[i - 1][j] + a[i]);
        }
      }
    }
    if (dp[n][10000] <= 0)
      puts("-1");
    else
      cout << dp[n][10000] << endl;
  }
  return 0;
}
