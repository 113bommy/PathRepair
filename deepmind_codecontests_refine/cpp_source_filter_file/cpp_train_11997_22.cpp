#include <bits/stdc++.h>
struct node {
  int x, y;
} bp;
char s[105][105];
int up[105][105], down[105][105], left[105][105], right[105][105], dp, cp,
    a[105][105], len, n, m;
void go() {
  if (dp == 1) {
    bp.x = up[bp.x][bp.y];
    if (cp == 0)
      bp.y = left[bp.x][bp.y];
    else
      bp.y = right[bp.x][bp.y];
  }
  if (dp == 2) {
    bp.y = right[bp.x][bp.y];
    if (cp == 0)
      bp.x = up[bp.x][bp.y];
    else
      bp.x = down[bp.x][bp.y];
  }
  if (dp == 3) {
    bp.x = down[bp.x][bp.y];
    if (cp == 0)
      bp.y = right[bp.x][bp.y];
    else
      bp.y = left[bp.x][bp.y];
  }
  if (dp == 4) {
    bp.y = left[bp.x][bp.y];
    if (cp == 0)
      bp.x = down[bp.x][bp.y];
    else
      bp.x = right[bp.x][bp.y];
  }
}
void update() {
  if (dp == 1) {
    if (bp.x - 1 >= 1 && a[bp.x - 1][bp.y] != 0)
      bp.x--;
    else {
      if (cp == 0)
        cp = 1;
      else
        cp = 0, dp++, dp = (dp - 1) % 4 + 1;
    }
  } else if (dp == 2) {
    if (bp.y + 1 <= len && a[bp.x][bp.y + 1] != 0)
      bp.y++;
    else {
      if (cp == 0)
        cp = 1;
      else
        cp = 0, dp++, dp = (dp - 1) % 4 + 1;
    }
  } else if (dp == 3) {
    if (bp.x + 1 <= n && a[bp.x + 1][bp.y] != 0)
      bp.x++;
    else {
      if (cp == 0)
        cp = 1;
      else
        cp = 0, dp++, dp = (dp - 1) % 4 + 1;
    }
  } else {
    if (bp.y - 1 >= 1 && a[bp.x][bp.y - 1] != 0)
      bp.y--;
    else {
      if (cp == 0)
        cp = 1;
      else
        cp = 0, dp++, dp = (dp - 1) % 4 + 1;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  len = strlen(s[1] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= len; j++) a[i][j] = s[i][j] - '0';
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= len; j++)
      up[i][j] = down[i][j] = i, left[i][j] = right[i][j] = j;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= len; j++)
      if (a[i][j] == a[i][j - 1] && a[i][j] != 0)
        left[i][j] = j - 1, right[i][j - 1] = j;
  for (int j = 1; j <= len; j++)
    for (int i = 1; i <= n; i++)
      if (a[i][j] == a[i - 1][j] && a[i][j] != 0)
        up[i][j] = i - 1, down[i - 1][j] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= len; j++) {
      int l = j, r = j;
      while (left[i][j] != l)
        left[i][j] = left[i][left[i][j]], l = left[i][left[i][j]];
      while (right[i][j] != r)
        right[i][j] = right[i][right[i][j]], r = right[i][right[i][j]];
    }
  for (int j = 1; j <= len; j++)
    for (int i = 1; i <= n; i++) {
      int u = i, d = i;
      while (up[i][j] != u) up[i][j] = up[up[i][j]][j], u = up[up[i][j]][j];
      while (down[i][j] != d)
        down[i][j] = down[down[i][j]][j], d = down[down[i][j]][j];
    }
  bp = node{1, 1};
  dp = 2, cp = 0;
  while (m--) {
    go();
    update();
  }
  printf("%d", a[bp.x][bp.y]);
}
