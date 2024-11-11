#include <bits/stdc++.h>
using namespace std;
int first[25], second[25], dp[205][205];
int call(int i, int j, int x, int y, int d, int n) {
  if (dp[i][j] == -1) {
    if ((i + x) * (i + x) + (j + y) * (j + y) > d * d)
      dp[i][j] = 1;
    else {
      dp[i][j] = 0;
      for (int k = 0; k < n; k++) {
        if (!call(i + first[k], j + second[k], x, y, d, n)) {
          return dp[i][j] = 1;
        }
      }
    }
  }
  return dp[i][j];
}
int main() {
  memset(dp, -1, sizeof(dp));
  int x, y, n, d;
  scanf("%d %d %d %d", &x, &y, &n, &d);
  for (int i = 0; i < n; i = i + 1) scanf("%d %d", &first[i], &second[i]);
  if (call(0, 0, x, y, d, n))
    printf("Anton\n");
  else
    printf("Dasha\n");
  return 0;
}
