#include <bits/stdc++.h>
int v[105][105], t[105][105], len[105];
int main() {
  int n, s;
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", len + i);
    for (int j = 0; j < len[i]; j++) {
      scanf("%d%d", v[i] + j, t[i] + j);
      t[i][j] += j ? t[i][j - 1] : 0;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int x = 0, y = 0, curt = 0, curx = 0, cury = 0;
      while (x < len[i] && y < len[j]) {
        int dx = v[i][x], dy = v[j][y], dt;
        if (t[i][x] < t[j][y]) {
          dt = t[i][x] - curt;
          x++;
        } else if (t[i][x] > t[j][y]) {
          dt = t[j][y] - curt;
          y++;
        } else {
          dt = t[i][x] - curt;
          x++;
          y++;
        }
        dx *= dt;
        dy *= dt;
        ans += (long long)(curx - cury) * (cury + dy - curx - dx) > 0;
        curx += dx;
        cury += dy;
        curt += dy;
        if (curx == cury) ans += (long long)(dx - dy) * (v[i][x] - v[j][y]) > 0;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
