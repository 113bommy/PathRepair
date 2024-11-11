#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const double PI = 3.141592653589793;
const int N = 1005;
int xx[4] = {-1, 0, 1, 0};
int yy[4] = {0, 1, 0, -1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int tab[N][N], i, j, k, vis[N][N], maxx, da, n, m, sas, i1, j11;
vector<pair<int, int> > wek, wek2;
char t[N];
bool good(int a, int b) {
  if (a < 0 || a >= n || b < 0 || b >= m) return false;
  return true;
}
void dfs(int a, int b) {
  vis[a][b] = 1;
  wek.push_back(pair<int, int>(a, b));
  for (int i = 0; i < 4; i++)
    if (good(a + xx[i], b + yy[i]) && tab[a + xx[i]][b + yy[i]] == 0 &&
        vis[a + xx[i]][b + yy[i]] == 0)
      dfs(a + xx[i], b + yy[i]);
}
void dfs2(int a, int b, int k) {
  vis[a][b] = k + 1;
  for (int i = 0; i < 4; i++)
    if (good(a + xx[i], b + yy[i]) && vis[a + xx[i]][b + yy[i]] == k)
      dfs2(a + xx[i], b + yy[i], k);
}
int main() {
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%s", t);
    for (j = 0; j < m; j++) tab[i][j] = (t[j] == '1');
  }
  k = 2;
  maxx = 0;
  for (i1 = 0; i1 < n; i1++)
    for (j11 = 0; j11 < m; j11++)
      if (tab[i1][j11] == 0 && vis[i1][j11] == 0) {
        wek.resize(0);
        wek2.resize(0);
        dfs(i1, j11);
        k++;
        da = 1;
        for (i = 0; i < wek.size(); i++) {
          for (j = 0; j < 8; j++)
            if (!good(wek[i].first + dx[j], wek[i].second + dy[j]))
              da = 0;
            else if (tab[wek[i].first + dx[j]][wek[i].second + dy[j]] == 0 &&
                     vis[wek[i].first + dx[j]][wek[i].second + dy[j]] != 1)
              da = 0;
            else if (vis[wek[i].first + dx[j]][wek[i].second + dy[j]] == 0) {
              vis[wek[i].first + dx[j]][wek[i].second + dy[j]] = k;
              wek2.push_back(
                  pair<int, int>(wek[i].first + dx[j], wek[i].second + dy[j]));
            }
        }
        if (da) {
          for (i = 0; i < wek2.size(); i++) {
            sas = 0;
            for (j = 0; j < 4; j++)
              if (good(wek2[i].first + xx[j], wek2[i].second + yy[j]) &&
                  vis[wek2[i].first + xx[j]][wek2[i].second + yy[j]] == k)
                sas++;
            if (sas != 2) da = 0;
          }
          dfs2(wek2[0].first, wek2[0].second, k);
          for (i = 0; i < wek2.size(); i++)
            if (vis[wek2[i].first][wek2[i].second] != k + 1) da = 0;
          if (da) maxx = max(maxx, (int)wek2.size());
        }
        for (i = 0; i < wek.size(); i++) vis[wek[i].first][wek[i].second] = 2;
        for (i = 0; i < wek2.size(); i++)
          vis[wek2[i].first][wek2[i].second] = 0;
      }
  if (maxx == 0) {
    for (i = 0; i < n - 1; i++)
      for (j = 0; j < m - 1; j++)
        if (tab[i][j] && tab[i][j + 1] && tab[i + 1][j] && tab[i + 1][j + 1])
          maxx = 4;
  }
  printf("%d\n", maxx);
  return 0;
}
