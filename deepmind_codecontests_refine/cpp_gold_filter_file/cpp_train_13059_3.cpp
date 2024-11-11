#include <bits/stdc++.h>
using namespace std;
char s[1010][1010];
int col[1010][1010];
int usd[1010][1010];
int can(int i, int j) { return s[i][j] == 'w' && !usd[i][j]; }
int vis[5];
int get1(int i, int j) {
  memset(vis, 0, sizeof(vis));
  vis[col[i][j - 2]] = 1;
  vis[col[i - 1][j]] = 1;
  vis[col[i - 1][j + 1]] = 1;
  vis[col[i - 1][j - 1]] = 1;
  vis[col[i][j + 2]] = 1;
  for (i = 1; vis[i]; i++)
    ;
  return i;
}
int get2(int i, int j) {
  memset(vis, 0, sizeof(vis));
  vis[col[i - 2][j]] = 1;
  vis[col[i - 1][j - 1]] = 1;
  vis[col[i - 1][j + 1]] = 1;
  vis[col[i][j - 1]] = 1;
  vis[col[i][j + 1]] = 1;
  vis[col[i + 1][j - 1]] = 1;
  vis[col[i + 1][j + 1]] = 1;
  for (i = 1; vis[i]; i++)
    ;
  return i;
}
int main() {
  int n, m, i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  int c1 = 0, c2 = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++)
      if (s[i][j] == 'b') {
        c1++;
        if (can(i - 1, j)) {
          if (can(i + 1, j)) {
            k = get2(i, j);
            usd[i - 1][j] = usd[i + 1][j] = 1;
            col[i - 1][j] = col[i][j] = col[i + 1][j] = k;
          } else {
            puts("NO");
            return 0;
          }
        } else {
          if (can(i, j - 1) && can(i, j + 1)) {
            k = get1(i, j);
            usd[i][j - 1] = usd[i][j + 1] = 1;
            col[i][j - 1] = col[i][j] = col[i][j + 1] = k;
          } else {
            puts("NO");
            return 0;
          }
        }
      } else if (s[i][j] == 'w')
        c2++;
  }
  if (c2 != c1 * 2) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++)
      if (s[i][j] == 'b' || s[i][j] == 'w')
        printf("%c", col[i][j] - 1 + 'a');
      else
        printf(".");
    puts("");
  }
}
