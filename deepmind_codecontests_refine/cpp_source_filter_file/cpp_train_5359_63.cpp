#include <bits/stdc++.h>
int hcf(int a, int b) {
  if (b == 0) return a;
  return (b, a % b);
}
int b[110];
int g[110];
int main() {
  int n, m, i, j;
  scanf("%d%d", &n, &m);
  memset(b, 0, sizeof(b));
  memset(g, 0, sizeof(g));
  int nb, sb, temp, ng, sg;
  scanf("%d", &nb);
  sb = n - nb;
  while (nb--) {
    scanf("%d", &temp);
    b[temp] = 1;
  }
  scanf("%d", &ng);
  sg = m - ng;
  while (ng--) {
    scanf("%d", &temp);
    g[temp] = 1;
  }
  for (i = 0; i < n * m; i++) {
    int man = i % n;
    int wom = i % m;
    if (b[man] == 0 && g[wom] == 1) {
      b[man] = 1;
      sb--;
    } else if (b[man] == 1 && g[wom] == 0) {
      g[wom] = 1;
      sg--;
    }
    if ((sg + sb) == 0) {
      printf("Yes");
      break;
    }
  }
  if (i == n * m) {
    printf("No");
  }
  return 0;
}
