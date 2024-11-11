#include <bits/stdc++.h>
using namespace std;
int h[302][302], lft[302][302], rgt[302][302], up[302][302], down[302][302];
int Tp, Tu, Td;
inline int spent(int s, int t) { return (t == s ? Tp : (t > s ? Tu : Td)); }
int main(void) {
  int N, M, T, i, j, i2, j2, x1, y1, x2, y2, ans, d;
  bool done = false;
  scanf("%d %d %d", &N, &M, &T);
  scanf("%d %d %d", &Tp, &Tu, &Td);
  for (i = 1; i <= N; i++)
    for (j = 1; j <= M; j++) {
      scanf("%d", &h[i][j]);
      if (i > 1)
        down[i][j] = (down[i - 1][j] + spent(h[i - 1][j], h[i][j]));
      else
        down[i][j] = 0;
      if (j > 1)
        rgt[i][j] = (rgt[i][j - 1] + spent(h[i][j - 1], h[i][j]));
      else
        rgt[i][j] = 0;
    }
  for (i = N; i > 0; i--)
    for (j = M; j > 0; j--) {
      if (i < N)
        up[i][j] = (up[i + 1][j] + spent(h[i + 1][j], h[i][j]));
      else
        up[i][j] = 0;
      if (j < M)
        lft[i][j] = (lft[i][j + 1] + spent(h[i][j + 1], h[i][j]));
      else
        lft[i][j] = 0;
    }
  ans = 0x7fffffff;
  for (i = 1; i < N && !done; i++)
    for (i2 = i + 1; i2 <= N && !done; i2++)
      for (j = 1; j < M && !done; j++)
        for (j2 = j + 1; j2 <= M && !done; j2++) {
          d = (rgt[i][j2] - rgt[i][j]) + (down[i2][j2] - down[i][j2]);
          d += (lft[i2][j] - lft[i2][j2]) + (up[i][j] - up[i2][j]);
          d = abs(d - T);
          if (d < ans) {
            x1 = j;
            y1 = i;
            x2 = j2;
            y2 = i2;
            done = ((ans = d) == 0);
          }
        }
  printf("%d %d %d %d\n", y1, x1, y2, x2);
  return 0;
}
