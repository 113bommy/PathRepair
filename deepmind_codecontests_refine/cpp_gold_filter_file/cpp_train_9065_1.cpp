#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
const int maxn = 1205;
const double pi = acos(-1.0);
const int modn = 1000000007;
char mpp[maxn][maxn];
int n, m;
int resx[1000055], resy[1000055], reslen[1000055];
int idx = 0;
int num = 0;
int vis[maxn][maxn];
bool can(int x, int y, int step) {
  if ((x - step < 0) || (x + step >= n) || (y - step < 0) || (y + step >= m)) {
    return false;
  }
  if (mpp[x - step][y] == '*' && mpp[x][y - step] == '*' &&
      mpp[x + step][y] == '*' && mpp[x][y + step] == '*') {
    vis[x][y] = 1;
    vis[x - step][y] = vis[x][y - step] = vis[x + step][y] = vis[x][y + step] =
        1;
    return true;
  }
  return false;
}
int star(int x, int y) {
  if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
    return -1;
  }
  int maxlen = -0x3f3f3f3f;
  for (int i = 1; i <= max(n, m); i++) {
    if (can(x, y, i)) {
      maxlen = max(maxlen, i);
    } else
      break;
  }
  return maxlen == -0x3f3f3f3f ? -1 : maxlen;
}
void func() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mpp[i][j] == '*') {
        int maxsum = star(i, j);
        if (maxsum != -1) {
          num++;
          resx[idx] = i + 1;
          resy[idx] = j + 1;
          reslen[idx] = maxsum;
          idx++;
        }
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", mpp[i]);
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mpp[i][j] == '*') {
        flag = 1;
        break;
      }
    }
    if (flag) break;
  }
  if (!flag) {
    printf("0\n");
    return 0;
  }
  memset(vis, 0, sizeof(vis));
  func();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mpp[i][j] == '*' && !vis[i][j]) {
        printf("-1\n");
        return 0;
      }
    }
  }
  printf("%d\n", num);
  for (int i = 0; i < num; i++) {
    printf("%d %d %d\n", resx[i], resy[i], reslen[i]);
  }
}
