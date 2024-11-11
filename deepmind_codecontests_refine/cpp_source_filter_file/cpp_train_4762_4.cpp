#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
const long long Mod = 1000000007;
int a[10][200];
struct node {
  int id, x, y;
  node(int _id = 0, int _x = 0, int _y = 0) {
    id = _id;
    x = _x;
    y = _y;
  }
} ans[maxn];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[2][i] && a[2][i] == a[1][i]) {
      ans[++cnt] = node(a[2][i], 1, i);
      a[2][i] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[3][i] && a[3][i] == a[4][i]) {
      ans[++cnt] = node(a[3][i], 4, i);
      a[3][i] = 0;
    }
  }
  int f = 0;
  int sx, sy;
  for (int i = 1; i <= n; i++) {
    if (a[2][i] == 0) {
      f = 1;
      sx = 2;
      sy = i;
      break;
    }
    if (a[3][i] == 0) {
      f = 1;
      sx = 3;
      sy = i;
      break;
    }
  }
  if (f == 0) {
    cout << -1 << endl;
    return 0;
  }
  int nx, ny;
  int d = 2 * n;
  for (int t = 1; t <= 200005; t++) {
    for (int i = 1; i <= d; i++) {
      if (sx == 2 && sy == 1) {
        nx = 3;
        ny = 1;
      } else if (sx == 3 && sy == n) {
        nx = 2;
        ny = n;
      } else {
        if (sx == 2) {
          nx = sx;
          ny = sy - 1;
        } else {
          nx = sx;
          ny = sy + 1;
        }
      }
      swap(a[sx][sy], a[nx][ny]);
      if (a[sx][sy]) {
        ans[++cnt] = node(a[sx][sy], sx, sy);
      }
      sx = nx;
      sy = ny;
    }
    for (int i = 1; i <= n; i++) {
      if (a[2][i] && a[2][i] == a[1][i]) {
        ans[++cnt] = node(a[2][i], 1, i);
        a[2][i] = 0;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (a[3][i] && a[3][i] == a[4][i]) {
        ans[++cnt] = node(a[3][i], 4, i);
        a[3][i] = 0;
      }
    }
    f = 0;
    for (int i = 1; i <= n; i++) {
      if (a[2][i]) {
        f = 1;
        break;
      }
      if (a[3][i]) {
        f = 1;
        break;
      }
    }
    if (f == 0) {
      break;
    }
  }
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++) {
    cout << ans[i].id << ' ' << ans[i].x << ' ' << ans[i].y << endl;
  }
  return 0;
}
