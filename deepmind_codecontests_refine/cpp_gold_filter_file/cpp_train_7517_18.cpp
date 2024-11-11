#include <bits/stdc++.h>
using namespace std;
char m[10];
bool n[10][10][10];
int dir[9][2] = {0, 0, 0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, -1, -1, 1};
bool ok(int i, int j, int k) {
  if (i < 1 || i > 8 || j < 1 || j > 8) return false;
  if (n[k][i][j]) return false;
  return true;
}
bool dfs(int i, int j, int k) {
  int t, x, y;
  if (k == 8) return true;
  for (t = 0; t < 9; t++) {
    x = i + dir[t][0];
    y = j + dir[t][1];
    if (ok(x, y, k) && (x == 1 || n[k][x - 1][y] == 0)) {
      if (dfs(x, y, k + 1)) return true;
    }
  }
  return false;
}
int main() {
  int i, j, k;
  for (i = 1; i <= 8; i++)
    for (j = 1; j <= 8; j++) n[1][i][j] = 0;
  for (i = 1; i <= 8; i++) {
    scanf("%s", m);
    for (j = 0; j < 8; j++)
      if (m[j] == 'S') n[1][i][j + 1] = 1;
  }
  for (i = 2; i <= 7; i++) {
    for (j = 1; j < i; j++)
      for (k = 1; k <= 8; k++) n[i][j][k] = 0;
    for (j = i; j <= 8; j++)
      for (k = 1; k <= 8; k++) n[i][j][k] = n[i - 1][j - 1][k];
  }
  if (dfs(8, 1, 1))
    printf("WIN\n");
  else
    printf("LOSE\n");
  return 0;
}
