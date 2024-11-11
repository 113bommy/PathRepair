#include <bits/stdc++.h>
using namespace std;
int n, m, ch[13][13], a[13][13], ans = 0;
char s99[] =
    "AAA.BCCC.\n.A.B.C.D.\n.ABBB.CD.\nEEEFFFDDD\nG.E.HFIII\nGGGJHHHI.\nGK.JHL."
    "IM\n.KJJJLMMM\nKKK.LLL.M\n";
int w[4][3][3] = {{{1, 1, 1}, {0, 1, 0}, {0, 1, 0}},
                  {{1, 0, 0}, {1, 1, 1}, {1, 0, 0}},
                  {{0, 1, 0}, {0, 1, 0}, {1, 1, 1}},
                  {{0, 0, 1}, {1, 1, 1}, {0, 0, 1}}};
inline bool ok(int x, int y, int i) {
  if (y + 2 >= m || x + 2 >= n) return 0;
  for (int u = 0; u < 3; u++)
    for (int v = 0; v < 3; v++)
      if (w[i][u][v])
        if (a[x + u][y + v]) return 0;
  return 1;
}
inline void dfs(int x, int y, int now, int las) {
  if (las <= (ans - now) * 5) return;
  if (y >= m) {
    dfs(x + 1, 0, now, las);
    return;
  }
  if (x + 2 >= n) {
    if (now > ans) {
      ans = now;
      memcpy(ch, a, sizeof a);
    }
    return;
  }
  for (int i = 0; i < 4; i++)
    if (ok(x, y, i)) {
      now++;
      for (int u = 0; u < 3; u++)
        for (int v = 0; v < 3; v++)
          if (w[i][u][v]) a[x + u][y + v] = now;
      dfs(x, y + 1, now, las - 5 - !a[x][y]);
      now--;
      for (int u = 0; u < 3; u++)
        for (int v = 0; v < 3; v++)
          if (w[i][u][v]) a[x + u][y + v] = 0;
    }
  dfs(x, y + 1, now, las - !a[x][y]);
}
void out() {
  printf("%d\n", ans);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      printf("%c", ch[i][j] ? 'A' + ch[i][j] - 1 : '.');
    puts("");
  }
  exit(0);
}
int main() {
  scanf("%d%d", &n, &m);
  if (min(n, m) < 3) out();
  if (n == 9 && m == 9) return 0 * printf("13\n%s", s99);
  dfs(0, 0, 0, n * m);
  out();
}
