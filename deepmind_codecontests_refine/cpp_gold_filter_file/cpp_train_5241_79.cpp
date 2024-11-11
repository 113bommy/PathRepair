#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 2020;
bool a[N_MAX][N_MAX];
int id[N_MAX][N_MAX];
const int DX[4] = {1, -1, 0, 0};
const int DY[4] = {0, 0, 1, -1};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      char x[4];
      scanf("%s", x);
      a[i][j] = (x[0] == '1');
    }
  int cid = 1;
  queue<pair<int, int> > q;
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (!a[i][j] || id[i][j] != 0) continue;
      int area = 0;
      q.push(make_pair(i, j));
      id[i][j] = cid;
      int xsum = 0, ysum = 0;
      while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        area++;
        xsum += cx;
        ysum += cy;
        for (int k = 0; k < 4; ++k) {
          int nx = cx + DX[k];
          int ny = cy + DY[k];
          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (a[nx][ny] && id[nx][ny] == 0) {
            id[nx][ny] = cid;
            q.push(make_pair(nx, ny));
          }
        }
      }
      if (area < 150) continue;
      long double xx = long double(xsum) / area;
      long double yy = long double(ysum) / area;
      long double maxDist = 0;
      for (int ii = 0; ii < n; ++ii)
        for (int jj = 0; jj < n; ++jj) {
          if (!(id[ii][jj] == cid)) continue;
          long double dx = i - xx, dy = j - yy;
          long double curDist = sqrt(dx * dx + dy * dy);
          maxDist = max(maxDist, curDist);
        }
      long double coeff = long double(area) / (maxDist * maxDist);
      if (coeff > 2.2)
        ans1++;
      else
        ans2++;
      cid++;
    }
  cout << ans1 << ' ' << ans2 << '\n';
  return 0;
}
