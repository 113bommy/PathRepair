#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int LOGN = 21;
int v[MAXN];
int dp[MAXN][LOGN];
int ult[LOGN];
int n, q;
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < LOGN; j++) {
      if ((v[i] & (1 << j)) == 0) continue;
      dp[i][j] = ult[j];
      int cara = ult[j];
      for (int k = 0; k < LOGN; k++) dp[i][k] = max(dp[i][k], dp[cara][k]);
    }
    for (int j = 0; j < LOGN; j++)
      if (v[i] & (1 << j)) ult[j] = i;
  }
  while (q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    bool ok = 0;
    for (int i = 0; i < LOGN; i++) {
      if ((v[a] & (1 << i)) == 0) continue;
      if (dp[b][i] != 0 && dp[b][i] <= a) ok = 1;
    }
    if (ok)
      printf("Shi\n");
    else
      printf("Fou\n");
  }
}
