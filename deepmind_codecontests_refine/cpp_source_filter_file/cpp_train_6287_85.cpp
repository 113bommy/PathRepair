#include <bits/stdc++.h>
using namespace std;
int n, m, p1[2010][2010], p2[2010][2010], p3[2010][2010], p4[2010][2010];
int sun[2010][2010];
int dir[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                 {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int vis[2010][2010];
int nw, nwr, bel[4000010], cnt[4000010];
int tr[2010][2010];
void col(int x, int y, int c) {
  sun[x][y] = c;
  for (int k = 0; k <= 7; ++k) {
    int tx = x + dir[k][0], ty = y + dir[k][1];
    if (tx > 0 && tx <= n && ty > 0 && ty <= m && p1[tx][ty] && p2[tx][ty] &&
        !sun[tx][ty]) {
      col(tx, ty, c);
    }
  }
}
void hehe(int x, int y, int c) {
  tr[x][y] = c;
  for (int k = 0; k <= 7; ++k) {
    int tx = x + dir[k][0], ty = y + dir[k][1];
    if (tx > 0 && tx <= n && ty > 0 && ty <= m) {
      if (sun[tx][ty])
        bel[c] = sun[tx][ty];
      else if (p1[tx][ty] && !tr[tx][ty])
        hehe(tx, ty, c);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &p1[i][j]), p2[i][j] = p1[i][j];
  for (int k = 1; k <= 4; ++k) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) p3[i][j] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        int tmp = 1;
        for (int l = 0; l <= 7; ++l) {
          int ti = i + dir[l][0], tj = j + dir[l][1];
          if (ti > 0 && ti <= n && tj > 0 && tj <= m) {
            if (p2[ti][tj] == 0) tmp = 0;
          }
        }
        p3[i][j] = tmp;
      }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) swap(p2[i][j], p3[i][j]);
  }
  for (int k = 1; k <= 5; ++k) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) p3[i][j] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        int tmp = 0;
        for (int l = 0; l <= 7; ++l) {
          int ti = i + dir[l][0], tj = j + dir[l][1];
          if (ti > 0 && ti <= n && tj > 0 && tj <= m) {
            if (p2[ti][tj] == 1) tmp = 1;
          }
        }
        p3[i][j] = tmp;
      }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) swap(p2[i][j], p3[i][j]);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (p1[i][j] && p2[i][j] && !sun[i][j]) col(i, j, ++nw);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (p1[i][j] && !sun[i][j] && !tr[i][j]) hehe(i, j, ++nwr);
  for (int i = 1; i <= nwr; ++i) ++cnt[bel[i]];
  vector<int> huhu;
  for (int i = 1; i <= nw; ++i) huhu.push_back(cnt[i]);
  sort(huhu.begin(), huhu.end());
  printf("%d\n", nw);
  for (int i = 0; i < huhu.size(); ++i)
    printf("%d%c", huhu[i], i + 1 == huhu.size() ? '\n' : ' ');
  return 0;
}
