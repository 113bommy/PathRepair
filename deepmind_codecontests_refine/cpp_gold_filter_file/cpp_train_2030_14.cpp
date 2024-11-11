#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int mod[1005];
bool dp[1005][1005];
int main(void) {
  int cnt = 0;
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    fill(mod, mod + 1001, 0);
    memset(dp, false, sizeof(dp));
    int s = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      a[i] %= m;
      s += a[i];
      if (s >= m) s %= m;
    }
    if (n > m) {
      printf("YES\n");
      continue;
    }
    dp[0][0] = true;
    bool ans = false;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i][j] = dp[i - 1][j];
      }
      for (int j = 0; j < m; j++) {
        if (dp[i - 1][j]) {
          if ((j + a[i - 1]) % m == 0) ans = true;
          dp[i][(j + a[i - 1]) % m] = true;
        }
      }
    }
    if (ans)
      puts("YES");
    else
      puts("NO\n");
  }
}
