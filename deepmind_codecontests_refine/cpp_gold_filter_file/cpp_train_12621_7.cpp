#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> mp(n);
    for (int i = 0; i < n; i++) cin >> mp[i];
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<vector<int>> deg(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int tx = i;
        int ty = j;
        if (s[i][j] == 'U') tx--;
        if (s[i][j] == 'D') tx++;
        if (s[i][j] == 'R') ty++;
        if (s[i][j] == 'L') ty--;
        deg[tx][ty]++;
      }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (deg[i][j] == 0) {
          q.push(make_pair(i, j));
        }
      }
    }
    while (!q.empty()) {
      pair<int, int> PP = q.front();
      q.pop();
      int tx = PP.first;
      int ty = PP.second;
      int nx = tx;
      int ny = ty;
      if (s[tx][ty] == 'U') nx--;
      if (s[tx][ty] == 'D') nx++;
      if (s[tx][ty] == 'L') ny--;
      if (s[tx][ty] == 'R') ny++;
      if (--deg[nx][ny] == 0) q.push(make_pair(nx, ny));
    }
    vector<vector<int>> dis(n, vector<int>(m, -1));
    vector<int> f(n * m);
    vector<pair<int, int>> que;
    int r1 = 0;
    int r2 = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (deg[i][j] == 0) continue;
        if (dis[i][j] != -1) continue;
        dis[i][j] = 0;
        que.clear();
        que.push_back(make_pair(i, j));
        int len = 0;
        for (int i = 0; i < que.size(); i++) {
          pair<int, int> PP = que[i];
          int tx = PP.first;
          int ty = PP.second;
          if (deg[tx][ty] != 0) len++;
          for (int j = 0; j < 4; j++) {
            int nx = tx + dir[j][0];
            int ny = ty + dir[j][1];
            if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
            if (dis[nx][ny] != -1) continue;
            int fx = nx;
            int fy = ny;
            if (s[nx][ny] == 'U') fx--;
            if (s[nx][ny] == 'D') fx++;
            if (s[nx][ny] == 'L') fy--;
            if (s[nx][ny] == 'R') fy++;
            if (fx == tx && fy == ty) {
              que.push_back(make_pair(nx, ny));
              dis[nx][ny] = dis[tx][ty] + 1;
            }
          }
        }
        r1 += len;
        for (int i = 0; i < len; i++) f[i] = 0;
        for (int i = 0; i < que.size(); i++) {
          pair<int, int> PP = que[i];
          int tx = PP.first;
          int ty = PP.second;
          if (mp[tx][ty] == '0') {
            f[dis[tx][ty] % len] = 1;
          }
        }
        for (int i = 0; i < len; i++) r2 += f[i];
      }
    }
    printf("%d %d\n", r1, r2);
  }
  return 0;
}
