#include <bits/stdc++.h>
using namespace std;
int n, m, a[410][410], dp[410][410], pre[410][160010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  int ans = 0;
  for (int L = 1; L <= n; L++) {
    for (int i = 1; i <= m; i++)
      dp[i][i] = max(dp[i][i], pre[i][a[L][i]]), ans = max(ans, L - dp[i][i]);
    for (int len = 2; len <= m; len++) {
      for (int i = 1; i + len - 1 <= m; i++) {
        int j = i + len - 1;
        if (a[L][i] == a[L][j])
          dp[i][j] = L;
        else
          dp[i][j] = max(max(dp[i + 1][j], dp[i][j - 1]),
                         max(dp[i][j], max(pre[j][a[L][i]], pre[i][a[L][j]])));
        ans = max(ans, (j - i + 1) * (L - dp[i][j]));
      }
    }
    for (int i = 1; i <= m; i++) pre[i][a[L][i]] = L;
  }
  printf("%d\n", ans);
  return 0;
}
