#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = (int)1e9 + 99;
const int N = 88;
const int K = 14;
int dp[K][N];
int g[N][N];
int a[N];
int ANS = INF;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &g[i][j]);
  while ((double)clock() / CLOCKS_PER_SEC < 0.2) {
    for (int i = 0; i < n; i++) a[i] = rng() & 1;
    for (int i = 0; i <= k; i++)
      for (int j = 0; j < n; j++) dp[i][j] = INF;
    dp[0][0] = 0;
    for (int t = 0; t < k; t++) {
      for (int v = 0; v < n; v++)
        for (int u = 0; u < n; u++) {
          if (a[v] == a[u]) continue;
          dp[t + 1][u] = min(dp[t + 1][u], dp[t][v] + g[v][u]);
        }
    }
    ANS = min(ANS, dp[k][0]);
  }
  printf("%d\n", ANS);
  return 0;
}
