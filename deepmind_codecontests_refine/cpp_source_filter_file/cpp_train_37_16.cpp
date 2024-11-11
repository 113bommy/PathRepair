#include <bits/stdc++.h>
const int MAXN = 1000005;
const int MAXL = 5000005;
const int MAXLOGN = 21;
int n, r, c;
int totl;
char str[MAXL];
int id[MAXL];
int pos[MAXN];
int next[MAXN];
int goright[MAXLOGN][MAXN];
void init() {
  scanf("%d%d%d\n", &n, &r, &c);
  ++c;
  fgets(str, MAXL, stdin);
  int now = 0;
  for (int i = 0; i < n; ++i) {
    pos[i] = now;
    while (true) {
      id[now] = i;
      ++now;
      if (str[now - 1] == ' ' || str[now - 1] == '\n') break;
    }
  }
  totl = now;
  id[totl] = n;
  pos[n] = totl;
}
void solve() {
  for (int i = 0; i < n; ++i) {
    int nx = pos[i] + c;
    if (nx > totl) nx = totl;
    next[i] = id[nx];
  }
  next[n] = n;
  for (int i = 0; i < n; ++i) goright[0][i] = next[i];
  for (int i = 1; i < MAXLOGN; ++i)
    for (int j = 0; j <= n; ++j)
      goright[i][j] = goright[i - 1][goright[i - 1][j]];
  int ans = -1;
  int ansp;
  for (int i = 0; i < n; ++i) {
    int xx = i;
    for (int j = 0; j < MAXLOGN; ++j)
      if ((r >> j) & 1) xx = goright[j][xx];
    if (xx - i > ans) {
      ans = xx - i;
      ansp = i;
    }
  }
  for (int i = 0, x = ansp; i < r; ++i) {
    int y = next[x];
    if (x == y) break;
    printf("%.*s\n", pos[y] - pos[x] - 1, str + pos[x]);
    x = y;
  }
}
int main() {
  init();
  solve();
  return 0;
}
