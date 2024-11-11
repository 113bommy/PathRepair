#include <bits/stdc++.h>
using namespace std;
struct cd {
  int nr, l[50 * 50 + 4], c[50 * 50 + 4];
};
cd r;
cd v[50 * 50 + 1];
int lin[] = {0, 0, 1, -1};
int col[] = {1, -1, 0, 0};
int a[54][54], i, n, sf, penal, k, m, in, j;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  r.nr = 1;
  r.l[1] = 1;
  r.c[1] = 1;
  in = sf = 1;
  v[in] = r;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) a[i][j] = 1;
  a[1][1] = 0;
  penal = 1;
  while (in <= sf && sf < k) {
    for (i = 0; i < 4 && sf < k; i++) {
      if (a[v[in].l[v[in].nr] + lin[i]][v[in].c[v[in].nr] + col[i]] == 1) {
        a[v[in].l[v[in].nr] + lin[i]][v[in].c[v[in].nr] + col[i]] = 0;
        r = v[in];
        r.nr++;
        penal += r.nr;
        r.l[r.nr] = v[in].l[v[in].nr] + lin[i];
        r.c[r.nr] = v[in].c[v[in].nr] + col[i];
        sf++;
        v[sf] = r;
      }
    }
    in++;
  }
  printf("%d\n", penal);
  for (i = sf; i >= 1; i--) {
    for (k = 1; k <= v[i].nr; k++) {
      printf("(%d,%d) ", v[i].l[k], v[i].c[k]);
    }
    printf("\n");
  }
  return 0;
}
