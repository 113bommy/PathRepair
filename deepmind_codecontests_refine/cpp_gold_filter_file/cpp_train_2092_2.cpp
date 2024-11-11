#include <bits/stdc++.h>
using namespace std;
long long ax, bx;
long long ay, by;
int get(long long x, long long y) {
  cout << x << " " << y << endl;
  cout.flush();
  int ret = 0;
  cin >> ret;
  return ret;
}
bool dfs(long long x, long long y) {
  while (ax <= x && x <= bx && ay <= y && y <= by) {
    long long xx = ax + (x - ax) / 2;
    long long yy = ay + (y - ay) / 2;
    long long dx = x - ax, dy = y - ay;
    if (dx * 2 <= dy) {
      xx = x - dx / 20;
    }
    if (dy * 2 <= dx) {
      yy = y - dy / 20;
    }
    int r = get(xx, yy);
    if (r == 0) {
      ax = bx = xx;
      ay = by = yy;
      return true;
    }
    if (r == 1) {
      ax = xx + 1;
    } else if (r == 2) {
      ay = yy + 1;
    } else {
      if (xx - 1 < ax) {
        by = yy - 1;
        return false;
      }
      if (yy - 1 < ay) {
        bx = xx - 1;
        return false;
      }
      return dfs(xx - 1, yy - 1);
    }
  }
  if (y < ay) {
    bx = min(x, bx);
  }
  if (x < ax) {
    by = min(y, by);
  }
  return false;
}
int main() {
  long long n;
  cin >> n;
  ax = ay = 1;
  bx = by = n;
  while (ax != bx || ay != by) {
    if (dfs(bx, by)) {
      return 0;
    }
  }
  cout << ax << " " << ay << endl;
  return 0;
}
