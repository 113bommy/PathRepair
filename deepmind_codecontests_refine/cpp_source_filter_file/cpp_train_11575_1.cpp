#include <bits/stdc++.h>
using namespace std;
int n, m, ct, num, l, r, u, d;
int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
char gp[250 + 50][250 + 50];
int cnt[250 + 50][250 + 50];
void dfs(int x, int y) {
  cnt[x][y] = ct;
  l = min(l, y);
  r = max(r, y);
  u = min(u, x);
  d = max(d, x);
  num++;
  for (int i = 0; i < 8; i++) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (!(tx >= 0 && tx < n && ty >= 0 && ty < m) || cnt[tx][ty] != 0 ||
        gp[tx][ty] != '1')
      continue;
    dfs(tx, ty);
  }
}
bool check(int x, int y, int num) {
  if (num % 4) return false;
  num /= 4;
  if (l == y && r == y + num && u == x && d == x + num) {
    for (int i = 0; i <= num; i++) {
      if (!(gp[x + i][y] == '1' && gp[x + i][y + num] == '1' &&
            gp[x][y + i] == '1' && gp[x + num][y + i] == '1'))
        return false;
    }
    return true;
  } else if (l == y - num && r == y + num && u == x && d == x + 2 * num) {
    for (int i = 0; i < num; i++) {
      if (!(gp[x + i][y + i] == '1' && gp[x + num + i][y - num + i] == '1' &&
            gp[x - i][y + i] == '1' && gp[x + num - i][y + num + i] == '1'))
        return false;
    }
    return true;
  } else
    return false;
}
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    ct = 0;
    scanf("%d%d", &n, &m);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) scanf("%s", gp[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (cnt[i][j] != 0 || gp[i][j] != '1') continue;
        ct++, num = 0;
        l = r = j, u = d = i;
        dfs(i, j);
        if (check(i, j, num)) ++ans;
      }
    }
    printf("%d\n", ans);
  }
}
