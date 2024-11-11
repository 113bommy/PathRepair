#include <bits/stdc++.h>
using namespace std;
const int g[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int val[10], pos[10], xp[10], yp[10], n, m, cnt;
char s[30][30];
struct zt {
  int x, y, s;
  zt(int a = 0, int b = 0, int c = 0) {
    x = a;
    y = b;
    s = c;
  }
} q[200010], t;
int gao(int x, int y, int py, int s) {
  for (int i = 0; i < cnt; i++) {
    if (xp[i] < x &&
        ((y == yp[i] && py == yp[i] + 1) || (y == yp[i] + 1 && py == yp[i])))
      s ^= 1 << i;
  }
  return s;
}
int f[30][30][256];
int main() {
  int tc, i, j, sx, sy, x, y, head, tail, ans, sum;
  bool flag;
  scanf("%d%d", &n, &m);
  tc = 0;
  for (i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for (j = 1; j <= m; j++) {
      if (s[i][j] == 'B') {
        xp[cnt] = i;
        yp[cnt] = j;
        val[cnt] = -400;
        cnt++;
      }
      if ('1' <= s[i][j] && s[i][j] <= '9') {
        xp[cnt] = i;
        yp[cnt] = j;
        pos[s[i][j] - '1'] = cnt;
        cnt++;
        tc++;
      }
      if (s[i][j] == 'S') {
        sx = i;
        sy = j;
      }
    }
  }
  for (i = 0; i < tc; i++) scanf("%d", val + pos[i]);
  memset(f, -1, sizeof(f));
  head = tail = 1;
  q[1] = zt(sx, sy, 0);
  f[sx][sy][0] = 0;
  while (head <= tail) {
    t = q[head++];
    for (i = 0; i < 4; i++) {
      x = t.x + g[i][0];
      y = t.y + g[i][1];
      if (0 < x && x <= n && 0 < y && y <= m &&
          (s[x][y] == '.' || s[x][y] == 'S')) {
        j = gao(x, y, t.y, t.s);
        if (~f[x][y][j]) continue;
        f[x][y][j] = f[t.x][t.y][t.s] + 1;
        q[++tail] = zt(x, y, j);
      }
    }
  }
  ans = 0;
  for (i = 0; i < 1 << cnt; i++) {
    if (~f[sx][sy][i]) {
      flag = 0;
      sum = 0;
      for (j = 0; j < cnt; j++) {
        if (i >> j & 1) {
          if (val[j] == -400) {
            flag = 1;
            break;
          }
          sum += val[j];
        }
      }
      if (flag) continue;
      ans = max(ans, sum - f[sx][sy][i]);
    }
  }
  printf("%d", ans);
}
