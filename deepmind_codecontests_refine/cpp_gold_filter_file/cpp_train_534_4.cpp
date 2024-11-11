#include <bits/stdc++.h>
using namespace std;
const int maxn = 300100;
int dp[maxn][22];
int n, q;
int num[maxn], las[25];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  for (int i = 0; i <= 20; i++) las[i] = n + 1;
  for (int i = 0; i <= 20; i++) dp[n + 1][i] = n + 1;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= 20; j++) {
      dp[i][j] = n + 1;
    }
    for (int j = 0; j <= 20; j++) {
      if ((num[i] >> j) & 1) {
        dp[i][j] = i;
        for (int k = 0; k <= 20; k++) dp[i][k] = min(dp[i][k], dp[las[j]][k]);
        las[j] = i;
      }
    }
  }
  while (q--) {
    int xi, yi;
    int flag = 0;
    scanf("%d%d", &xi, &yi);
    for (int i = 0; i <= 20; i++) {
      if ((num[yi] >> i) & 1) {
        if (dp[xi][i] <= yi) {
          flag = 1;
        }
      }
    }
    if (flag)
      printf("Shi\n");
    else
      printf("Fou\n");
  }
  return 0;
}
