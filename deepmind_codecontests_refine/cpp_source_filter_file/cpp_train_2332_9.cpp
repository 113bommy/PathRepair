#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char s[503][503];
bool flag[503][503];
struct opera {
  char c;
  int x, y;
};
opera p[2150003];
bool fl;
int i, j;
void dfs(int y, int x) {
  if (x < 0 || y < 0 || x == m || y == n || flag[y][x] || s[y][x] == '#')
    return;
  flag[y][x] = true;
  p[k].c = 'B';
  p[k].x = x;
  p[k].y = y;
  k++;
  dfs(y - 1, x);
  dfs(y + 1, x);
  dfs(y, x + 1);
  dfs(y, x - 1);
  if (i != y || j != x) {
    p[k].c = 'D';
    p[k].x = x;
    p[k].y = y;
    k++;
    p[k].c = 'R';
    p[k].x = x;
    p[k].y = y;
    k++;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) scanf("%s", s[i]);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (!flag[i][j]) dfs(i, j);
  printf("%d\n", k);
  for (i = 0; i < k; i++) printf("%c %d %d\n", p[i].c, p[i].y + 1, p[i].x + 1);
  return 0;
}
