#include <bits/stdc++.h>
using namespace std;
long long int k, b, n, t;
int main(void) {
  scanf("%I64d %I64d %I64d %I64d", &k, &b, &n, &t);
  if (k == 1) {
    printf("%I64d\n", max((long long int)0,
                          (long long int)ceil(1.0 * (1 + b * n - t) / b)));
    return 0;
  }
  long long int resp = 1;
  int i;
  for (i = 0; i <= n; i++) {
    if (resp * (k + b - 1) > k * t + b - 1) {
      break;
    }
    resp *= k;
  }
  i--;
  printf("%d\n", n - i);
  return 0;
}
