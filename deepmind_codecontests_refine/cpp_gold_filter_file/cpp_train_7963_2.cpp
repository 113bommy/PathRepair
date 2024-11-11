#include <bits/stdc++.h>
using namespace std;
const int MAX = 1009;
int n, m;
queue<int> q[3];
char ch[MAX][MAX];
bool mark[MAX][MAX][3];
int dis[MAX][MAX][3], d[3][3];
int id(int x, int y) { return x * m + y; }
pair<int, int> mk(int id) { return {id / m, id % m}; }
void bfs(int c) {
  while (q[c].size()) {
    int x = mk(q[c].front()).first, y = mk(q[c].front()).second;
    q[c].pop();
    if (ch[x][y] != c + '1' && ch[x][y] != '.' && ch[x][y] != '#')
      d[c][ch[x][y] - '1'] = min(dis[x][y][c], d[c][ch[x][y] - '1']);
    if (y < m and x + 1 < n and x + 1 >= 0 and y >= 0 and
        ch[x + 1][y] != '#' and !mark[x + 1][y][c])
      q[c].push(id(x + 1, y)), dis[x + 1][y][c] = dis[x][y][c] + 1,
                                       mark[x + 1][y][c] = true;
    if (y < m and x - 1 < n and x - 1 >= 0 and y >= 0 and
        ch[x - 1][y] != '#' and !mark[x - 1][y][c])
      q[c].push(id(x - 1, y)), dis[x - 1][y][c] = dis[x][y][c] + 1,
                                       mark[x - 1][y][c] = true;
    if (y + 1 < m and x < n and x >= 0 and y + 1 >= 0 and
        ch[x][y + 1] != '#' and !mark[x][y + 1][c])
      q[c].push(id(x, y + 1)), dis[x][y + 1][c] = dis[x][y][c] + 1,
                                          mark[x][y + 1][c] = true;
    if (y - 1 < m and x < n and x >= 0 and y - 1 >= 0 and
        ch[x][y - 1] != '#' and !mark[x][y - 1][c])
      q[c].push(id(x, y - 1)), dis[x][y - 1][c] = dis[x][y][c] + 1,
                                          mark[x][y - 1][c] = true;
  }
}
int main() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) d[i][j] = 1e8;
  for (int i = 0; i < MAX - 5; i++)
    for (int j = 0; j < MAX - 5; j++)
      for (int k = 0; k < 3; k++) dis[i][j][k] = 1e8;
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> ch[i][j];
      if (ch[i][j] != '.' && ch[i][j] != '#')
        q[ch[i][j] - '1'].push(id(i, j)),
            mark[i][j][ch[i][j] - '1'] = true, dis[i][j][ch[i][j] - '1'] = 0;
    }
  bfs(0), bfs(1), bfs(2);
  int ans = 1e9;
  ans = min(d[0][1] + d[0][2], min(d[0][1] + d[1][2], d[0][2] + d[2][1])) - 2;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      ans = min(ans, dis[i][j][0] + dis[i][j][1] + dis[i][j][2] - 2);
  if (ans > 1e6)
    cout << -1;
  else
    cout << ans;
}
