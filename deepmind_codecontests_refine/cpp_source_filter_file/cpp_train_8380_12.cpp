#include <bits/stdc++.h>
using namespace std;
int n, m;
int flag, sum, ave, ans, res, len, ans1, ans2;
int g[512][512];
char s[112345];
struct node {
  int x, y;
  int r, w;
  int to, next;
  void init() { r = 0; }
  friend bool operator<(node a, node b) { return a.r > b.r; }
} tn;
int main() {
  int i, j, k, kk, t, x, y, z, xx, yy;
  while (scanf("%d%d%d%d", &n, &m, &x, &y) != EOF) {
    memset(g, 0, sizeof(g));
    scanf("%s", s);
    z = strlen(s);
    printf("1");
    res = 1;
    g[x][y] = 1;
    for (i = 0; i < z - 1; i++) {
      if (s[i] == 'U') xx = x - 1, yy = y;
      if (s[i] == 'D') xx = x + 1, yy = y;
      if (s[i] == 'L') xx = x, yy = y - 1;
      if (s[i] == 'R') xx = x, yy = y + 1;
      if (xx == 0) xx = 1;
      if (xx == n + 1) xx = n;
      if (yy == 0) y = 1;
      if (yy == m + 1) yy = m;
      if (!g[xx][yy]) {
        res++;
        printf(" 1");
      } else
        printf(" 0");
      g[xx][yy] = 1;
      x = xx;
      y = yy;
    }
    printf(" %d\n", n * m - res);
  }
  return 0;
}
