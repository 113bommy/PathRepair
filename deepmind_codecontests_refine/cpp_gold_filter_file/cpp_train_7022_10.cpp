#include <bits/stdc++.h>
using namespace std;
int x[30][30], y[30][30];
void solve_n_1(int m) {
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++) {
      int tmp[40];
      for (int k = 0; k < m; k++) tmp[k] = x[0][k];
      for (int k = i; k < j; k++) swap(tmp[k], tmp[k + 1]);
      int same = 1;
      for (int k = 0; k < m; k++)
        if (tmp[k] != y[0][k]) same = 0;
      if (same) {
        printf("%d\n", j - i);
        for (int k = i; k <= j; k++) printf("1 %d\n", k + 1);
        return;
      }
    }
  for (int i = 0; i < m; i++)
    for (int j = i + 1; j < m; j++) {
      int tmp[40];
      for (int k = 0; k < m; k++) tmp[k] = x[0][k];
      for (int k = j; k > i; k--) swap(tmp[k], tmp[k - 1]);
      int same = 1;
      for (int k = 0; k < m; k++)
        if (tmp[k] != y[0][k]) same = 0;
      if (same) {
        printf("%d\n", j - i);
        for (int k = j; k >= i; k--) printf("1 %d\n", k + 1);
        return;
      }
    }
  printf("-1\n");
}
void solve_m_1(int n) {
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int tmp[40];
      for (int k = 0; k < n; k++) tmp[k] = x[k][0];
      for (int k = i; k < j; k++) swap(tmp[k], tmp[k + 1]);
      int same = 1;
      for (int k = 0; k < n; k++)
        if (tmp[k] != y[k][0]) same = 0;
      if (same) {
        printf("%d\n", j - i);
        for (int k = i; k <= j; k++) printf("%d 1\n", k + 1);
        return;
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int tmp[40];
      for (int k = 0; k < n; k++) tmp[k] = x[k][0];
      for (int k = j; k > i; k--) swap(tmp[k], tmp[k - 1]);
      int same = 1;
      for (int k = 0; k < n; k++)
        if (tmp[k] != y[k][0]) same = 0;
      if (same) {
        printf("%d\n", j - i);
        for (int k = j; k >= i; k--) printf("%d 1\n", k + 1);
        return;
      }
    }
  printf("-1\n");
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> x[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> y[i][j];
  if (n == 1) {
    solve_n_1(m);
    return 0;
  }
  if (m == 1) {
    solve_m_1(n);
    return 0;
  }
  vector<int> _xx, _yy;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      _xx.push_back(x[i][j]);
      _yy.push_back(y[i][j]);
    }
  sort(_xx.begin(), _xx.end());
  sort(_yy.begin(), _yy.end());
  if (_xx != _yy) {
    printf("-1\n");
    return 0;
  }
  vector<int> res;
  int yy = -1, xx = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (x[i][j] == y[n - 1][m - 1]) {
        yy = i;
        xx = j;
      }
  x[yy][xx] = 0;
  res.push_back(yy * m + xx);
  int blocked[30][30] = {0};
  vector<pair<int, int> > VV;
  for (int i = 0; i < n - 2; i++)
    for (int j = 0; j < m; j++) VV.push_back(pair<int, int>(i, j));
  for (int j = 0; j < m; j++)
    for (int i = n - 2; i < n; i++)
      if (i != n - 1 || j != m - 1) VV.push_back(pair<int, int>(i, j));
  {
    int sz = VV.size();
    for (int idx = 0; idx < sz; idx++) {
      int ty = VV[idx].first;
      int tx = VV[idx].second;
      int sy = -1, sx = -1;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (!blocked[i][j] && x[i][j] == y[ty][tx]) {
            sy = i, sx = j;
          }
      fprintf(stderr, "%d %d -> %d %d, space at %d %d\n", sy, sx, ty, tx, yy,
              xx);
      int dist[30][30] = {0};
      queue<pair<int, int> > Q;
      Q.push(pair<int, int>(ty, tx));
      dist[ty][tx] = 1;
      while (!Q.empty()) {
        pair<int, int> now = Q.front();
        Q.pop();
        for (int i = -1; i <= 1; i++)
          for (int j = -1; j <= 1; j++) {
            int ny = now.first + i;
            int nx = now.second + j;
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !blocked[ny][nx] &&
                dist[ny][nx] == 0) {
              Q.push(pair<int, int>(ny, nx));
              dist[ny][nx] = dist[now.first][now.second] + 1;
            }
          }
      }
      while (sy != ty || sx != tx) {
        int py = -1, px = -1;
        for (int i = -1; i <= 1; i++)
          for (int j = -1; j <= 1; j++) {
            int ny = sy + i;
            int nx = sx + j;
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !blocked[ny][nx] &&
                dist[ny][nx] < dist[sy][sx])
              py = ny, px = nx;
          }
        blocked[sy][sx] = 1;
        int dist2[30][30] = {0};
        Q.push(pair<int, int>(py, px));
        dist2[py][px] = 1;
        while (!Q.empty()) {
          pair<int, int> now = Q.front();
          Q.pop();
          for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++) {
              int ny = now.first + i;
              int nx = now.second + j;
              if (ny >= 0 && ny < n && nx >= 0 && nx < m && !blocked[ny][nx] &&
                  dist2[ny][nx] == 0) {
                Q.push(pair<int, int>(ny, nx));
                dist2[ny][nx] = dist2[now.first][now.second] + 1;
              }
            }
        }
        while (yy != py || xx != px) {
          int qy = -1, qx = -1;
          for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++) {
              int ny = yy + i;
              int nx = xx + j;
              if (ny >= 0 && ny < n && nx >= 0 && nx < m && !blocked[ny][nx] &&
                  dist2[ny][nx] < dist2[yy][xx])
                qy = ny, qx = nx;
            }
          res.push_back(qy * m + qx);
          x[yy][xx] = x[qy][qx];
          x[qy][qx] = 0;
          yy = qy;
          xx = qx;
        }
        blocked[sy][sx] = 0;
        res.push_back(sy * m + sx);
        x[yy][xx] = x[sy][sx];
        x[sy][sx] = 0;
        swap(yy, sy);
        swap(xx, sx);
      }
      blocked[ty][tx] = 1;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (x[i][j] != y[i][j] && (i < n - 1 || j < m - 1)) printf("INVALID\n");
  printf("%d\n", res.size() - 1);
  for (int i = 0; i < res.size(); i++)
    printf("%d %d\n", 1 + (res[i] / m), 1 + (res[i] % m));
}
