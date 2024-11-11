#include <bits/stdc++.h>
using namespace std;
struct state {
  int x, y, dir;
  bool left;
};
const static int dx[4] = {1, 0, -1, 0};
const static int dy[4] = {0, 1, 0, -1};
struct solve {
  int b[52][52];
  int mem[52][52][4][2];
  void adjust(state& s) {
    bool incx = dx[s.dir] > 0;
    if (dx[s.dir] == 0 &&
        ((dy[s.dir] > 0 && s.left) || (dy[s.dir] < 0 && !s.left)))
      incx = true;
    bool incy = dy[s.dir] > 0;
    if (dy[s.dir] == 0 &&
        ((dx[s.dir] > 0 && !s.left) || (dx[s.dir] < 0 && s.left)))
      incy = true;
    int ix = incx ? 1 : -1;
    int iy = incy ? 1 : -1;
    while (b[s.y][s.x] == b[s.y][s.x + ix]) s.x += ix;
    while (b[s.y][s.x] == b[s.y + iy][s.x]) s.y += iy;
    bool moved = false;
    if (dx[s.dir] != 0) {
      if (b[s.y][s.x + ix] != 0) {
        s.x += ix;
        moved = true;
      }
    }
    if (dy[s.dir] != 0) {
      if (b[s.y + iy][s.x] != 0) {
        s.y += iy;
        moved = true;
      }
    }
    if (!moved) {
      if (s.left)
        s.left = false;
      else {
        s.left = true;
        s.dir = (s.dir + 1) % 4;
      }
    }
  }
  void doit() {
    memset(b, 0, sizeof(b));
    memset(mem, -1, sizeof(mem));
    int m, N;
    cin >> m >> N;
    for (int i = 0; i < m; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); ++j) b[i + 1][j + 1] = s[j] - '0';
    }
    state s;
    s.x = 1;
    s.y = 1;
    s.dir = 0;
    s.left = true;
    int t = 0;
    while (t < N) {
      adjust(s);
      ++t;
      int& loc = mem[s.x][s.y][s.dir][s.left ? 1 : 0];
      if (loc < 0)
        loc = t;
      else {
        int diff = t - loc;
        int rem = N - t;
        if ((rem % diff) == 0) t = N;
      }
    }
    int ret = b[s.y][s.x];
    cout << ret << endl;
  }
};
int main() {
  solve s;
  s.doit();
  return 0;
}
