#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
bool G[maxn][maxn];
int dp[(1 << 20)][maxn];
bool check(int n) {
  int cnt = 0;
  for (int i = 1; i <= 20; i++) {
    if (n & (1 << (i - 1))) cnt++;
  }
  return cnt >= 3;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(G, false, sizeof(G));
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a][b] = G[b][a] = true;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[1 << (i - 1)][i] = 1;
  }
  for (int i = 1; i < (1 << n); i++) {
    int pos = 0;
    for (int l = 1; l <= 20; l++) {
      if (i & (1 << (l - 1))) {
        pos = l;
        break;
      }
    }
    for (int j = pos; j <= n; j++) {
      if (i & (1 << (j - 1))) {
        for (int k = pos; k <= n; k++) {
          if (!(i & (1 << (k - 1))) && G[j][k]) {
            dp[i | (1 << (k - 1))][k] += dp[i][j];
            if (G[pos][k] && check(i | (1 << (k - 1)))) ans += dp[i][j];
          }
        }
      }
    }
  }
  printf("%lld\n", ans / 2);
  return 0;
}
