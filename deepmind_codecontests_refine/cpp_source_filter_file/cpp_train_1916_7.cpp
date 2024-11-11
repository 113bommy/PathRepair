#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int m, n;
int app[1005][1005];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main() {
  cin >> m >> n;
  int ex, ey, sx, sy;
  vector<int> px, py;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c >= '0' && c <= '9') {
        a[i][j] = c - '0';
        if (a[i][j] > 0) {
          px.push_back(i);
          py.push_back(j);
        }
      } else if (c == 'T') {
        a[i][j] = -1;
      } else if (c == 'E') {
        a[i][j] = -2;
        ex = i;
        ey = j;
      } else if (c == 'S') {
        a[i][j] = -3;
        sx = i;
        sy = j;
      }
      app[i][j] = 100000;
    }
  }
  app[ex][ey] = 0;
  queue<int> qx, qy;
  qx.push(ex);
  qy.push(ey);
  while (!qx.empty()) {
    for (int i = 0; i < 4; i++) {
      int tempx = qx.front() + dx[i];
      int tempy = qy.front() + dy[i];
      if (tempx >= 0 && tempx < m && tempy >= 0 && tempy < n &&
          app[tempx][tempy] > app[qx.front()][qy.front()] + 1 &&
          a[tempx][tempy] != -1) {
        app[tempx][tempy] = app[qx.front()][qy.front()] + 1;
        qx.push(tempx);
        qy.push(tempy);
      }
    }
    qx.pop();
    qy.pop();
  }
  int ans = 0;
  for (int i = 0; i < px.size(); i++) {
    if (app[px[i]][py[i]] <= app[sx][sy]) {
      ans += a[px[i]][py[i]];
    }
  }
  cout << ans << endl;
  return 0;
}
