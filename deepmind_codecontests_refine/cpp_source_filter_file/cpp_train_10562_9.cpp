#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int n, m;
char sa[50], sb[50];
bool used[50][50];
void dfs(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= m || used[x][y] == true) return;
  {
    used[x][y] = true;
    if (sa[x] == '>')
      dfs(x, y + 1);
    else
      dfs(x, y - 1);
    if (sb[y] == '^')
      dfs(x - 1, y);
    else
      dfs(x + 1, y);
  }
}
int main() {
  scanf("%d%d\n", &n, &m);
  gets(sa);
  gets(sb);
  int i, j, i1, j1;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      memset(used, 0, sizeof(used));
      dfs(i, j);
      for (i1 = 0; i1 < n; i1++)
        for (j1 = 0; j1 < m; j1++)
          if (used[i1][j1] == false) {
            puts("NO");
            return 0;
          }
    }
  puts("YES");
  return 0;
}
