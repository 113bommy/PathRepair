#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
int s[2][2][N][N];
void up(int p, int q, int x, int y, int z) {
  for (int i = x; i <= n; i += i & -i)
    for (int j = y; j <= n; j += j & -j) s[p][q][i][j] ^= z;
}
void up(int p, int q, int x0, int y0, int x1, int y1, int z) {
  up(p, q, x0, y0, z);
  int pp = x1 - x0 + 1 & 1, qq = y1 - y0 + 1 & 1;
  if (pp)
    up(p ^ 1, q, x1 + 1, y0, z);
  else
    up(p, q, x1 + 1, y0, z);
  if (qq)
    up(p, q ^ 1, x0, y1 + 1, z);
  else
    up(p, q, x0, y1 + 1, z);
  if (pp && qq) up(p ^ 1, q ^ 1, x1 + 1, y1 + 1, z);
  if (!pp && !qq) up(p, q, x1 + 1, y1 + 1, z);
  if (pp && !qq) up(p ^ 1, q, x1 + 1, y1 + 1, z);
  if (!pp && qq) up(p, q ^ 1, x1 + 1, y1 + 1, z);
}
int ask2(int p, int q, int x, int y) {
  int ret = 0;
  for (int i = x; i; i -= i & -i)
    for (int j = y; j; j -= j & -j) ret ^= s[p][q][x][y];
  return ret;
}
int ask(int x0, int y0, int x1, int y1) {
  int ret = 0;
  ret ^= ask2(x1 & 1, y1 & 1, x1, y1);
  ret ^= ask2(x0 - 1 & 1, y1 & 1, x0 - 1, y1);
  ret ^= ask2(x1 & 1, y0 - 1 & 1, x1, y0 - 1);
  ret ^= ask2(x0 - 1 & 1, y0 - 1 & 1, x0 - 1, y0 - 1);
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  ++n;
  for (int i = 1; i <= m; ++i) {
    int q, x0, y0, x1, y1, w;
    scanf("%d%d%d%d%d", &q, &x0, &y0, &x1, &y1);
    ++x0, ++y0, ++x1, ++y1;
    if (q == 2) {
      scanf("%d", &w);
      up(x0 & 1, y0 & 1, x0, y0, x1, y1, w);
    } else {
      int ans = ask(x0, y0, x1, y1);
      printf("%d\n", ans);
    }
  }
  return 0;
}
