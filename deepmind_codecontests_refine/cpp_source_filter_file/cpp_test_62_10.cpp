#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int m, n, q;
long long f[N][N][2];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> q;
  memset(f, 0, sizeof f);
  long long cnt = n * m;
  long long total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      f[i][j][0] = 1;
      f[i][j][1] = 1;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      f[i][j][0] += f[i][j + 1][1];
      f[i][j][1] += f[i + 1][j][0];
      total += (f[i][j][0] + f[i][j][1]);
    }
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    int change0, change1;
    if (f[x][y][0] > 0) {
      change0 = -f[x][y][1];
      change1 = -f[x][y][0];
      f[x][y][0] = f[x][y][1] = 0;
      total += (change0 + change1);
      cnt--;
    } else {
      change0 = f[x][y][1] = f[x + 1][y][0] + 1;
      change1 = f[x][y][0] = f[x][y + 1][1] + 1;
      total += (change0 + change1);
      cnt++;
    }
    int t = 1;
    int xx = x;
    int yy = y;
    bool failed = false;
    while (!failed) {
      if (t & 1) {
        x--;
        if (x < 0 || y < 0 || f[x][y][0] == 0)
          failed = true;
        else {
          f[x][y][1] += change1;
          total += change1;
        }
      } else {
        y--;
        if (x < 0 || y < 0 || f[x][y][0] == 0)
          failed = true;
        else {
          f[x][y][0] += change0;
          total += change0;
        }
      }
      t++;
    }
    x = xx;
    y = yy;
    t = 1;
    failed = false;
    while (!failed) {
      if (t & 1) {
        y--;
        if (x < 0 || y < 0 or f[x][y][0] == 0)
          failed = true;
        else {
          f[x][y][0] += change0;
          total += change0;
        }
      } else {
        x--;
        if (x < 0 || y < 0 or f[x][y][0] == 0)
          failed = true;
        else {
          f[x][y][1] += change1;
          total += change1;
        }
      }
      t++;
    }
    cout << total - cnt << endl;
  }
  return 0;
}
