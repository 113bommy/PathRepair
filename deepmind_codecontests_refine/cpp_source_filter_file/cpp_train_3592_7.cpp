#include <bits/stdc++.h>
using namespace std;
const int inf = 12345678;
int n, m;
char field[1050][1050];
int dis[3][1050][1050], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
bool ok(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void bfs(int x) {
  vector<pair<int, int> > v;
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      dis[x][i][j] = inf;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (field[i][j] == '1' + x) {
        v.push_back(make_pair(i, j));
        dis[x][i][j] = 0;
      }
    }
  }
  for (i = 0; i < v.size(); i++) {
    int a = v[i].first;
    int b = v[i].second;
    for (j = 0; j < 4; j++) {
      int aa = a + dx[j];
      int bb = b + dy[j];
      if (!ok(aa, bb) || field[aa][bb] == '#' || dis[x][aa][bb] < inf) continue;
      dis[x][aa][bb] = dis[x][a][b] + 1;
      v.push_back(make_pair(aa, bb));
    }
  }
}
int main() {
  cin >> n >> m;
  int i, j, k;
  for (i = 0; i < n; i++) {
    cin >> field[i];
  }
  for (i = 0; i < 3; i++) {
    bfs(i);
  }
  int ans = inf;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      int res = 1;
      for (k = 0; k < 3; k++) res = res + max(0, dis[k][i][j] - 1);
      ans = min(ans, res);
    }
  }
  for (k = 0; k < 3; k++) {
    int d1 = inf, d2 = inf;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if ((field[i][j] != '1' + k)) continue;
        d1 = min(d1, dis[(k + 1) % 3][i][j]);
        d2 = min(d2, dis[(k + 2) % 3][i][j]);
      }
    }
    ans = min(ans, d1 + d2 - 2);
  }
  if (ans >= inf)
    cout << -1;
  else
    cout << ans;
  return 0;
}
