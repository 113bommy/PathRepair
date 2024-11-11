#include <bits/stdc++.h>
using namespace std;
int d[1001][1001], a[1001][1001], n, m, xs, ys, xt, yt;
int tx[] = {-1, 1, 0, 0};
int ty[] = {0, 0, -1, 1};
void dij() {
  priority_queue<pair<pair<int, int>, pair<int, int> >,
                 vector<pair<pair<int, int>, pair<int, int> > >,
                 greater<pair<pair<int, int>, pair<int, int> > > >
      q;
  q.push(pair<pair<int, int>, pair<int, int> >(pair<int, int>(0, -1),
                                               pair<int, int>(xs, ys)));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      d[i][j] = 1e9;
    }
  }
  d[xs][ys] = 0;
  while (q.size()) {
    int x = q.top().second.first;
    int y = q.top().second.second;
    int h = q.top().first.second;
    int dxy = q.top().first.first;
    q.pop();
    if (dxy != d[x][y]) continue;
    for (int j = 0; j < 4; ++j) {
      int xx = x + tx[j];
      int yy = y + ty[j];
      if (xx < 1 || yy < 1 || xx > n || yy > m || a[xx][yy] == 0) continue;
      int uxy;
      if (h == -1) {
        uxy = 0;
      } else if (h != j) {
        uxy = 1;
      } else {
        uxy = 0;
      }
      if (d[xx][yy] > dxy + uxy) {
        d[xx][yy] = dxy + uxy;
        q.push(pair<pair<int, int>, pair<int, int> >(
            pair<int, int>(d[xx][yy], j), pair<int, int>(xx, yy)));
      }
    }
  }
}
int main() {
  if (fopen("test.inp", "r")) {
    freopen("test.inp", "r", stdin);
  }
  ios_base ::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      if (c == 'S') {
        xs = i;
        ys = j;
        a[i][j] = 1;
      } else if (c == 'T') {
        xt = i;
        yt = j;
        a[i][j] = 1;
      } else if (c == '.') {
        a[i][j] = 1;
      } else {
        a[i][j] = 0;
      }
    }
  }
  dij();
  if (d[xt][yt] <= 2) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
