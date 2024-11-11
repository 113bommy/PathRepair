#include <bits/stdc++.h>
int main() {
  int n, r, z, g;
  scanf("%d%d", &n, &r);
  float n2 = 1 << n, m = 0.0f;
  int C[1 << n];
  int i = 0;
  while (i < 1 << n) {
    scanf("%d", &C[i]);
    m += C[i++] / n2;
  }
  printf("%.6f\n", m);
  while (r-- > 0) {
    scanf("%d%d", &z, &g);
    m -= (C[z] - g) / n2;
    C[z] = g;
    printf("%.6f\n", m);
  }
  return 0;
}
