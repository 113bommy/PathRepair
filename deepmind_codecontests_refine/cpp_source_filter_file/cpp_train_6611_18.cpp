#include <bits/stdc++.h>
int main() {
  int n, f[100001][2], b[100001][2], c[100001], i, m, v, kq;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    f[i][0] = 0;
    b[i][0] = 0;
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &v);
    f[v][0]++;
    f[v][1] = i;
  }
  for (i = 1; i <= m; i++) {
    scanf("%d", &v);
    c[i] = v;
    b[v][0]++;
    b[v][1] = i;
  }
  kq = 1;
  for (i = 1; i <= n; i++) {
    if (f[i][0] == 0 && b[i][0] > 0) {
      kq = 0;
      break;
    }
    if (f[i][0] > 1 && b[i][0] > 0) kq = 2;
  }
  if (kq == 0)
    printf("Impossible");
  else if (kq == 2)
    printf("Ambiguity");
  else {
    printf("Possible\n");
    for (i = 1; i <= n; i++) printf("%d ", f[c[i]][1]);
  }
  return 0;
}
