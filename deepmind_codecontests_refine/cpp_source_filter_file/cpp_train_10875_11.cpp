#include <bits/stdc++.h>
using namespace std;
int i, j, l, u, fg, o, e, n, m, cont = 500000, a = 1000, b, p, k, sol[1000],
                                usa[1000][1000], arr[400][400];
char s[2000];
int main() {
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) scanf("%d", &arr[i][j]);
  scanf("%d%d", &a, &b);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      o = 0;
      if (i + a < n && j + b < m) {
        for (k = i; k < i + a; k++)
          for (l = j; l < j + b; l++) o += arr[k][l];
        cont = min(cont, o);
      }
      o = 0;
      if (i + b < n && j + a < m) {
        for (k = i; k < i + b; k++)
          for (l = j; l < j + a; l++) o += arr[k][l];
        cont = min(cont, o);
      }
    }
  printf("%d", cont);
}
