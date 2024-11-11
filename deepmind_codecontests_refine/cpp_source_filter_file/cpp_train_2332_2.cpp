#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N = 500 + 10, mod = 1e9 + 7, M = 3e3 + 10;
const double PI = 3.1415926535;
char str[N][N];
bool vis[N][N];
vector<pair<int, int>> path;
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
vector<pair<char, pair<int, int>>> res;
void dfs(int x, int y) {
  vis[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int d1 = x + dx[i], d2 = y + dy[i];
    if (d1 < 1 || d1 > n || d2 < 1 || d2 > m || str[d1][d2] == '#' ||
        vis[d1][d2])
      continue;
    dfs(d1, d2);
  }
  path.push_back({x, y});
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", str[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (!vis[i][j] && str[i][j] != '#') {
        path.clear();
        dfs(i, j);
        reverse(path.begin(), path.end());
        if (path.size() == 1) {
          res.push_back({'B', path[0]});
          continue;
        }
        for (int k = 0; k < path.size() - 1; k++) {
          res.push_back({'B', path[k]});
        }
        res.push_back({'R', path.back()});
        for (int k = path.size() - 2; k >= 0; k--) {
          res.push_back({'D', path[k]});
          res.push_back({'R', path[k]});
        }
      }
  }
  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); i++)
    printf("%c %d %d\n", res[i].first, res[i].second.first,
           res[i].second.second);
  return 0;
}
