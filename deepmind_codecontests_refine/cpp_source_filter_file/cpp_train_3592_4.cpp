#include <bits/stdc++.h>
using namespace std;
const double pi =
    3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int inf = 1e9;
char s[1010][1010];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
bool ok(int x, int y, int pos) {
  return x + dx[pos] >= 0 && x + dx[pos] < n && y + dy[pos] >= 0 &&
         y + dy[pos] < m;
}
int dist[1010][1010][3];
void bfs(int wsk) {
  queue<pair<int, int>> Q;
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) {
      if (s[i][j] - '0' == wsk + 1) {
        Q.push(make_pair(i, j));
      } else {
        dist[i][j][wsk] = inf;
      }
    }
  while (!Q.empty()) {
    pair<int, int> akt = Q.front();
    Q.pop();
    for (int i = 0; i < (4); ++i)
      if (ok(akt.first, akt.second, i) &&
          s[akt.first + dx[i]][akt.second + dy[i]] != '#' &&
          dist[akt.first + dx[i]][akt.second + dy[i]][wsk] == inf) {
        dist[akt.first + dx[i]][akt.second + dy[i]][wsk] =
            dist[akt.first][akt.second][wsk] + 1;
        Q.push(make_pair(akt.first + dx[i], akt.second + dy[i]));
      }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (n); ++i) scanf("%s", s[i]);
  bfs(0);
  bfs(1);
  bfs(2);
  int res = inf;
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) {
      if (dist[i][j][0] < inf && dist[i][j][1] < inf && dist[i][j][2] < inf) {
        res = min(res, dist[i][j][0] + dist[i][j][1] + dist[i][j][2] - 2);
      }
    }
  int res12 = inf, res13 = inf, res23 = inf;
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) {
      res12 = min(res12, dist[i][j][0] + dist[i][j][1] - 1);
      res13 = min(res13, dist[i][j][0] + dist[i][j][2] - 1);
      res23 = min(res23, dist[i][j][1] + dist[i][j][2] - 1);
    }
  res = min(res, min(res12 + res13, min(res12 + res23, res13 + res23)));
  if (res == inf) res = -1;
  printf("%d\n", res);
  return 0;
}
