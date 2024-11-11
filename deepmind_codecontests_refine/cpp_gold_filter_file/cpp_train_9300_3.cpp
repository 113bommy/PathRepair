#include <bits/stdc++.h>
int main() {
  long long int n, a[3][3], a1[3][3], r[3][3], r1[3][3], s, i, j, k,
      p = 1000000007, sum = 0;
  scanf("%lld", &n);
  a[0][0] = 10;
  a[0][1] = 3;
  a[1][0] = 0;
  a[1][1] = 0;
  r[0][0] = 6;
  r[0][1] = 1;
  r[1][0] = -8;
  r[1][1] = 0;
  s = n - 2;
  if (n == 0)
    printf("1\n");
  else if (n == 1)
    printf("3\n");
  else {
    while (s > 0) {
      sum = 0;
      if (s % 2 != 0) {
        for (i = 0; i < 2; i++) {
          for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
              sum = (sum + (a[i][k] * r[k][j] + p) % p) % p;
            }
            a1[i][j] = sum % p;
            sum = 0;
          }
        }
        for (i = 0; i < 2; i++) {
          for (j = 0; j < 2; j++) {
            a[i][j] = a1[i][j];
          }
        }
      }
      sum = 0;
      s = s / 2;
      for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
          for (k = 0; k < 2; k++) {
            sum = (sum + (r[i][k] * r[k][j] + p) % p) % p;
          }
          r1[i][j] = sum % p;
          sum = 0;
        }
      }
      for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
          r[i][j] = r1[i][j];
        }
      }
    }
    printf("%lld\n", a[0][0] % p);
  }
  return 0;
}
