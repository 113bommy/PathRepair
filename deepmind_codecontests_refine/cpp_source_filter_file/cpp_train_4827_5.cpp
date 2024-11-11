#include <bits/stdc++.h>
int main() {
  long i, N;
  float p, incr = 0.0, res = 0.0;
  scanf("%ld\n", &N);
  for (i = 0; i < N; i++) {
    scanf("%f ", &p);
    res += p * (2.0 * incr + 1.0);
    incr = p * (incr + 1.0);
  }
  printf("%.14f\n", res);
  return 0;
}
