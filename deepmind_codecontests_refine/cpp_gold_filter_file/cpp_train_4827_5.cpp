#include <bits/stdc++.h>
int main() {
  long i, N;
  double p, incr = 0.0, res = 0.0;
  scanf("%ld\n", &N);
  for (i = 0; i < N; i++) {
    scanf("%lf ", &p);
    res += p * (2.0 * incr + 1.0);
    incr = p * (incr + 1.0);
  }
  printf("%.14lf\n", res);
  return 0;
}
