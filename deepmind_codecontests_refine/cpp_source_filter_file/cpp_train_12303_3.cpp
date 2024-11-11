#include <bits/stdc++.h>
using namespace std;
int n, tx, ty;
int a[100][100];
void out(int x) {
  if (x) {
    for (int i = (1); i <= (n); ++i)
      for (int j = (1); j <= (n); ++j)
        if ((i + j) % 2 & 1) a[i][j] ^= 1;
  }
  printf("!\n");
  fflush(stdout);
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) {
      printf("%d", a[i][j]);
      if (j == n) printf("\n");
    }
}
void dfs(int x, int y, int val, int dep) {
  if (tx == -1) return;
  if (dep == 3) {
    if (!val) {
      int d = a[tx][ty] ^ a[x][y], u;
      printf("? %d %d %d %d\n", tx, ty, x, y);
      fflush(stdout);
      scanf("%d", &u);
      out(d == u);
      tx = -1;
    }
    return;
  }
  if (x + 1 <= n) dfs(x + 1, y, val ^ a[x + 1][y], dep + 1);
  if (y + 1 <= n) dfs(y, x + 1, val ^ a[x][y + 1], dep + 1);
}
int main() {
  int u;
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) a[i][j] = -1;
  a[1][1] = 1;
  a[n][n] = 0;
  for (int i = (1); i <= (n - 2); ++i) {
    printf("? %d %d %d %d\n", i, i, i + 1, i + 1);
    fflush(stdout);
    scanf("%d", &u);
    a[i + 1][i + 1] = a[i][i] ^ (u ^ 1);
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) {
      if (i == j) continue;
      if ((i + j) % 2 == 0) {
        if (i > 2) {
          printf("? %d %d %d %d\n", i - 2, j, i, j);
          fflush(stdout);
          scanf("%d", &u);
          a[i][j] = a[i - 2][j] ^ (u ^ 1);
        } else {
          printf("? %d %d %d %d\n", i, j - 2, i, j);
          fflush(stdout);
          scanf("%d", &u);
          a[i][j] = a[i][j - 2] ^ (u ^ 1);
        }
      }
    }
  a[1][2] = 0;
  printf("? 1 2 2 3\n");
  fflush(stdout);
  scanf("%d", &u);
  a[2][3] = a[1][2] ^ (u ^ 1);
  printf("? 2 1 2 3\n");
  fflush(stdout);
  scanf("%d", &u);
  a[2][1] = a[2][3] ^ (u ^ 1);
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) {
      if (a[i][j] != -1) continue;
      if ((i + j) % 2 == 1) {
        if (i > 2) {
          printf("? %d %d %d %d\n", i - 2, j, i, j);
          fflush(stdout);
          scanf("%d", &u);
          a[i][j] = a[i - 2][j] ^ (u ^ 1);
        } else {
          printf("? %d %d %d %d\n", i, j - 2, i, j);
          fflush(stdout);
          scanf("%d", &u);
          a[i][j] = a[i][j - 2] ^ (u ^ 1);
        }
      }
    }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) {
      tx = i, ty = j;
      dfs(i, j, a[i][j], 0);
      if (tx == -1) return 0;
    }
  return 0;
}
