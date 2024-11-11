#include <bits/stdc++.h>
using namespace std;
int n, m;
char ss[1005][1005];
int dis[4][1005][1005], v[4][4];
void bfs(char c) {
  int num = c - '1' + 1;
  queue<pair<int, int> > q;
  int f[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (ss[i][j] == c) q.push(make_pair(i, j));
  pair<int, int> now;
  while (!q.empty()) {
    now = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int xx = now.first + f[i][0];
      int yy = now.second + f[i][1];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      if (ss[xx][yy] == '#') continue;
      if (ss[xx][yy] == '.' &&
          dis[num][xx][yy] > dis[num][now.first][now.second] + 1) {
        dis[num][xx][yy] = dis[num][now.first][now.second] + 1;
        q.push(make_pair(xx, yy));
      }
      if (ss[xx][yy] != '.' &&
          dis[num][xx][yy] > dis[num][now.first][now.second]) {
        dis[num][xx][yy] = dis[num][now.first][now.second];
        q.push(make_pair(xx, yy));
      }
    }
  }
}
int main() {
  cin >> n >> m;
  int i, j, k;
  for (i = 0; i < n; i++) scanf("%s", ss[i]);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      dis[1][i][j] = 10000000;
      dis[2][i][j] = 10000000;
      dis[3][i][j] = 10000000;
      if (ss[i][j] - '1' - 0 >= 0) {
        k = ss[i][j] - '1' + 1;
        dis[k][i][j] = 0;
      }
    }
  for (i = 0; i < 3; i++) bfs('1' + i);
  int min1 = 10000000;
  for (i = 1; i <= 3; i++)
    for (j = 1; j <= 3; j++) v[i][j] = 10000000;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      if (ss[i][j] == '.')
        min1 = min(min1, dis[1][i][j] + dis[2][i][j] + dis[3][i][j] + 50);
      else if (ss[i][j] == '1') {
        v[1][2] = min(v[1][2], dis[2][i][j]);
        v[1][3] = min(v[1][3], dis[3][i][j]);
      } else if (ss[i][j] == '2') {
        v[2][1] = min(v[2][1], dis[1][i][j]);
        v[2][3] = min(v[2][3], dis[3][i][j]);
      } else if (ss[i][j] == '3') {
        v[3][1] = min(v[3][1], dis[1][i][j]);
        v[3][2] = min(v[3][2], dis[2][i][j]);
      }
    }
  min1 = min(min1, v[1][2] + v[1][3]);
  min1 = min(min1, v[2][1] + v[2][3]);
  min1 = min(min1, v[3][1] + v[3][2]);
  if (min1 < 10000000)
    cout << min1 << endl;
  else
    cout << -1 << endl;
  return 0;
}
