#include <bits/stdc++.h>
char map[1001][1010];
struct point {
  int x;
  int y;
} p[1001];
point newpoint(int x, int y) {
  point re;
  re.x = x;
  re.y = y;
  return re;
}
int n;
int main() {
  scanf("%d", &n);
  p[0] = newpoint(0, 0);
  int s1 = 0;
  int s2 = 0;
  int min = 0;
  int max = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    s1 += x;
    if (i % 2 == 0)
      s2 += x;
    else
      s2 -= x;
    p[i + 1] = newpoint(s1, s2);
    if (s2 > max) max = s2;
    if (s2 < min) min = s2;
  }
  for (int i = 0; i < max - min; i++) {
    for (int j = 0; j < p[n].x; j++) map[i][j] = ' ';
    map[i][p[n].x] = 0;
  }
  for (int i = 0; i <= n; i++) p[i].y -= min;
  max -= min;
  max--;
  for (int i = 0; i < n; i++) {
    double k = ((double)(p[i + 1].x - p[i].x)) / (p[i + 1].y - p[i].y);
    int tx = p[i].x;
    int ty = p[i].y - 1;
    bool f = false;
    if (ty < p[i + 1].y) f = true;
    int loop = 0;
    while (tx != p[i + 1].x) {
      loop++;
      if (f)
        map[max - ty - 1][tx] = '/';
      else
        map[max - ty][tx] = '\\';
      if (f)
        ty++;
      else
        ty--;
      if (f)
        tx = (int)(p[i].x + loop * k);
      else
        tx = (int)(p[i].x - loop * k);
    }
  }
  for (int i = 0; i <= max; i++) printf("%s\n", map[i]);
}
