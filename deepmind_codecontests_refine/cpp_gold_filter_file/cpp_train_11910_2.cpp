#include <bits/stdc++.h>
using namespace std;
char s[10];
int step[1010][1010];
int vis[1010][1010];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int qx[5000000], qy[5000000];
int peox[12000100], peoy[12000100], peonum[12000100];
void bfs(int x, int y) {
  int i, j, k;
  vis[x][y] = 1;
  step[x][y] = 0;
  int head, tail;
  head = tail = 0;
  qx[tail] = x;
  qy[tail] = y;
  tail++;
  int nowx, nowy, nextx, nexty, nowstep;
  while (head < tail) {
    nowx = qx[head];
    nowy = qy[head];
    nowstep = step[nowx][nowy];
    head++;
    for (i = 0; i < 4; i++) {
      nextx = nowx + dx[i];
      nexty = nowy + dy[i];
      if (!vis[nextx][nexty]) {
        vis[nextx][nexty] = 1;
        step[nextx][nexty] = nowstep + 1;
        qx[tail] = nextx;
        qy[tail] = nexty;
        tail++;
      }
    }
  }
}
int main() {
  int r, c;
  int i, j, k, l;
  int total = 0;
  char chaa;
  long long ans = 0;
  int startx, starty;
  int maxs, maxx, maxy;
  scanf("%d%d", &r, &c);
  gets(s);
  for (i = 0; i <= c + 1; i++) vis[0][i] = vis[r + 1][i] = 1;
  for (i = 0; i <= r + 1; i++) vis[i][0] = vis[i][c + 1] = 1;
  for (i = 1; i <= r; i++) {
    for (j = 1; j <= c; j++) {
      scanf("%c", &chaa);
      if (chaa == 'T') vis[i][j] = 1;
      if (chaa == 'E') {
        startx = i;
        starty = j;
      }
      if (chaa >= '1' && chaa <= '9') {
        peox[total] = i;
        peoy[total] = j;
        peonum[total] = chaa - '0';
        total++;
      }
      if (chaa == 'S') {
        maxx = i;
        maxy = j;
      }
      step[i][j] = 800000000;
    }
    gets(s);
  }
  bfs(startx, starty);
  maxs = step[maxx][maxy];
  for (i = 0; i < total; i++) {
    if (step[peox[i]][peoy[i]] <= maxs) ans += peonum[i];
  }
  printf("%I64d\n", ans);
  return 0;
}
