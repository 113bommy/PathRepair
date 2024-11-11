#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char pd[65536][4][4][4][4];
int play(int tab, int ax, int ay, int bx, int by);
inline int M(int x, int y) { return 1 << (4 * x + y); }
inline int A(int tab, int x, int y) { return tab & M(x, y); }
inline int D(int ax, int ay, int bx, int by) {
  return abs(ax - bx) + abs(ay - by);
}
int play2(int tab, int ax, int ay, int bx, int by) {
  int out = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!A(tab, i, j) && (i != ax || j != ay) && (i != bx || j != by)) {
        if (!play(tab | M(i, j), ax, ay, bx, by)) {
          out = 1;
        }
      }
    }
  }
  return out;
}
int play(int tab, int ax, int ay, int bx, int by) {
  if (pd[tab][ax][ay][bx][by] != -1) {
    return pd[tab][ax][ay][bx][by];
  }
  if (ax == bx && ay == by) {
    return 1;
  }
  int out = 0;
  if (!A(tab, ax, ay)) {
    for (int d = 0; d < 4; d++) {
      int cx = ax + dx[d];
      int cy = ay + dy[d];
      if (0 <= cx && cx < n && 0 <= cy && cy < m) {
        if (D(cx, cy, bx, by) < D(ax, ay, bx, by)) {
          if (!play2(tab, cx, cy, bx, by)) {
            out = 1;
          }
        }
      }
    }
  }
  if (!A(tab, bx, by)) {
    for (int d = 0; d < 4; d++) {
      int cx = bx + dx[d];
      int cy = by + dy[d];
      if (0 <= cx && cx < n && 0 <= cy && cy < m) {
        if (D(ax, ay, cx, cy) < D(ax, ay, bx, by)) {
          if (!play2(tab, ax, ay, cx, cy)) {
            out = 1;
          }
        }
      }
    }
  }
  return pd[tab][ax][ay][bx][by] = out;
}
int main() {
  int ax, ay, bx, by;
  scanf("%*d %*d %d %d %d %d", &ax, &ay, &bx, &by);
  if (max(abs(bx - ax), abs(by - ay)) == 4 &&
      min(abs(bx - ax), abs(by - ay)) == 0) {
    printf("First\n");
    return 0;
  } else if (max(abs(bx - ax), abs(by - ay)) >= 4) {
    printf("Second\n");
    return 0;
  }
  int mx = min(ax, bx);
  int my = min(ay, by);
  ax -= mx;
  bx -= mx;
  ay -= my;
  by -= my;
  n = max(ax, bx) + 1;
  m = max(ay, by) + 1;
  memset(pd, -1, sizeof(pd));
  printf("%s\n", play(0, ax, ay, bx, by) ? "First" : "Second");
  return 0;
}
