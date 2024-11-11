#include <bits/stdc++.h>
using namespace std;
struct st {
  int x, y, z;
};
char str[111];
int arr[111][111];
int dp[111][111][12];
st from[111][111][12];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    for (int j = 0; j < m; j++) arr[i][j] = str[j] - '0';
  }
  memset(dp, -1, sizeof(dp));
  memset(from, -1, sizeof(from));
  for (int i = 0; i < m; i++) dp[0][i][arr[0][i] % (k + 1)] = arr[0][i];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int l = 0; l < k + 1; l++) {
        from[i][j][l] = {-1, -1, -1};
        int red = (l + (k + 1) - (arr[i][j] % (k + 1))) % (k + 1);
        if (j > 0 && dp[i - 1][j - 1][red] != -1 &&
            dp[i][j][k] < dp[i - 1][j - 1][red] + arr[i][j]) {
          dp[i][j][l] = dp[i - 1][j - 1][red] + arr[i][j];
          from[i][j][l] = {i - 1, j - 1, red};
        }
        if (j + 1 < m && dp[i - 1][j + 1][red] != -1 &&
            dp[i][j][k] < dp[i - 1][j + 1][red] + arr[i][j]) {
          dp[i][j][l] = dp[i - 1][j + 1][red] + arr[i][j];
          from[i][j][l] = {i - 1, j + 1, red};
        }
      }
    }
  }
  int zac = 0;
  for (int i = 1; i < m; i++) {
    if (dp[n - 1][i][0] > dp[n - 1][zac][0]) zac = i;
  }
  if (dp[n - 1][zac][0] == -1) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n%d\n", dp[n - 1][zac][0], zac + 1);
  int x = n - 1;
  int y = zac;
  int z = 0;
  while (from[x][y][z].x != -1) {
    st here = from[x][y][z];
    if (here.y == y + 1)
      printf("R");
    else
      printf("L");
    x = here.x;
    y = here.y;
    z = here.z;
  }
  return 0;
}
