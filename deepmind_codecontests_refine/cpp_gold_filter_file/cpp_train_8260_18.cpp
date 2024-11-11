#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int A[100100], N;
int dp[100100][21], ex[100100 * 20];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", A + i);
  for (int j = 0; j <= 20; j++) dp[N + 1][j] = 1000000000;
  for (int i = N; i >= 1; i--)
    for (int j = 0; j <= 20; j++) {
      dp[i][j] = dp[i + 1][j];
      if (A[i] & (1 << j)) dp[i][j] = i;
    }
  for (int i = 1; i <= N; i++) {
    int idx = i, val = A[i];
    while (idx != 1000000000) {
      ex[val] = 1;
      int res = 1000000000;
      for (int j = 0; j <= 20; j++)
        if (((val & (1 << j)) == 0) && dp[idx + 1][j] < res)
          res = dp[idx + 1][j];
      idx = res;
      if (idx != 1000000000) val |= A[idx];
    }
  }
  int ans = 0;
  for (int i = 0; i <= 2000000; i++) ans += ex[i];
  printf("%d\n", ans);
  return 0;
}
