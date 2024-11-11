#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 10;
struct Point {
  int x, y;
} p[MAX];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);
  int minx = 1e9, miny = 1e9;
  int maxx = -1e9, maxy = -1e9;
  for (int i = 0; i < n; i++) {
    minx = min(minx, p[i].x);
    miny = min(miny, p[i].y);
    maxy = max(maxy, p[i].y);
    maxx = max(maxx, p[i].x);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, p[i].x - minx + p[i].y - miny);
    ans = max(ans, p[i].x - minx + maxy - p[i].y);
    ans = max(ans, maxx - p[i].x + maxy - p[i].y);
    ans = max(ans, maxx - p[i].x + p[i].y - miny);
  }
  printf("%d", ans);
  for (int i = 4; i <= n; i++) printf(" %d", 2 * (maxx - minx + maxy - miny));
  return 0;
}
