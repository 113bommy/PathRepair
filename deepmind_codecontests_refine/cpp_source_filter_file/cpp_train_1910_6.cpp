#include <bits/stdc++.h>
using namespace std;
int nb, nf;
int x[255], y[255], see[1000111];
int nod(int a, int b) { return b == 0 ? a : nod(b, a % b); }
int nodp(int a, int b) { return nod(max(-a, a), max(-b, b)); }
int main() {
  scanf("%d%d", &nb, &nf);
  for (int f = 0; f < nf; f++) scanf("%d%d", x + f, y + f);
  for (int a = 0; a < nf; a++)
    for (int b = a + 1; b < nf; b++)
      if (y[a] != y[b]) {
        if (x[a] == x[b]) {
          if (x[a] <= nb) {
            int tt = 2;
            for (int c = b + 1; c < nf; c++)
              if (x[c] == x[a]) tt++;
            see[x[a]] = max(see[x[a]], tt);
          }
        } else if (y[a] != y[b]) {
          int dy = y[b] - y[a], dx = x[b] - x[a], no = nodp(dy, dx);
          dy /= no;
          dx /= no;
          if (dy < 0) {
            dy = -dy;
            dx = -dx;
          }
          if (y[a] % dy == 0) {
            long long x2 = x[a] - y[a] * 1LL / dy * dx;
            if (x2 > 0 && x2 <= nb) {
              int tt = 2, bi = x2;
              for (int c = b + 1; c < nf; c++) {
                int y3 = y[c], x3 = x[c] - bi, n3 = nodp(y3, x3);
                x3 /= n3;
                y3 /= n3;
                if (y3 < 0) {
                  x3 = -x3;
                  y3 = -y3;
                }
                if (x3 == dx && y3 == dy) tt++;
              }
              see[bi] = max(see[bi], tt);
            }
          }
        }
      }
  int re = 0;
  for (int b = 1; b <= nf; b++) {
    re += max(see[b], 1);
  }
  printf("%d\n", re);
}
