#include <bits/stdc++.h>
using namespace std;
int dp[110][10010], n, m, l[110], r[110], t[10010], v[10010];
int main() {
  scanf("%d%d", &n, &m);
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &l[i], &r[i]);
    memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
    int s = 0, e = 0;
    int len = r[i] - l[i];
    for (int j = 0; j < r[i] - n; j++) {
      while (e > s && v[e - 1] >= dp[i - 1][j]) e--;
      v[e] = dp[i - 1][j];
      t[e++] = j;
    }
    for (int j = n; j >= 0; j--) {
      if (r[i] < j) continue;
      while (e > s && t[s] < r[i] - j - len) s++;
      while (e > s && v[e - 1] >= dp[i - 1][r[i] - j]) e--;
      v[e] = dp[i - 1][r[i] - j];
      t[e++] = r[i] - j;
      if (e > s) dp[i][j] = min(dp[i][j], v[s] + 1);
    }
    s = e = 0;
    for (int j = 0; j <= n; j++) {
      if (e > s && t[s] < j - len) s++;
      if (e > s) dp[i][j] = min(dp[i][j], v[s] + 2);
      while (e > s && v[e - 1] >= dp[i - 1][j]) e--;
      v[e] = dp[i - 1][j], t[e++] = j;
    }
  }
  if (dp[m][n] == 0x3f3f3f3f)
    puts("Hungry");
  else {
    puts("Full");
    printf("%d\n", dp[m][n]);
  }
  return 0;
}
