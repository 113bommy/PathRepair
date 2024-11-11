#include <bits/stdc++.h>
using namespace std;
int p[1602][1602], a[1602][1602], viz[1602][1602], sol[1602 * 1602];
queue<pair<int, int> > c;
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
int bound(int n, int m) {
  int i, j, x, y, k, nr;
  nr = 0;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (p[i][j] && viz[i][j] == 0) {
        nr++;
        p[i][j] = nr;
        viz[i][j] = 1;
        c.push(make_pair(i, j));
        while (c.empty() == 0) {
          x = c.front().first;
          y = c.front().second;
          c.pop();
          for (k = 1; k <= 8; k++) {
            x = x + dx[k];
            y = y + dy[k];
            if (p[x][y] && viz[x][y] == 0) {
              c.push(make_pair(x, y));
              viz[x][y] = 1;
              p[x][y] = nr;
            }
            x = x - dx[k];
            y = y - dy[k];
          }
        }
      }
  memset(viz, 0, sizeof(viz));
  return nr;
}
void erode(int n, int m) {
  int i, j, k, x, y, l;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) a[i][j] = p[i][j];
  for (k = 1; k <= 4; k++) {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) {
        if (a[i][j] == 0) continue;
        x = i;
        y = j;
        for (l = 1; l <= 8; l++) {
          x = x + dx[l];
          y = y + dy[l];
          if (a[x][y] == 0) break;
          x = x - dx[l];
          y = y - dy[l];
        }
        if (l <= 8) viz[i][j] = 1;
      }
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) {
        if (viz[i][j] == 1) a[i][j] = 0;
        viz[i][j] = 0;
      }
  }
}
void dilate(int n, int m) {
  int i, j, k, x, y, l, nr;
  for (k = 1; k <= 4 + 1; k++) {
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) {
        if (a[i][j]) continue;
        x = i;
        y = j;
        for (l = 1; l <= 8; l++) {
          x = x + dx[l];
          y = y + dy[l];
          if (a[x][y]) {
            nr = a[x][y];
            break;
          }
          x = x - dx[l];
          y = y - dy[l];
        }
        if (l <= 8) viz[i][j] = nr;
      }
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) {
        if (viz[i][j]) a[i][j] = viz[i][j];
        viz[i][j] = 0;
      }
  }
}
void merge(int n, int m) {
  int i, j, x, y, k;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (a[i][j]) p[i][j] = 0;
  memset(viz, 0, sizeof(viz));
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (p[i][j] && viz[i][j] == 0) {
        sol[p[i][j]]++;
        viz[i][j] = 1;
        c.push(make_pair(i, j));
        while (c.empty() == 0) {
          x = c.front().first;
          y = c.front().second;
          c.pop();
          for (k = 1; k <= 8; k++) {
            x = x + dx[k];
            y = y + dy[k];
            if (p[x][y] && viz[x][y] == 0) {
              c.push(make_pair(x, y));
              viz[x][y] = 1;
            }
            x = x - dx[k];
            y = y - dy[k];
          }
        }
      }
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, m, i, j, suns;
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) cin >> p[i][j];
  suns = bound(n, m);
  erode(n, m);
  dilate(n, m);
  merge(n, m);
  sort(sol + 1, sol + suns + 1);
  cout << suns << '\n';
  for (i = 1; i <= suns; i++) cout << sol[i] << " ";
  return 0;
}
