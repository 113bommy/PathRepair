#include <bits/stdc++.h>
int n, m;
int a[52][52];
int use[52][52];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
inline int flood(int c, int i, int j, int pi, int pj, int cnt) {
  use[i][j] = 1;
  for (int k = 0; k < 4; ++k)
    if (0 <= i + dx[k] && i + dx[k] < n && 0 <= j + dy[k] && j + dy[k] < m)
      if (c == a[i + dx[k]][j + dy[k]]) {
        if (use[i + dx[k]][j + dy[k]]) {
          if (cnt >= 4 && (i + dx[k] != pi || j + dy[k] != pj)) return 1;
        } else {
          int ok = flood(c, i + dx[k], j + dy[k], i, j, cnt + 1);
          if (ok) return 1;
        }
      }
  return 0;
}
int main() {
  scanf("%d %d\n", &n, &m);
  char ch;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%c", &ch);
      a[i][j] = ch - 'A';
    }
    scanf("%c", &ch);
  }
  memset(use, 0, sizeof(use));
  int sol = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      if (!use[i][j]) {
        sol = flood(a[i][j], i, j, -1, -1, 0);
        if (sol) break;
      }
    if (sol) break;
  }
  if (sol)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
