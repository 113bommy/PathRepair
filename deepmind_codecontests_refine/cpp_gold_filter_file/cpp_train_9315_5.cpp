#include <bits/stdc++.h>
int e1, e2, s1, s2, n, m;
int f = 0;
int c = 2;
char mat[501][501];
int check[501][501] = {};
void dfs(int x, int y) {
  if (c == 1 && x == e1 && y == e2) {
    f = 1;
    return;
  }
  if (x == e1 && y == e2) c -= 1;
  if (mat[x][y] == 'X' && !(x == s1 && y == s2)) return;
  if (check[x][y] == 0) {
    check[x][y] = 1;
    if (x > 0) dfs(x - 1, y);
    if (y > 0) dfs(x, y - 1);
    if (x < n) dfs(x + 1, y);
    if (y < m) dfs(x, y + 1);
  }
  return;
}
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  n--;
  m--;
  for (i = 0; i <= n; i++) scanf("%s", mat[i]);
  scanf("%d%d%d%d", &s1, &s2, &e1, &e2);
  s1--;
  s2--;
  e1--;
  e2--;
  if (mat[e1][e2] == 'X') c -= 1;
  check[s1][s2] = 1;
  if (s1 > 0) dfs(s1 - 1, s2);
  if (s2 > 0) dfs(s1, s2 - 1);
  if (s1 < n) dfs(s1 + 1, s2);
  if (s2 < m) dfs(s1, s2 + 1);
  printf("%s", f == 1 ? "YES" : "NO");
  return 0;
}
