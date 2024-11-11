#include <bits/stdc++.h>
int main() {
  int n, r, z, g;
  scanf("%d%d", &n, &r);
  double n2 = 1 << n, m = 0.0;
  int C[1 << n];
  int i = 0;
  while (i < 1 << n) {
    scanf("%d", &C[i]);
    m += C[i++] / n2;
  }
  printf("%.7f\n", m);
  while (r-- > 0) {
    scanf("%d%d", &z, &g);
    m -= (C[z] - g) / n2;
    C[z] = g;
    printf("%.7f\n", m);
  }
  return 0;
}
