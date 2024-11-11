#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int rt[N * N * 5], k;
bool u[N][N];
int a[N][N], n, c[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
char s[] = "DRUL";
void dfs(int x, int y) {
  u[x][y] = true;
  if (!a[x][y]) {
    rt[k++] = 4;
    a[x][y] = 1;
  }
  for (int h = 0; h < 4; h++) {
    int x1 = x + c[h][0], y1 = y + c[h][1], fg = 0;
    while (x1 > 0 && x1 <= n && y1 > 0 && y1 <= n && !u[x1][y1]) {
      if (a[x1][y1]) {
        fg = 1;
        break;
      }
      x1 += c[h][0];
      y1 += c[h][1];
    }
    if (fg) {
      rt[k++] = h;
      dfs(x + c[h][0], y + c[h][1]);
      rt[k++] = (h + 2) % 4;
    }
  }
  a[x][y] = 0;
  rt[k++] = 5;
}
int main() {
  int sx, sy, i, j;
  scanf("%d%d%d", &n, &sx, &sy);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  dfs(sx, sy);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++)
      if (a[i][j] && !u[i][j]) {
        puts("NO");
        return 0;
      }
  }
  puts("YES");
  for (i = 0; i < k; i++) {
    if (rt[i] < 4)
      putchar(s[rt[i]]);
    else
      printf("%d", rt[i] - 3);
  }
  return 0;
}
