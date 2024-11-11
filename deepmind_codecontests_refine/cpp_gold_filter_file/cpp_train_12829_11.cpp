#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int manx = 2e5 + 10;
int n, t, a[manx];
int vs1[210], vs2[210];
int dp[manx][210], bf[manx], net[manx];
int slove(int x) {
  int ans = -1, f = 0, temp;
  int i = vs2[x], j = vs1[x];
  while (1) {
    f++;
    temp = -1;
    if (f != 1) {
      i = net[i];
      j = bf[j];
    }
    if (i == -1 || j == -1 || i >= j) break;
    for (int k = 1; k <= 200; k++) temp = max(temp, dp[j - 1][k] - dp[i][k]);
    ans = max(ans, temp + f * 2);
  }
  return ans;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    memset(dp[0], 0, sizeof(dp[0]));
    memset(dp[n + 1], 0, sizeof(dp[n + 1]));
    for (int i = 1; i <= n; i++) {
      memset(dp[i], 0, sizeof(dp[i]));
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 200; j++) dp[i][j] = dp[i - 1][j];
      dp[i][a[i]]++;
    }
    memset(vs1, -1, sizeof(vs1));
    for (int i = 1; i <= n; i++) {
      bf[i] = vs1[a[i]];
      vs1[a[i]] = i;
    }
    memset(vs2, -1, sizeof(vs2));
    for (int i = n; i >= 1; i--) {
      net[i] = vs2[a[i]];
      vs2[a[i]] = i;
    }
    int ans = 1;
    for (int i = 1; i <= 200; i++) ans = max(ans, slove(i));
    printf("%d\n", ans);
  }
  return 0;
}
