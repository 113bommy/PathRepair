#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, m1, m2;
struct SAT {
  bitset<N> e[N];
  int c[N], flg;
  void color(int x) {
    if (c[x] != -1) return;
    c[x] = 1;
    c[x ^ 1] = 0;
    for (int i = (int)(0); i <= (int)(2 * n - 1); i++)
      if (e[x][i]) color(i);
  }
  void init(int m) {
    for (int i = (int)(1); i <= (int)(m); i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      x = (x > 0 ? x * 2 - 2 : -x * 2 - 1);
      y = (y > 0 ? y * 2 - 2 : -y * 2 - 1);
      e[x][y ^ 1] = e[y][x ^ 1] = 1;
    }
    for (int i = (int)(0); i <= (int)(2 * n - 1); i++) e[i][i] = 1;
    for (int k = (int)(0); k <= (int)(2 * n - 1); k++)
      for (int i = (int)(0); i <= (int)(2 * n - 1); i++)
        if (e[i][k]) e[i] |= e[k];
    for (int i = (int)(0); i <= (int)(2 * n - 1); i++)
      if (e[i][i ^ 1] && e[i ^ 1][i]) flg = 1;
    if (!flg) {
      for (int i = (int)(0); i <= (int)(2 * n - 1); i++) c[i] = -1;
      for (int i = (int)(0); i <= (int)(2 * n - 1); i++)
        if (e[i][i ^ 1]) color(i ^ 1);
    }
  }
  void solve(int c1 = -1, int c2 = -1) {
    if (c1 != -1) color(c1);
    if (c2 != -1) color(c2);
    for (int i = (int)(0); i <= (int)(2 * n - 1); i++)
      if (c[i] == -1) color(i);
    for (int i = (int)(0); i <= (int)(n - 1); i++)
      printf("%c ", '1' ^ (c[i * 2]));
    exit(0);
  }
} f, g;
void check(SAT &f, SAT &g) {
  if (f.flg) return;
  if (g.flg) return f.solve();
  for (int i = (int)(0); i <= (int)(2 * n - 1); i++)
    if (f.c[i] && !g.c[i]) return f.solve(i);
  for (int i = (int)(0); i <= (int)(2 * n - 1); i++)
    if (f.c[i] == -1)
      for (int j = (int)(i); j <= (int)(2 * n - 1); j++)
        if (f.c[j] == -1)
          if (!f.e[i][j] && g.e[i][j]) return f.solve(i, j ^ 1);
}
int main() {
  scanf("%d%d%d", &n, &m1, &m2);
  f.init(m1);
  g.init(m2);
  check(f, g);
  check(g, f);
  puts("SIMILAR");
}
