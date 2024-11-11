#include <bits/stdc++.h>
struct data {
  int x, y;
} c[5000];
char in[1505][1505];
int a[1505][1505];
int check[500][500];
bool v[5005][5005][4];
int x, y, cnt;
int n, m, S, sx, sy;
int xx[] = {-1, 1, 0, 0};
int yy[] = {0, 0, 1, -1};
bool ck[5005], flag;
void go(int y, int x) {
  a[y][x] = cnt;
  int i;
  for (i = 0; i < 4; i++)
    if (a[y + yy[i]][x + xx[i]] == 5000) go(y + yy[i], x + xx[i]);
}
int k[] = {1, 0, 3, 2};
void dfs(int x) {
  ck[x] = 1;
  c[x].x = sx;
  c[x].y = sy;
  int i, j;
  for (i = 1; i <= cnt; i++) {
    for (j = 0; j < 4; j++) {
      sx += xx[j];
      sy += yy[j];
      if (flag) return;
      if (ck[i] && v[x][i][j] && !(sx == c[x].x && sy == c[x].y)) {
        printf("Yes");
        flag = 1;
        return;
      }
      if (!ck[i] && v[x][i][j]) {
        v[x][i][j] = 0;
        v[i][x][k[j]] = 0;
        dfs(i);
        v[x][i][j] = 1;
        v[i][x][k[j]] = 1;
      }
      sx -= xx[j];
      sy -= yy[j];
    }
  }
  ck[x] = 0;
}
int main() {
  scanf("%d%d", &n, &m);
  int i, j;
  for (i = 1; i <= n; i++) scanf("%s", &in[i][1]);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      if (in[i][j] == 'S') x = j, y = i;
      if (in[i][j] != '#') a[i][j] = 5000;
    }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (i == 1 || i == n || j == 1 || j == m) {
        if (a[i][j] == 5000) ++cnt, go(i, j);
      }
    }
  }
  S = a[y][x];
  if (S == 5000) {
    printf("No");
    return 0;
  }
  for (i = 1; i <= n; i++)
    v[a[i][1]][a[i][m]][0] = 1, v[a[i][m]][a[i][1]][1] = 1;
  for (i = 1; i <= m; i++)
    v[a[n][i]][a[1][i]][2] = 1, v[a[1][i]][a[n][i]][3] = 1;
  dfs(S);
  if (flag) return 0;
  printf("No");
  return 0;
}
