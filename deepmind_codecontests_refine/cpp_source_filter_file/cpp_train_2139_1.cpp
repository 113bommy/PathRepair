#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool debug = false;
int a[16], b[26], dp[4005][4005];
char sa[4005], sb[4005];
int main() {
  int ti, td, tr, te;
  scanf("%d%d%d%d", &ti, &td, &tr, &te);
  scanf("%s%s", sa + 1, sb + 1);
  for (n = 1; sa[n]; n++) dp[n][0] = td * n;
  for (m = 1; sb[m]; m++) dp[0][m] = ti * m;
  for (int i = 1; i < n; i++) {
    memset(b, 0, sizeof b);
    for (int j = 1; j < m; j++) {
      dp[i][j] = dp[i - 1][j - 1] + (sa[i] != sb[j]) * tr;
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + td);
      dp[i][j] = min(dp[i][j], dp[i][j - 1] + ti);
      int x = a[sb[j] - 'a'], y = b[sa[i] - 'a'];
      if (x && y) {
        dp[i][j] = min(dp[i][j], dp[x - 1][y - 1] + td * (i - x - 1) +
                                     ti * (j - y - 1) + te);
      }
      b[sb[j] - 'a'] = j;
    }
    a[sa[i] - 'a'] = i;
  }
  printf("%d\n", dp[n - 1][m - 1]);
  return 0;
}
