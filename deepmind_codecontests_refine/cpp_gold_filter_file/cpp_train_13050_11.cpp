#include <bits/stdc++.h>
using namespace std;
int n, i, c[50000], j, a[1000][1000], l[10000], r[50000], k, q, e, ee;
int main() {
  scanf(
      "%d"
      "\n",
      &n);
  for (i = 1; i <= n; i++) scanf("%d", &c[i]);
  scanf("\n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= c[i]; j++) scanf("%d", &a[i][j]);
    scanf("\n");
  }
  for (i = 1; i <= 55; i++)
    for (j = 1; j <= 55; j++)
      if (a[i][j] != 0) {
        q++;
        if (a[i][j] != q)
          for (e = 1; e <= 55; e++)
            for (ee = 1; ee <= 55; ee++)
              if (a[e][ee] == q) {
                l[++k] = i;
                r[k] = j;
                l[++k] = e;
                r[k] = ee;
                swap(a[i][j], a[e][ee]);
              }
      }
  printf(
      "%d"
      "\n",
      k / 2);
  for (i = 1; i <= k; i += 2)
    printf(
        "%d"
        " "
        "%d"
        " "
        "%d"
        " "
        "%d"
        "\n",
        l[i], r[i], l[i + 1], r[i + 1]);
  return 0;
}
