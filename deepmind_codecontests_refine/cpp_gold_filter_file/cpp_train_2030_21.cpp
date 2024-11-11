#include <bits/stdc++.h>
int vc[1002], v[100001];
int main() {
  int n, m, i, pp, nr, k, j;
  scanf("%d%d", &n, &m);
  pp = 0;
  for (i = 1; i <= n && pp == 0; i++) {
    scanf("%d", &nr);
    nr = nr % m;
    k = 0;
    for (j = 1; j <= m; j++)
      if (vc[j] != 0) {
        k++;
        v[k] = (nr + j) % m;
      }
    for (j = 1; j <= k; j++) vc[v[j]] = 1;
    vc[nr] = 1;
    if (vc[0] == 1) pp = 1;
  }
  if (pp == 1)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
