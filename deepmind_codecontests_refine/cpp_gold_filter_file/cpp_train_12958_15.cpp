#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
};
Point p[100005];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int maxX = -9999999;
    int maxY = -9999999;
    int minX = 9999999;
    int minY = 9999999;
    int k[4];
    k[0] = k[2] = 9999999;
    k[1] = k[3] = -9999999;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &p[i].x, &p[i].y);
      maxX = max(maxX, p[i].x);
      maxY = max(maxY, p[i].y);
      minX = min(minX, p[i].x);
      minY = min(minY, p[i].y);
      int t = p[i].x + p[i].y;
      k[0] = min(k[0], t);
      k[3] = max(k[3], t);
      t = p[i].y - p[i].x;
      k[2] = min(k[2], t);
      k[1] = max(k[1], t);
    }
    minX--;
    minY--;
    maxX++;
    maxY++;
    k[0]--;
    k[1]++;
    k[2]--;
    k[3]++;
    int d[8];
    d[0] = k[0] - minY;
    d[1] = minY - k[2];
    d[2] = maxX + k[2];
    d[3] = k[3] - maxX;
    d[4] = k[3] - maxY;
    d[5] = maxY - k[1];
    d[6] = minX + k[1];
    d[7] = k[0] - minX;
    int ans = 0;
    ans += d[1] - d[0] + 1;
    ans += d[3] - d[2] + 1;
    ans += d[4] - d[5] + 1;
    ans += d[6] - d[7] + 1;
    ans += d[7] - minY - 1;
    ans += d[2] - minY - 1;
    ans += maxY - d[3] - 1;
    ans += maxY - d[6] - 1;
    printf("%d\n", ans);
  }
  return 0;
}
