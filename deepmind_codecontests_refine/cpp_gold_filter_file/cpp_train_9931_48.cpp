#include <bits/stdc++.h>
using namespace std;
int a[2222][2222], out[2222][2222], was[2222][2222];
int n, m;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
void dfs(int i, int j, vector<int>& x, vector<int>& y) {
  if (i < 0 || j < 0 || i >= n || j >= m) return;
  if (was[i][j] || a[i][j] != 1) return;
  was[i][j] = true;
  x.push_back(i);
  y.push_back(j);
  dfs(i - 1, j, x, y);
  dfs(i + 1, j, x, y);
  dfs(i, j + 1, x, y);
  dfs(i, j - 1, x, y);
}
void OUTPUT() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << out[i][j] << " ";
    cout << endl;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
      out[i][j] = a[i][j];
    }
  }
  vector<pair<int, int> > centers;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      if (a[i][j] == 1 && !was[i][j]) {
        vector<int> sx;
        vector<int> sy;
        dfs(i, j, sx, sy);
        nth_element(sx.begin(), sx.begin() + sx.size() / 2, sx.end());
        nth_element(sy.begin(), sy.begin() + sy.size() / 2, sy.end());
        centers.push_back(make_pair(sx[sx.size() / 2], sy[sy.size() / 2]));
        out[sx[sx.size() / 2]][sy[sy.size() / 2]] = 4;
      }
  }
  set<pair<int, int> > l;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      if (a[i][j] == 1) {
        int nei = 0;
        for (int k = 0; k < 8; ++k) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x >= 0 && x < n && y >= 0 && y < m) nei += a[x][y] == 1;
        }
        if (nei <= 3) {
          bool fnd = false;
          for (int dx = -3; !fnd && dx <= 3; ++dx)
            for (int dy = -3; dy <= 3; ++dy) {
              if (l.find(make_pair(i + dx, j + dy)) != l.end()) {
                fnd = true;
                break;
              }
            }
          if (!fnd) {
            l.insert(make_pair(i, j));
            out[i][j] = 2;
          }
        }
      }
  }
  vector<vector<pair<int, int> > > luch(centers.size());
  vector<pair<int, int> > ll(l.begin(), l.end());
  for (int j = 0; j < ll.size(); ++j) {
    double mind = 1e100;
    int ans = 0;
    for (int i = 0; i < centers.size(); ++i) {
      double d = sqrt(((ll[j].first - centers[i].first) *
                       (ll[j].first - centers[i].first)) +
                      ((ll[j].second - centers[i].second) *
                       (ll[j].second - centers[i].second)));
      if (d < mind) {
        mind = d;
        ans = i;
      }
    }
    luch[ans].push_back(ll[j]);
  }
  vector<int> ans;
  for (int i = 0; i < centers.size(); ++i) {
    vector<double> ratios;
    int cnt = 0;
    for (int j = 0; j < luch[i].size(); ++j) {
      int cntone = 0;
      for (int dxx = -4; dxx <= 4; dxx++)
        for (int dyy = -4; dyy <= 4; dyy++) {
          int xx = luch[i][j].first + dxx;
          int yy = luch[i][j].second + dyy;
          if (xx >= 0 && yy >= 0 && xx < n && yy < m) {
            out[xx][yy] = 7;
            cntone += a[xx][yy] == 1;
          }
        }
      if (cntone < 27) ratios.push_back(cntone);
      out[luch[i][j].first][luch[i][j].second] = cntone;
    }
    ans.push_back(ratios.size());
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
