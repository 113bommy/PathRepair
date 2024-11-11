#include <bits/stdc++.h>
using namespace std;
int arr[17][10005], nor[17][17], downup[17][17], dp[17][17][132000], p[18], n,
    m;
int solve(int last, int first, int mask) {
  if (dp[last][first][mask] != -1) return dp[last][first][mask];
  bool lesa = 0;
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if ((int)(mask & p[i]) == 0) {
      lesa = 1;
      int hoba = first;
      if (first == 0) hoba = i;
      ret = max(ret, min(solve(i, hoba, (int)(mask | p[i])), nor[last][i]));
    }
  }
  if (!lesa) return downup[last][first];
  return dp[last][first][mask] = ret;
}
int main() {
  p[0] = 1;
  for (int i = 1; i <= 16; i++) p[i] = p[i - 1] * 2;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    nor[i][0] = nor[0][i] = downup[i][0] = downup[0][i] = 1e9;
    for (int j = 1; j <= n; j++) {
      nor[i][j] = downup[i][j] = 1e9;
      for (int k = 1; k <= m; k++) {
        nor[i][j] = min(nor[i][j], abs(arr[i][k] - arr[j][k]));
        if (k != m) {
          downup[i][j] = min(downup[i][j], abs(arr[i][k] - arr[j][k + 1]));
        }
      }
    }
  }
  printf("%d", solve(0, 0, 0));
  return 0;
}
