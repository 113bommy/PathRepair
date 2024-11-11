#include <bits/stdc++.h>
using namespace std;
int x[4];
int y[4];
int ans = 0;
int bx = 0, by = 0;
bool a[1010][1010];
void draw(int x0, int y0, int x1, int y1) {
  a[x0][y0] = true;
  while (x0 != x1 || y0 != y1) {
    if (x0 != x1) {
      x0 += x1 > x0 ? 1 : -1;
      a[x0][y0] = true;
    } else {
      y0 += y1 > y0 ? 1 : -1;
      a[x0][y0] = true;
    }
  }
}
int main() {
  for (int i = 0; i < 3; ++i) {
    cin >> x[i] >> y[i];
  }
  memset(a, 0, sizeof(a));
  ans = 1001 * 1001;
  for (int i = 0; i <= 1000; i++)
    for (int j = 0; j <= 1000; j++) {
      if (abs(i - x[0]) + abs(j - y[0]) + abs(i - x[1]) + abs(j - y[1]) +
              abs(i - x[2]) + abs(j - y[2]) <
          ans) {
        ans = abs(i - x[0]) + abs(j - y[0]) + abs(i - x[1]) + abs(j - y[1]) +
              abs(i - x[2]) + abs(j - y[2]);
        bx = i;
        by = j;
      }
    }
  cout << ans + 1 << endl;
  draw(x[0], y[0], bx, by);
  draw(x[1], y[1], bx, by);
  draw(x[2], y[2], bx, by);
  for (int i = 0; i <= 1000; i++)
    for (int j = 0; j < 1000; j++)
      if (a[i][j]) {
        cout << i << " " << j << endl;
      }
  return 0;
}
