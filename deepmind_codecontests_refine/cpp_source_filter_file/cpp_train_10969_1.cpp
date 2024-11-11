#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[210][210];
struct node {
  int x, y, w;
} p[20010], q[210];
bool cmp(node p1, node p2) { return p1.x < p2.x; }
int find(int s) {
  int i, j;
  for (i = 0; i < m; i++) {
    int x = p[i].x;
    int y = p[i].y;
    int len = 0;
    for (j = 0; j < n; j++) {
      int l = s - c[x][j];
      int r = s - c[y][j];
      if (l < 0) l = -1;
      if (r < 0) r = -1;
      if (l == -1 && r == -1) break;
      if (l + r >= p[i].w - 1) continue;
      q[len].x = l + 1;
      q[len].y = p[i].w - r - 1;
      len++;
    }
    if (j < n) continue;
    if (len == 0) return 1;
    sort(q, q + len, cmp);
    int mx = 0;
    for (j = 0; j < len; j++) {
      if (q[j].x > mx) {
        return 1;
      }
      if (q[j].y + 1 > mx) mx = q[j].y + 1;
    }
  }
  return 0;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    int i, j, k;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        c[i][j] = 1000000000;
      }
      c[i][i] = 0;
    }
    for (i = 0; i < m; i++) {
      int x, y, w;
      scanf("%d%d%d", &x, &y, &w);
      x--;
      y--;
      p[i].x = x;
      p[i].y = y;
      p[i].w = w * 2;
      c[x][y] = c[y][x] = w * 2;
    }
    for (k = 0; k < n; k++) {
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          if (c[i][k] == 1000000000) continue;
          if (c[j][k] == 1000000000) continue;
          if (c[i][k] + c[j][k] < c[i][j]) c[i][j] = c[i][k] + c[j][k];
        }
      }
    }
    int l = 0, h = 200002;
    int ans;
    int z = 0;
    while (l <= h) {
      int mid = (l + h) / 2;
      if (find(mid)) {
        ans = mid;
        h = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    printf("%.2lf\n", (double)ans / 2.0);
  }
  return 0;
}
