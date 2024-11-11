#include <bits/stdc++.h>
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
using namespace std;
int x[4], y[4];
int a[4], b[4];
bool vis[1005][1005];
void fun(int xm, int ym, int x, int y) {
  if (xm >= x) {
    for (int i = x; i <= xm; i++) {
      if (!vis[i][y]) {
        printf("%d %d\n", i, y);
        vis[i][y] = true;
      }
    }
  } else if (xm <= x) {
    for (int i = x; i >= xm; i--) {
      if (!vis[i][y]) {
        printf("%d %d\n", i, y);
        vis[i][y] = true;
      }
    }
  }
  if (ym >= y + 1) {
    for (int i = y + 1; i <= ym; i++) {
      if (!vis[xm][i]) {
        printf("%d %d\n", xm, i);
        vis[xm][i] = true;
      }
    }
  } else if (ym <= y - 1) {
    for (int i = y - 1; i >= ym; i--) {
      if (!vis[xm][i]) {
        printf("%d %d\n", xm, i);
        vis[xm][i] = true;
      }
    }
  }
}
int main() {
  int maxx = 0, maxy = 0;
  int minx = INF, miny = 0;
  for (int i = 1; i <= 3; i++)
    scanf("%d %d", &x[i], &y[i]),
        a[i] = x[i], b[i] = y[i], maxx = max(maxx, x[i]),
        maxy = max(maxy, y[i]), minx = min(minx, x[i]), miny = min(miny, y[i]);
  printf("%d\n", maxx - minx + maxy - miny + 1);
  int xm, ym;
  nth_element(x + 1, x + 2, x + 1 + 3);
  xm = x[2];
  nth_element(y + 1, y + 2, y + 1 + 3);
  ym = y[2];
  for (int i = 1; i <= 3; i++) {
    fun(xm, ym, a[i], b[i]);
  }
  return 0;
}
