#include <bits/stdc++.h>
using namespace std;
int i, j, n, k, cnt;
int mov[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
float a[2222][2222], b[2222][2222];
int c[2222][2222], d[2222][2222], color[2222][2222], center[2000000][2],
    ccc[2000000];
vector<pair<int, int> > col[2000000];
queue<pair<int, int> > q;
float dist(int x1, int y1, int x2, int y2) {
  return sqrt(1.0 * (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      scanf("%d", &k);
      a[i][j] = k;
    }
  for (int q = 0; q < 6; q++) {
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) {
        b[i][j] = a[i][j];
        cnt = 1;
        for (k = 0; k < 4; k++)
          if (i + mov[k][0] >= 0 && i + mov[k][0] < n && j + mov[k][1] >= 0 &&
              j + mov[k][1] < n) {
            cnt++;
            b[i][j] += a[i + mov[k][0]][j + mov[k][1]];
          }
        b[i][j] *= 1.0 / cnt;
      }
    memcpy(a, b, 2222 * 2222 * sizeof(float));
    memset(b, 0, 2222 * 2222 * sizeof(float));
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (a[i][j] > 0.5)
        c[i][j] = 1;
      else
        c[i][j] = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      for (k = 0; k < 4; k++)
        if (i + mov[k][0] >= 0 && i + mov[k][0] < n && j + mov[k][1] >= 0 &&
            j + mov[k][1] < n)
          if (c[i + mov[k][0]][j + mov[k][1]]) d[i][j]++;
    }
  for (i = cnt = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (!color[i][j] && c[i][j]) {
        cnt++;
        color[i][j] = cnt;
        col[cnt].push_back(make_pair(i, j));
        q.push(make_pair(i, j));
        while (!q.empty()) {
          pair<int, int> x = q.front();
          q.pop();
          for (k = 0; k < 4; k++) {
            int I = x.first + mov[k][0];
            int J = x.second + mov[k][1];
            if (I >= 0 && I < n && J >= 0 && J < n)
              if (c[I][J] && !color[I][J]) {
                color[I][J] = cnt;
                q.push(make_pair(I, J));
                col[cnt].push_back(make_pair(I, J));
                ccc[cnt]++;
              }
          }
        }
      }
  cnt++;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (d[i][j] <= 2 && ccc[color[i][j]] > 50) q.push(make_pair(i, j));
  while (!q.empty()) {
    pair<int, int> x = q.front();
    q.pop();
    if (!d[x.first][x.second]) {
      center[color[x.first][x.second]][0] = x.first;
      center[color[x.first][x.second]][1] = x.second;
    }
    d[x.first][x.second] = 0;
    for (k = 0; k < 4; k++)
      if (x.first + mov[k][0] >= 0 && x.first + mov[k][0] < n &&
          x.second + mov[k][1] >= 0 && x.second + mov[k][1] < n) {
        if (--d[x.first + mov[k][0]][x.second + mov[k][1]] == 2)
          q.push(make_pair(x.first + mov[k][0], x.second + mov[k][1]));
      }
  }
  int circles = 0;
  int rectangles = 0;
  for (i = 0; i < cnt; i++)
    if (col[i].size() && ccc[i] > 10) {
      float mean = 0;
      float r = 0;
      float temp = 0;
      for (j = 0; j < col[i].size(); j++) {
        temp =
            dist(center[i][0], center[i][1], col[i][j].first, col[i][j].second);
        mean += temp;
        r = max(r, temp);
      }
      mean /= col[i].size();
      if (r / mean < 1.7)
        circles++;
      else
        rectangles++;
    }
  printf("%d %d\n", circles, rectangles);
  return 0;
}
