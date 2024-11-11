#include <bits/stdc++.h>
using namespace std;
const int N = 22;
const int M = 22;
const int INF = 1e7;
int n, m;
int dp[1 << N];
char str[N][M];
int val[N][M], cst[N][M], msk[N][M];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", str[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &val[i][j]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int total = 0;
      int maxn = 0;
      for (int k = 0; k < n; k++) {
        if (str[i][j] == str[k][j]) {
          msk[i][j] |= (1 << k);
          total += val[k][j];
          maxn = max(maxn, val[k][j]);
        }
      }
      cst[i][j] = total - maxn;
    }
  }
  for (int i = 1; i < (1 << n); i++) dp[i] = INF;
  dp[0] = 0;
  for (int i = 1; i < (1 << n); i++) {
    int first = 0;
    while ((i & (1 << first)) == 0) first++;
    for (int j = 0; j < m; j++) {
      dp[i] = min(dp[i], dp[i ^ (1 << first)] + val[first][j]);
      dp[i] = min(dp[i], dp[i & (i ^ msk[first][j])] + cst[first][j]);
    }
  }
  printf("%d\n", dp[(1 << n) - 1]);
}
