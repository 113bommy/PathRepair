#include <bits/stdc++.h>
using namespace std;
int h, w;
unsigned long long a[501][501];
char mp[501][501];
int dx[] = {0, 1}, dy[] = {1, 0};
signed main() {
  cin >> h >> w;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> mp[i][j];
    }
  }
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j) {
      for (int k = 0; k < 2; ++k) {
        int ny = i + dy[k], nx = j + dx[k];
        if (ny >= h || nx >= w) continue;
        if (mp[i][j] == '.' && mp[ny][nx] == '.') a[i][j]++;
      }
    }
  for (int i = 0; i < h; ++i) {
    for (int j = 1; j < w; ++j) {
      a[i][j] += a[i][j - 1];
    }
  }
  int q;
  cin >> q;
  for (int ii = 0; ii < q; ++ii) {
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    x1--;
    y1--;
    x2--;
    y2--;
    unsigned long long ans = 0;
    for (int i = y1; i <= y2; ++i) {
      ans += a[i][x2];
    }
    if (x1 - 1 >= 0) {
      for (int i = y1; i <= y2; ++i) ans -= a[i][x1 - 1];
    }
    for (int i = y1; i <= y2; ++i)
      if (x2 + 1 <= w && mp[i][x2] == '.' && mp[i][x2 + 1] == '.') ans--;
    for (int i = x1; i <= x2; ++i)
      if (y2 + 1 <= h && mp[y2][i] == '.' && mp[y2 + 1][i] == '.') ans--;
    cout << ans << endl;
  }
}
