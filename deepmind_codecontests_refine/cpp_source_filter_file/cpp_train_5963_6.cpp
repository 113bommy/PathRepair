#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int P[301][301];
int A[301], pos[301], n;
int dp[301], pr[301];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &P[i][j]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    pos[A[i]] = i;
  }
  dp[1] = pos[1];
  for (int i = 2; i <= n; i++) {
    if (pos[i] > dp[i - 1])
      dp[i] = dp[i - 1];
    else
      dp[i] = pos[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) pr[P[i][j]] = j;
    int res = 0, tres = 1000000000, cur;
    for (int j = 1; j <= n; j++) {
      if (A[dp[j]] != i) {
        if (pr[A[dp[j]]] < tres) {
          res = j;
          tres = pr[A[dp[j]]];
        }
      } else {
        cur = dp[j] + 1;
        while (cur <= n && A[cur] > j) cur++;
        if (cur <= n) {
          if (pr[A[cur]] < tres) {
            tres = pr[cur];
            res = j;
          }
        }
      }
    }
    if (i < n)
      printf("%d ", res);
    else
      printf("%d\n", res);
  }
  return 0;
}
