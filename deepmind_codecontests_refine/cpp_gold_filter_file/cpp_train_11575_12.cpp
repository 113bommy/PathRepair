#include <bits/stdc++.h>
using namespace std;
char s[300][300];
int n, m;
const int dr[] = {+0, +1, +0, -1, +1, +1, -1, -1};
const int dc[] = {+1, +0, -1, +0, -1, +1, -1, +1};
int tot;
void dfs(int r, int c) {
  s[r][c] = '2', tot++;
  for (int i = 0; i < 8; i++) {
    int p = r + dr[i];
    int q = c + dc[i];
    if ((p >= 0 && q >= 0 && p < n && q < m) and s[p][q] == '1') dfs(p, q);
  }
}
bool check(int r, int c, int d, int l, int h) {
  for (int i = 0; i <= d; i++) {
    for (int j = l; j < h; j++) {
      int p = r + i * dr[j];
      int q = c + i * dc[j];
      if (!(p >= 0 && q >= 0 && p < n && q < m) or s[p][q] != '2') return 0;
    }
  }
  return 1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    int ans = 0;
    for (int i = 0; i < n; i++) scanf(" %s", s[i]);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1') {
          tot = 0;
          dfs(i, j);
          if (tot % 4 or (tot >> 2) > 250) continue;
          int sz = (tot >> 2);
          ans += (check(i, j, sz, 0, 2) and check(i + sz, j + sz, sz, 2, 4));
          ans += (check(i, j, sz, 4, 6) and check(i + (tot >> 1), j, sz, 6, 8));
        }
      }
    printf("%d\n", ans);
  }
  return 0;
}
