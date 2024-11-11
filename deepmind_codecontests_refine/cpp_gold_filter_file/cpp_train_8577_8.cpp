#include <bits/stdc++.h>
using namespace std;
struct node {
  int x1, y1, x2, y2, id;
  bool operator<(const node &t) const {
    if (y1 != t.y1) return y1 < t.y1;
    return x1 < t.x1;
  }
} a[100001];
int n, s[3001][3001], r1[3001][3001], r2[3001][3001], cnt, ans[100001];
void output(int lx, int rx, int ly, int ry) {
  for (int i = 1; i <= n; i++)
    if (a[i].x1 >= lx && a[i].x2 <= rx && a[i].y1 >= ly && a[i].y2 <= ry)
      ans[++cnt] = a[i].id;
  printf("YES %d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
  puts("");
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    for (int x = a[i].x1 + 1; x <= a[i].x2; x++)
      for (int y = a[i].y1 + 1; y <= a[i].y2; y++) s[x][y] = 1;
    for (int x = a[i].x1 + 1; x <= a[i].x2; x++)
      r1[x][a[i].y1] = r1[x][a[i].y2] = 1;
    for (int y = a[i].y1 + 1; y <= a[i].y2; y++)
      r2[a[i].x1][y] = r2[a[i].x2][y] = 1;
    a[i].id = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= 3000; i++)
    for (int j = 1; j <= 3000; j++)
      s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
  for (int i = 0; i <= 3000; i++)
    for (int j = 0; j <= 3000; j++) {
      if (i) r1[i][j] += r1[i - 1][j];
      if (j) r2[i][j] += r2[i][j - 1];
    }
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      if (a[i].y1 != a[j].y1)
        break;
      else {
        int ly = a[i].y1, lx = a[i].x1, rx = a[j].x2, ry = rx - lx + ly;
        if (ry > 3000) continue;
        if (s[rx][ry] - s[lx][ry] - s[rx][ly] + s[lx][ly] !=
            (rx - lx) * (ry - ly))
          continue;
        if (r1[rx][ry] - r1[lx][ry] != rx - lx ||
            r1[rx][ly] - r1[lx][ly] != rx - lx)
          continue;
        if (r2[rx][ry] - r2[rx][ly] != ry - ly ||
            r2[lx][ry] - r2[lx][ly] != ry - ly)
          continue;
        output(lx, rx, ly, ry);
        return 0;
      }
  puts("NO");
}
