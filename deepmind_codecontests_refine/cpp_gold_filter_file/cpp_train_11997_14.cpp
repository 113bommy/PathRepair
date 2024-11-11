#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-6;
inline int ROUND(double x) { return (int)(x + 0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x) - x) < EPS; }
inline bool ISEQUAL(double x, double y) {
  return fabs(x - y) <= EPS * max(fabs(x), fabs(y));
}
int H;
int W;
const int DIR = 4;
const int dy[] = {0, +1, 0, -1};
const int dx[] = {+1, 0, -1, 0};
vector<vector<int> > movable[4];
bool InArea(int y, int x) {
  return ((0) <= (x) && (x) <= (W - 1)) && ((0) <= (y) && (y) <= (H - 1));
}
void EdgeMove(int& y, int& x, int dir) {
  y += movable[dir][y][x] * dy[dir];
  x += movable[dir][y][x] * dx[dir];
}
int main() {
  int M, N;
  cin >> M >> N;
  vector<string> vs;
  for (int i = 0; i < M; i++) {
    string s;
    cin >> s;
    vs.push_back(s);
  }
  H = M;
  W = ((int)vs[0].size());
  for (int d = 0; d < 4; d++) {
    movable[d].clear();
    movable[d].resize(H);
    for (int y = 0; y < H; y++) {
      movable[d][y].resize(W);
    }
  }
  {
    const int d = 0;
    for (int y = 0; y < H; y++) {
      for (int x = W - 1; x >= 0; x--) {
        if (x != W - 1 && vs[y][x] == vs[y][x + 1]) {
          movable[d][y][x] = movable[d][y][x + 1] + 1;
        } else {
          movable[d][y][x] = 0;
        }
      }
    }
  }
  {
    const int d = 1;
    for (int x = W - 1; x >= 0; x--) {
      for (int y = H - 1; y >= 0; y--) {
        if (y != H - 1 && vs[y][x] == vs[y + 1][x]) {
          movable[d][y][x] = movable[d][y + 1][x] + 1;
        } else {
          movable[d][y][x] = 0;
        }
      }
    }
  }
  {
    const int d = 2;
    for (int y = 0; y < H; y++) {
      for (int x = 0; x <= W - 1; x++) {
        if (x != 0 && vs[y][x] == vs[y][x - 1]) {
          movable[d][y][x] = movable[d][y][x - 1] + 1;
        } else {
          movable[d][y][x] = 0;
        }
      }
    }
  }
  {
    const int d = 3;
    for (int x = W - 1; x >= 0; x--) {
      for (int y = 0; y <= H - 1; y++) {
        if (y != 0 && vs[y][x] == vs[y - 1][x]) {
          movable[d][y][x] = movable[d][y - 1][x] + 1;
        } else {
          movable[d][y][x] = 0;
        }
      }
    }
  }
  int x = 0;
  int y = 0;
  int dp = 0;
  int dcp = -1;
  for (int n = 0; n < N; n++) {
    const int cp = (dp + dcp + DIR) % DIR;
    y += movable[dp][y][x] * dy[dp];
    x += movable[dp][y][x] * dx[dp];
    y += movable[cp][y][x] * dy[cp];
    x += movable[cp][y][x] * dx[cp];
    int ny = y + dy[dp];
    int nx = x + dx[dp];
    if (InArea(ny, nx) && vs[ny][nx] != '0') {
      y = ny;
      x = nx;
    } else {
      if (dcp == -1) {
        dcp = +1;
      } else {
        dcp = -1;
        dp = (dp + 1) % DIR;
      }
    }
  }
  printf("%d\n", vs[y][x] - '0');
}
