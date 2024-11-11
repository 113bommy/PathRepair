#include <bits/stdc++.h>
int N, i;
long long x, y, sum_x, sum_y, sq_x, sq_y;
int main() {
  scanf("%d", &N);
  sq_x = 0;
  sq_y = 0;
  sum_x = 0;
  sum_y = 0;
  for (i = 0; i < N; i++) {
    scanf("%lld %lld", &x, &y);
    sq_x += x * x;
    sq_y += y * y;
    sum_x += x;
    sum_y += y;
  }
  printf("%lld\n", N * sq_x + N * sq_y - sum_x * sum_x - sum_y * sum_y);
  return 0;
}
