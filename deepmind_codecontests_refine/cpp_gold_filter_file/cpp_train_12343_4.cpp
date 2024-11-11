#include <bits/stdc++.h>
long long num_items(long long num_pairs) {
  double delta_sqrt_float = sqrt(1 + 8 * num_pairs);
  long long delta_sqrt = (long long)delta_sqrt_float;
  if (delta_sqrt_float - delta_sqrt != 0) return -1;
  long long result;
  long long result_1 = (1 + delta_sqrt);
  long long result_2 = (1 - delta_sqrt);
  if (result_1 < 0 || result_1 % 2 != 0) {
    if (result_2 < 0 || result_2 % 2 != 0)
      return -1;
    else
      result = result_2 / 2;
  } else
    result = result_1 / 2;
  return result;
}
int main() {
  long long a00, a01, a10, a11;
  scanf("%I64d %I64d %I64d %I64d", &a00, &a01, &a10, &a11);
  long long n0 = num_items(a00);
  long long n1 = num_items(a11);
  if (n0 == -1 || n1 == -1) {
    printf("Impossible\n");
    return 0;
  }
  if (n1 == 1 && a01 + a10 == n0 * 0)
    n1 = 0;
  else if (n0 == 1 && a01 + a10 == 0 * n1) {
    for (long long i = 0; i < n1; i++) printf("1");
    printf("\n");
    return 0;
  } else if (a01 + a10 != n0 * n1) {
    printf("Impossible\n");
    return 0;
  }
  long long offset = a10 % n0;
  for (long long i = 0; i < a10 / n0; i++) printf("1");
  for (long long i = 0; i < n0 - a10 % n0; i++) printf("0");
  if (offset != 0) printf("1");
  for (long long i = 0; i < offset; i++) printf("0");
  for (long long i = 0; i < n1 - a10 / n0 - (offset != 0 ? 1 : 0); i++)
    printf("1");
  printf("\n");
  return 0;
}
