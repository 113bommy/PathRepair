#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
char a[maxn][maxn];
pair<int, int> p[maxn * maxn];
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, 1, 0, -1};
char cg[4] = {'v', '<', '^', '>'};
int n, m;
bool ck(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.');
}
int ok(int x, int y) {
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    int fx = x + X[i];
    int fy = y + Y[i];
    if (ck(fx, fy)) ans++;
  }
  return ans;
}
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
    int h = 0, sum = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (ck(i, j) && ok(i, j) == 1) p[sum++] = make_pair(i, j);
    for (; h < sum; h++) {
      int x = p[h].first, y = p[h].second;
      for (int i = 0; i < 4; i++) {
        int fx = x + X[i];
        int fy = y + Y[i];
        if (ck(fx, fy)) {
          a[x][y] = cg[i];
          a[fx][fy] = cg[i ^ 2];
          for (int i = 0; i < 4; i++) {
            int ffx = fx + X[i];
            int ffy = fy + Y[i];
            if (ck(ffx, ffy) && ok(ffx, ffy) == 1)
              p[sum++] = make_pair(ffx, ffy);
          }
          break;
        }
      }
    }
    int flag = 0;
    for (int i = 0; i < n && !flag; i++)
      for (int j = 0; j < m && !flag; j++)
        if (a[i][j] == '.') flag = 1;
    if (flag == 1)
      printf("Not unique\n");
    else {
      for (int i = 0; i < n; i++, printf("\n"))
        for (int j = 0; j < m; j++) printf("%c", a[i][j]);
    }
  }
  return 0;
}
