#include <bits/stdc++.h>
int main() {
  int b[100] = {0}, g[100] = {0}, n, m, hb, hg, i, x, cmt = 0;
  scanf("%d %d", &n, &m);
  scanf("%d", &hb);
  for (i = 0; i < hb; i++) {
    scanf("%d", &x);
    b[x] = 1;
  }
  scanf("%d", &hg);
  for (i = 0; i < hg; i++) {
    scanf("%d", &x);
    g[x] = 1;
  }
  for (i = 0; i < (n * m); i++) {
    if ((b[i % n] == 1) && (g[i % m] == 0)) g[i % m] = 1;
    if ((b[i % n] == 0) && (g[i % m] == 1)) b[i % n] = 1;
  }
  for (i = 0; i < n; i++)
    if (b[i] == 0) cmt++;
  for (i = 0; i < m; i++)
    if (g[i] == 0) cmt++;
  if (cmt == 0)
    printf("Yes");
  else
    printf("No");
  return 0;
}
