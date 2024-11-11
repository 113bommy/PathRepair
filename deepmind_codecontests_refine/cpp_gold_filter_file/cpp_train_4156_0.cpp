#include <iostream>

using namespace std;

int w, h;
int f[21][21];
int ans;

int dx[] = { 0, 0, -1, 1};
int dy[] = {-1, 1,  0, 0};

void rec(int n, int x, int y) {
  if (n >= ans) { return; }

  for (int i=0; i<4; i++) {
    int mx=x, my=y;
    mx += dx[i]; my += dy[i];
    if (mx < 0 || mx >= w) { continue; }
    if (my < 0 || my >= h) { continue; }
    if (f[my][mx] == 1) { continue; }

    while (1) {
      if (f[my][mx] == 3) {
        ans = n;
        return;
      }

      mx += dx[i]; my += dy[i];
      if (mx < 0 || mx >= w) { break; }
      if (my < 0 || my >= h) { break; }

      if (f[my][mx] == 1) {
        f[my][mx] = 0;
        rec(n+1, mx-dx[i], my-dy[i]);
        f[my][mx] = 1;
        break;
      }
    }
  }
}

int main() {
  while (cin >> w >> h, (w || h)) {
    int sx, sy;
    for (int y=0; y<h; y++) {
      for (int x=0; x<w; x++) {
        cin >> f[y][x];
        if (f[y][x] == 2) {
          sx = x; sy = y;
        }
      }
    }

    ans = 11;
    rec(1, sx, sy);
    if (ans > 10) { ans = -1; }
    cout << ans << endl;
  }

  return 0;
}
