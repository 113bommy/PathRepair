#include <bits/stdc++.h>
using namespace std;
char st[100005][2][55];
int n, f[100005][2], p[100005], len[100005][2];
bool cmp(int x, int u, int y, int v) {
  int i, lon = min(len[x][u], len[y][v]);
  for (i = 0; i < lon; i++)
    if (st[x][u][i] != st[y][v][i]) break;
  return st[x][u][i] > st[y][v][i];
}
int main() {
  int i;
  char ch;
  scanf("%d\n", &n);
  for (i = 1; i <= n; i++) {
    len[i][0] = len[i][1] = -1;
    while ((ch = getchar()) || 1) {
      if (ch == ' ' || ch == '\n' || ch == '\r') break;
      st[i][0][++len[i][0]] = ch;
    }
    while ((ch = getchar()) || 1) {
      if (ch == ' ' || ch == '\n' || ch == '\r') break;
      st[i][1][++len[i][1]] = ch;
    }
  }
  for (i = 1; i <= n; i++) scanf("%d", &p[i]);
  f[1][0] = f[1][1] = 1;
  for (i = 2; i <= n; i++) {
    if (cmp(p[i], 0, p[i - 1], 0)) f[i][0] |= f[i - 1][0];
    if (cmp(p[i], 0, p[i - 1], 1)) f[i][0] |= f[i - 1][1];
    if (cmp(p[i], 1, p[i - 1], 0)) f[i][1] |= f[i - 1][0];
    if (cmp(p[i], 1, p[i - 1], 1)) f[i][1] |= f[i - 1][1];
  }
  if (f[n][0] || f[n][1])
    printf("YES");
  else
    printf("NO");
  return 0;
}
