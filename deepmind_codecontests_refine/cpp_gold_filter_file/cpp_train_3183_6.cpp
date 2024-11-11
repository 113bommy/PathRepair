#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int dp[N][10];
int nt[N][10][N], a[N], n, cnt[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 8; j++) cnt[j] = 0;
    for (int j = 1; j <= 8; j++)
      for (int k = 1; k <= n; k++) nt[i][j][k] = (int)1e9;
    for (int j = i; j <= n; j++) {
      cnt[a[j]]++;
      nt[i][a[j]][cnt[a[j]]] = j;
    }
  }
  int ans = 0;
  for (int num = 0; num * 8 <= n; num++) {
    for (int i = 0; i < 1 << 8; i++)
      for (int k = 0; k <= 8; k++) dp[i][k] = (int)1e9;
    dp[0][0] = 1;
    for (int i = 0; i < 256; i++) {
      for (int j = 0; j <= 8; j++) {
        for (int k = 1; k <= 8; k++) {
          if ((1 << k - 1) & i) continue;
          if (dp[i][j] > n) continue;
          int s = i ^ (1 << k - 1);
          dp[s][j] = min(dp[s][j], nt[dp[i][j]][k][num] + 1);
          dp[s][j + 1] = min(dp[s][j + 1], nt[dp[i][j]][k][num + 1] + 1);
        }
      }
    }
    for (int i = 0; i <= 8; i++)
      if (dp[255][i] < n + 2) ans = max(ans, 8 * num + i);
  }
  printf("%d\n", ans);
}
