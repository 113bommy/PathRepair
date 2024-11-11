#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2000, R1 = 5, D = 3;
char b[MaxN][MaxN];
int u[MaxN][MaxN];
char u2[MaxN][MaxN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int minx[MaxN], miny[MaxN], maxx[MaxN], maxy[MaxN];
int mnx, mny, mxx, mxy;
int k;
int cnt[MaxN], res[MaxN];
void dfs(int x, int y) {
  u[y][x] = k + 1;
  for (int d = 0; d < 4; d++)
    if (b[y + dy[d]][x + dx[d]] == '1' && u[y + dy[d]][x + dx[d]] == 0)
      dfs(x + dx[d], y + dy[d]);
}
void dfs2(int x, int y) {
  u2[y][x] = 1;
  for (int d = 0; d < 4; d++)
    if (u[y + dy[d]][x + dx[d]] != 0 && u2[y + dy[d]][x + dx[d]] == 0)
      dfs2(x + dx[d], y + dy[d]);
}
int main(void) {
  int h, w;
  scanf("%d %d", &h, &w);
  int i, j, i1, j1;
  k = 0;
  for (i = 0; i < h; i++)
    for (j = 0; j < w; j++) scanf("%c ", &b[i][j]);
  memset(u, 0, sizeof(u));
  memset(u2, 0, sizeof(u2));
  memset(cnt, 0, sizeof(cnt));
  for (i = 0; i < h; i++)
    for (j = 0; j < w; j++)
      if (b[i][j] == '1' && !u[i][j]) {
        dfs(j, i);
        k++;
      }
  printf("%d\n", k);
  for (i = 0; i < h - R1; i++)
    for (j = 0; j < w - R1; j++) {
      bool f = 1;
      for (i1 = max(i - R1, 0); i1 <= i + R1 && f; i1++)
        for (j1 = max(j - R1, 0); j1 <= j + R1; j1++)
          if ((i1 - i) * (i1 - i) + (j1 - j) * (j1 - j) <= R1 * R1)
            if (b[i1][j1] == '0') {
              f = 0;
              break;
            }
      if (f)
        for (i1 = max(i - R1 - D, 0); i1 <= i + R1 + D; i1++)
          for (j1 = max(j - R1 - D, 0); j1 <= j + R1 + D; j1++)
            if ((i1 - i) * (i1 - i) + (j1 - j) * (j1 - j) <=
                (R1 + D) * (R1 + D))
              u[i1][j1] = 0;
    }
  for (i = 0; i < h; i++)
    for (j = 0; j < w; j++)
      if (u[i][j] != 0 && u2[i][j] == 0) {
        dfs2(j, i);
        cnt[u[i][j]]++;
      }
  for (i = 1; i <= k; i++) res[i - 1] = cnt[i];
  sort(res, res + k);
  for (i = 0; i < k; i++) printf("%d ", res[i]);
  printf("\n");
}
