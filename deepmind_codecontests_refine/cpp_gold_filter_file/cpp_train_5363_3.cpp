#include <bits/stdc++.h>
using namespace std;
string abc;
int main() {
  long long int tcase, n, m, i, j, k, ans, temp;
  long long int a, b, c, d, h, w;
  scanf("%lld", &n);
  scanf("%lld", &a);
  scanf("%lld", &b);
  cin >> abc;
  c = n / a + 1;
  d = n / b + 1;
  long long int p, q;
  k = 0;
  for (i = 0; i < c; ++i) {
    for (j = 0; j < d; ++j) {
      if ((i * a + j * b) == n) {
        k = 1;
        break;
      }
    }
    if (k == 1) break;
  }
  if (k == 1) {
    printf("%lld\n", i + j);
    p = 0;
    for (long long int ii = 1; ii <= i; ++ii) {
      for (long long int jj = p; jj < p + a; ++jj) {
        printf("%c", abc[jj]);
      }
      p = p + a;
      printf("\n");
    }
    for (long long int ii = 1; ii <= j; ++ii) {
      for (long long int jj = p; jj < p + b; ++jj) {
        printf("%c", abc[jj]);
      }
      p = p + b;
      printf("\n");
    }
  } else {
    printf("-1\n");
  }
  return 0;
}
