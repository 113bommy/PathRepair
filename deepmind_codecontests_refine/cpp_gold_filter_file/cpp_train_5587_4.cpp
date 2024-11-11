#include <bits/stdc++.h>
using namespace std;
int n, m, t, tot, ans, b[15], o[15], px[35], py[35];
int qx[35], qy[35], v[35][35];
bool u[8][8];
char s[35];
void dfs(int t) {
  if (t > 7) {
    memset(u, 0, sizeof(u));
    for (int i = 1; i <= 28; i++) {
      int x = b[v[px[i]][py[i]]], y = b[v[qx[i]][qy[i]]];
      if (u[x][y]) return;
      u[x][y] = u[y][x] = 1;
    }
    if (!ans) memcpy(o, b, sizeof(o));
    ans++;
    return;
  }
  int j;
  for (j = 1; j <= 14 && b[j]; j++)
    ;
  b[j] = t;
  for (int k = j + 1; k <= 14; k++)
    if (!b[k]) {
      b[k] = t;
      dfs(t + 1);
      b[k] = 0;
    }
  b[j] = 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++)
      if (s[j] != '.') {
        if (s[j] < 'a')
          t = s[j] - 'A' + 27;
        else
          t = s[j] - 'a' + 1;
        if (!px[t])
          px[t] = i, py[t] = j;
        else
          qx[t] = i, qy[t] = j;
        if (!v[i][j])
          v[i][j] = v[i + 1][j] = v[i][j + 1] = v[i + 1][j + 1] = ++tot;
      }
  }
  dfs(1);
  printf("%d\n", ans * 5040);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (v[i][j])
        s[j] = o[v[i][j]] + '0' - 1;
      else
        s[j] = '.';
    puts(s + 1);
  }
  return 0;
}
