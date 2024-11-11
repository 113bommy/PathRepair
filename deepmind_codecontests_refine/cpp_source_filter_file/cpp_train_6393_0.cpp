#include <bits/stdc++.h>
unsigned long long int calc_rem(unsigned long long int x,
                                unsigned long long int n) {
  unsigned long long int tmp = 0;
  if (n == 1) return x;
  tmp = calc_rem(x, n / 2) % 1000000007;
  tmp = (tmp * tmp) % 1000000007;
  if (n % 2) {
    tmp = (tmp * x) % 1000000007;
  }
  return tmp;
}
unsigned long long int count_gcd_pow(unsigned long long int *arr,
                                     long long int *n, unsigned long long int x,
                                     unsigned long long int down_pow) {
  unsigned long long int zeros = 0, min_pow = 0, tmp = 0, tmp_pow = 0;
  long long int i = 0;
  while ((*n >= 0) && (arr[(*n) - 1] == 0)) {
    zeros++;
    (*n)--;
  }
  tmp_pow = 0;
  if (zeros) {
    tmp = zeros;
    while ((tmp % x) == 0) {
      tmp = tmp / x;
      tmp_pow++;
    }
    if (tmp_pow > 0) {
      min_pow = (unsigned long long int)-1;
      for (i = ((*n) - 1); i >= 0; i--) {
        if (arr[i] < min_pow) min_pow = arr[i];
      }
      if (tmp_pow > min_pow) tmp_pow = min_pow;
      if (tmp_pow > down_pow) tmp_pow = down_pow;
      if (tmp_pow > 0) {
        tmp = 1;
        for (i = 0; i < tmp_pow; i++) tmp = tmp * x;
        zeros -= tmp;
        for (i = ((*n) - 1); i >= 0; i--) arr[i] -= tmp_pow;
        (*n) += zeros;
      }
    }
  }
  return tmp_pow;
}
int main(int argc, char **argv) {
  long long int n = 0;
  unsigned long long int x = 0;
  scanf("%I64d %I64u", &n, &x);
  unsigned long long int *arr = new unsigned long long int[n];
  long long i = 0;
  for (i = 0; i < n; i++) scanf("%I64u", &(arr[i]));
  unsigned long long int sum = 0, zero_sum = 0, k = 0, k_old = 0, min_pow = 0,
                         ans = 0, down_pow = 0, tmp = 0, tmp1 = 0;
  down_pow = arr[n - 1];
  arr[n - 1] = 0;
  for (i = (n - 2); i >= 0; i--) {
    sum += arr[i];
    arr[i] = down_pow - arr[i];
  }
  tmp = count_gcd_pow(arr, &n, x, down_pow);
  while (tmp) {
    sum += tmp;
    down_pow -= tmp;
    tmp = count_gcd_pow(arr, &n, x, down_pow);
  }
  ans = 1;
  if (sum >= 1) ans = calc_rem(x, sum);
  printf("%I64u", ans);
  delete[] arr;
}
