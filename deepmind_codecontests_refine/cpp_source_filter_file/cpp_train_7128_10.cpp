#include <bits/stdc++.h>
using namespace std;
char str[2005][2005];
void go(int x, int y) {
  int l, r, u, d;
  d = (int)(str[x + 1][y] == '.');
  u = (int)(str[x - 1][y] == '.');
  r = (int)(str[x][y + 1] == '.');
  l = (int)(str[x][y - 1] == '.');
  if (!d && !u && !r && !l) {
    cout << "Not unique" << endl;
    exit(0);
  }
  if (l && !r && !u && !d) {
    str[x][y - 1] = '<';
    str[x][y] = '>';
    if (str[x][y - 2] == '.') go(x, y - 2);
    if (str[x - 1][y - 1] == '.') go(x - 1, y - 1);
    if (str[x + 1][y - 1] == '.') go(x + 1, y - 1);
  }
  if (r && !l && !u && !d) {
    str[x][y] = '<';
    str[x][y + 1] = '>';
    if (str[x][y + 2] == '.') go(x, y + 2);
    if (str[x - 1][y + 1] == '.') go(x - 1, y + 1);
    if (str[x + 1][y + 1] == '.') go(x + 1, y + 1);
  }
  if (u && !l && !r && !d) {
    str[x - 1][y] = '^';
    str[x][y] = 'v';
    if (str[x - 2][y] == '.') go(x - 2, y);
    if (str[x - 1][y + 1] == '.') go(x - 1, y + 1);
    if (str[x - 1][y - 1] == '.') go(x - 1, y + 1);
  }
  if (d && !l && !r && !u) {
    str[x][y] = '^';
    str[x + 1][y] = 'v';
    if (str[x + 2][y] == '.') go(x + 2, y);
    if (str[x + 1][y - 1] == '.') go(x + 1, y - 1);
    if (str[x + 1][y + 1] == '.') go(x + 1, y + 1);
  }
  return;
}
int main() {
  int n, m, i, j;
  for (i = 0; i < 2005; i++)
    for (j = 0; j < 2005; j++) str[i][j] = '*';
  scanf("%d%d", &n, &m);
  getchar();
  for (i = 1; i <= n; i++) {
    gets(str[i] + 1);
    str[i][m + 1] = '*';
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (str[i][j] == '.') go(i, j);
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (str[i][j] == '.') {
        cout << "Not unique" << endl;
        return 0;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    str[i][m + 1] = 0;
    printf("%s\n", str[i] + 1);
  }
  return 0;
}
