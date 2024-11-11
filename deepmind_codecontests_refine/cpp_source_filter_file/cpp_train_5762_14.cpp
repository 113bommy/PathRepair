#include <bits/stdc++.h>
using namespace std;
FILE *in;
FILE *out;
int n;
int a[2048][2048];
int vis[2048][2048];
queue<pair<int, int> > q;
vector<pair<int, int> > v;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
double fdist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int eval(int row, int col) {
  v.clear();
  while (!q.empty()) q.pop();
  q.push(make_pair(row, col));
  vis[row][col] = 1;
  double srow = 0, scol = 0, all = 0;
  while (!q.empty()) {
    row = q.front().first;
    srow += row;
    col = q.front().second;
    scol += col;
    q.pop();
    all += 1;
    for (int i = 0; i < 4; i++) {
      int nrow = row + dir[i][0];
      if (nrow < 0 || nrow >= n) continue;
      int ncol = col + dir[i][1];
      if (ncol < 0 || ncol >= n) continue;
      if (!vis[nrow][ncol] && a[nrow][ncol]) {
        q.push(make_pair(nrow, ncol));
        vis[nrow][ncol] = 1;
        int isBorder = 0;
        for (int c = 0; c < 4; c++) {
          int crow = nrow + dir[c][0];
          if (crow < 0 || crow >= n) {
            isBorder = 1;
            break;
          }
          int ccol = ncol + dir[c][1];
          if (ccol < 0 || ccol >= n) {
            isBorder = 1;
            break;
          }
          if (a[crow][ccol] == 0) {
            isBorder = 1;
            break;
          }
        }
        if (isBorder) v.push_back(make_pair(nrow, ncol));
      }
    }
  }
  double minn = 999666333, maxx = 0;
  double crow = (double)srow / all, ccol = (double)scol / all;
  for (int i = 0; i < (int)v.size(); i++) {
    double dist = fdist(v[i].first, v[i].second, crow, ccol);
    minn = min(minn, dist);
    maxx = max(maxx, dist);
  }
  return maxx - minn < 5 ? 0 : 1;
}
void removeNoise() {
  for (int iter = 0; iter < 5; iter++) {
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < n; col++)
        if (a[row][col] == 0) {
          int cnt = 0, clean = 0;
          for (int i = 0; i < 4; i++) {
            int nrow = row + dir[i][0];
            if (nrow < 0 || nrow >= n) continue;
            int ncol = col + dir[i][1];
            if (ncol < 0 || ncol >= n) continue;
            if (a[nrow][ncol] == 0) clean++;
            cnt++;
          }
          if (cnt == clean) a[row][col] = 0;
        }
    }
  }
}
int main(void) {
  in = stdin;
  out = stdout;
  fscanf(in, "%d", &n);
  for (int i = 0; i < n; i++)
    for (int c = 0; c < n; c++) fscanf(in, "%d", &a[i][c]);
  int ans[2] = {0, 0};
  memset(vis, 0, sizeof(vis));
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++)
      if (!vis[row][col] && a[row][col]) ans[eval(row, col)]++;
  }
  fprintf(out, "%d %d\n", ans[0], ans[1]);
  return 0;
}
