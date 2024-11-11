#include <bits/stdc++.h>
using namespace std;
struct st {
  int v, t;
} w[10002];
int a[103][103], n, m;
int main() {
  int q, i, j, t, cn = 0, x, y, v, k, g, ng, ww;
  bool ck = 0;
  memset(a, 0, sizeof a);
  scanf("%d%d%d", &n, &m, &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &t);
    if (t == 3) {
      ck = 1;
      scanf("%d%d%d", &x, &y, &v);
      a[x][y] = v;
    } else {
      w[cn].t = t;
      scanf("%d", &w[cn].v);
      if (ck) {
        if (t == 1) {
          k = n;
          ng = a[w[cn].v][k];
          ww = a[w[cn].v][1];
          while (k > 1) {
            g = a[w[cn].v][k - 1];
            a[w[cn].v][k - 1] = ng;
            ng = g;
            k--;
          }
          a[w[cn].v][n] = ww;
        } else {
          k = m;
          ng = a[k][w[cn].v];
          ww = a[1][w[cn].v];
          while (k > 1) {
            g = a[k - 1][w[cn].v];
            a[k - 1][w[cn].v] = ng;
            ng = g;
            k--;
          }
          a[m][w[cn].v] = ww;
        }
      }
      cn++;
    }
  }
  if (ck) {
    for (i = cn - 1; i >= 0; i--) {
      if (w[i].t == 1) {
        k = n;
        g = a[w[i].v][k];
        while (k > 1) {
          a[w[i].v][k] = a[w[i].v][k - 1];
          k--;
        }
        a[w[i].v][1] = g;
      } else {
        k = m;
        g = a[k][w[i].v];
        while (k > 1) {
          a[k][w[i].v] = a[k - 1][w[i].v];
          k--;
        }
        a[1][w[i].v] = g;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (j > 1) printf(" ");
      printf("%d", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
