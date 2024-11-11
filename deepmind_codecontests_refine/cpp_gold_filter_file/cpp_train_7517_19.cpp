#include <bits/stdc++.h>
char mp[10][10];
int move[8][2] = {-1, 0, -1, -1, 1, 1, -1, 1, 1, -1, 0, 0, 0, -1, 0, 1};
int s[8][20][20];
int k;
int dfs(int cas, int x, int y) {
  if (cas == 7 || x == 1 && y == 8) return 1;
  int i;
  for (i = 0; i < 8; i++) {
    if (x + move[i][0] <= 8 && x + move[i][0] >= 1 && y + move[i][1] <= 8 &&
        y + move[i][1] >= 1) {
      if (s[cas][x + move[i][0]][y + move[i][1]] != 1 &&
          s[cas + 1][x + move[i][0]][y + move[i][1]] != 1) {
        if (dfs(cas + 1, x + move[i][0], y + move[i][1])) return 1;
      }
    }
  }
  return 0;
}
int main() {
  int i, j;
  while (scanf("%s", mp[1] + 1) != EOF) {
    for (i = 2; i <= 8; i++) scanf("%s", mp[i] + 1);
    k = 0;
    for (i = 0; i < 8; i++)
      for (j = 1; j <= 8; j++)
        for (k = 1; k <= 8; k++) s[i][j][k] = 0;
    for (i = 1; i <= 8; i++)
      for (j = 1; j <= 8; j++)
        if (mp[i][j] == 'S') {
          for (k = 0; k <= 7; k++) {
            s[k][i + k][j] = 1;
          }
        }
    if (dfs(0, 8, 1))
      printf("WIN\n");
    else
      printf("LOSE\n");
  }
}
