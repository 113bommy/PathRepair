#include <bits/stdc++.h>
int N, R;
int c[1 << 19];
int main() {
  scanf("%d%d", &N, &R);
  int c_sum = 0;
  for (int i = 0; i < (1 << N); i++) {
    scanf("%d", &c[i]);
    c_sum += c[i];
  }
  printf("%.10f\n", (double)c_sum / (1 << N));
  for (int i = 0; i < R; i++) {
    int z, g;
    scanf("%d%d", &z, &g);
    c_sum -= c[z];
    c_sum += g;
    c[z] = g;
    printf("%.10f\n", (double)c_sum / (1 << N));
  }
  return 0;
}
