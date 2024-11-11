#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int a[505][505], vis[505][505], tot, now, nex[5] = {-1, 0, 2, 0, 1},
                                          ney[5] = {0, -1, 2, 1, 0}, n;
char s[10 * 505 * 505], ss[6] = "UL*RD";
bool check(int x, int y) {
  if (x > 0 && x <= n && y > 0 && y <= n) return true;
  return false;
}
bool light(int x, int y, int d) {
  for (int i = (int)(1); i <= (int)(500); ++i) {
    if (check(x + i * nex[d + 2], y + i * ney[d + 2])) {
      if (a[x + i * nex[d + 2]][y + i * ney[d + 2]] == 1) return true;
    } else
      break;
  }
  return false;
}
int dfs(int x, int y, int pre) {
  int cnt = 0;
  vis[x][y] = 1;
  if (a[x][y] == 0)
    s[now++] = '1', a[x][y] = 1;
  else
    cnt++;
  for (int i = -2; i < 3; ++i) {
    if (i && i + pre != 0 && check(x + nex[i + 2], y + ney[i + 2]) &&
        !vis[x + nex[i + 2]][y + ney[i + 2]] && light(x, y, i)) {
      s[now++] = ss[i + 2];
      cnt += dfs(x + nex[i + 2], y + ney[i + 2], i);
    }
  }
  a[x][y] = 0;
  s[now++] = '2';
  s[now++] = ss[-pre + 2];
  return cnt;
}
int main() {
  int m, i, j, k, x, y, z, t, ca = 1, num = 0, re = 0;
  scanf("%d%d%d", &(n), &(x), &(y));
  for (int i = (int)(1); i <= (int)(n); ++i)
    for (int j = (int)(1); j <= (int)(n); ++j) {
      scanf("%d", &(a[i][j]));
      if (a[i][j] == 1) tot++;
    }
  if (dfs(x, y, 0) == tot) {
    now -= 2;
    s[now++] = '2', s[now++] = 0;
    puts("YES"), puts(s);
  } else
    puts("NO");
  return 0;
}
