#include <bits/stdc++.h>
using namespace std;
int n, m;
bool debug = false;
int k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void rot(int n, int *x, int *y, int rx, int ry) {
  if (ry == 0) {
    if (rx == 1) {
      *x = n - 1 - *x;
      *y = n - 1 - *y;
    }
    swap(*x, *y);
  }
}
void d2xy(int n, int d, int *x, int *y) {
  int rx, ry, s, t = d;
  *x = *y = 0;
  for (s = 1; s < n; s *= 2) {
    rx = 1 & (t / 2);
    ry = 1 & (t ^ rx);
    rot(s, x, y, rx, ry);
    *x += s * rx;
    *y += s * ry;
    t /= 4;
  }
}
int main() {
  int a, b;
  cin >> a >> b;
  int x, y;
  d2xy(a * a, b, &x, &y);
  printf("%d %d\n", x, y);
  return 0;
}
