#include <bits/stdc++.h>
unsigned long long int p[64][2][2], m, pi[64];
void mul_matrix(int size, unsigned long long int (*a)[2],
                unsigned long long int (*b)[2],
                unsigned long long int (*dest)[2]) {
  int i, j, k;
  for (i = 0; i < size; i++)
    for (j = 0; j < 2; j++) {
      dest[i][j] = 0;
      for (k = 0; k < 2; k++)
        dest[i][j] = (dest[i][j] + (a[i][k] * b[k][j]) % m) % m;
    }
}
void init_mat() {
  int i;
  p[0][0][0] = p[0][0][1] = p[0][1][0] = 1;
  p[0][1][1] = 0;
  pi[0] = 2;
  for (i = 1; i < 64; i++) {
    mul_matrix(2, p[i - 1], p[i - 1], p[i]);
    pi[i] = (pi[i - 1] * pi[i - 1]) % m;
  }
}
int main() {
  unsigned long long int n, k, t, zero = 0, one = 1, ans = 1, l, i;
  unsigned long long int base1[1][2] = {0, 1}, base2[1][2] = {1, 0}, dest[1][2];
  scanf("%lld %lld %lld %lld", &n, &k, &l, &m);
  init_mat();
  for (i = 0, t = n - 1; t; t >>= 1, i++) {
    if (t & 1) {
      mul_matrix(1, base1, p[i], dest);
      memcpy(base1, dest, sizeof(dest));
      mul_matrix(1, base2, p[i], dest);
      memcpy(base2, dest, sizeof(dest));
    }
  }
  for (i = 0, t = n; t; t >>= 1, i++)
    if (t & 1) one = (one * pi[i]) % m;
  zero =
      ((base1[0][0] + base1[0][1]) % m + (base2[0][0] + base2[0][1]) % m) % m;
  one = ((one + m) - zero) % m;
  for (t = k, i = 0; i < l; t >>= 1, i++) {
    if (t & 1)
      ans = (ans * one) % m;
    else
      ans = (ans * zero) % m;
  }
  if (t) {
    printf("0");
    return 0;
  }
  printf("%u", ans);
  return 0;
}
