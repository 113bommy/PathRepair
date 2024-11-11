#include <bits/stdc++.h>
using namespace std;
const int UNDEF = -1;
const int INF = 1999999999;
const double EPS = 1e-9;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int m, n, w;
inline bool chk(int y, int x) { return !(y < 0 || x < 0 || m <= y || w <= x); }
int main() {
  while (cin >> m >> n) {
    vector<string> map(m);
    for (int i = 0; i < (m); ++i) {
      cin >> map[i];
    }
    w = map[0].size();
    int y = 0, x = 0;
    int dp = 0, cp = 3;
    int memo[m][w][4][4];
    for (int y = 0; y < (m); ++y)
      for (int x = 0; x < (w); ++x)
        for (int i = 0; i < (4); ++i)
          for (int j = 0; j < (4); ++j) {
            memo[y][x][i][j] = -1;
          }
    bool cut = false;
    for (int i = 0; i < (n); ++i) {
      if (!cut && memo[y][x][dp][cp] != -1) {
        int rest = n - i - 1;
        int loop = i - memo[y][x][dp][cp];
        i += (rest / loop) * loop;
        cut = true;
      } else {
        memo[y][x][dp][cp] = i;
      }
      while (1) {
        int ny = y + dy[dp], nx = x + dx[dp];
        if (chk(ny, nx) && map[y][x] == map[ny][nx]) {
          y = ny;
          x = nx;
        } else {
          break;
        }
      }
      int np = (dp + cp) % 4;
      while (1) {
        int ny = y + dy[np], nx = x + dx[np];
        if (chk(ny, nx) && map[y][x] == map[ny][nx]) {
          y = ny;
          x = nx;
        } else {
          break;
        }
      }
      int ny = y + dy[dp], nx = x + dx[dp];
      if (chk(ny, nx) && map[ny][nx] != '0') {
        y = ny;
        x = nx;
      } else if (cp == 3) {
        cp = 1;
      } else {
        cp = 3;
        dp = (dp + 1) % 4;
      }
    }
    cout << map[y][x] << endl;
  }
  return 0;
}
