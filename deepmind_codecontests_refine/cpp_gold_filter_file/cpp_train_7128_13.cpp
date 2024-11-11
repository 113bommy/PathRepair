#include <bits/stdc++.h>
const int maxn = 2000 + 10;
char pic[maxn][maxn];
int n, m;
int cnt;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
bool judge(int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m && pic[r][c] == '.';
}
void dfs(int r, int c) {
  if (!judge(r, c)) return;
  int dir, sum = 0;
  for (int i = 0; i < 4; ++i) {
    int tr = r + dr[i];
    int tc = c + dc[i];
    if (judge(tr, tc)) {
      sum++;
      dir = i;
    }
  }
  if (sum == 1) {
    switch (dir) {
      case 0:
        pic[r][c] = 'v';
        pic[r - 1][c] = '^';
        break;
      case 1:
        pic[r][c] = '<';
        pic[r][c + 1] = '>';
        break;
      case 2:
        pic[r][c] = '^';
        pic[r + 1][c] = 'v';
        break;
      case 3:
        pic[r][c] = '>';
        pic[r][c - 1] = '<';
        break;
    }
    cnt += 2;
    for (int i = 0; i < 4; ++i) {
      int tr = r + dr[dir] + dr[i];
      int tc = c + dc[dir] + dc[i];
      if (judge(tr, tc)) dfs(tr, tc);
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%s", pic[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (pic[i][j] == '*') cnt++;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) dfs(i, j);
  if (cnt == n * m)
    for (int i = 0; i < n; ++i) printf("%s\n", pic[i]);
  else
    puts("Not unique");
  return 0;
}
