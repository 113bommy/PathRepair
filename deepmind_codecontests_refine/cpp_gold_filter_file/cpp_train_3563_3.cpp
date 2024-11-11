#include <bits/stdc++.h>
using namespace std;
const int maxn = 85;
const int inf = 0x3f3f3f3f;
int d[maxn][maxn], dp[maxn], col[maxn];
int n, k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  srand(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> d[i][j];
  int ans = inf, cnt = 5000;
  while (cnt--) {
    for (int i = 2; i <= n; i++) col[i] = rand() % 2;
    memset(dp, 63, sizeof(dp));
    dp[1] = 0;
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= n; j++)
        if (((i + col[j]) & 1) == 0) dp[j] = inf;
      for (int u = 1; u <= n; u++)
        if ((i + col[u]) & 1)
          for (int v = 1; v <= n; v++)
            if (((i + col[v]) & 1) == 0) dp[v] = min(dp[v], dp[u] + d[u][v]);
    }
    ans = min(ans, dp[1]);
  }
  cout << ans << "\n";
}
