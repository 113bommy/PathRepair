#include <bits/stdc++.h>
using namespace std;
long long a[1010];
int main() {
  long long n, k, p;
  int q;
  scanf("%I64d%I64d%d", &n, &k, &q);
  p = n - k;
  for (int i = 0; i < q; i++) scanf("%I64d", a + i);
  if (k == 0) {
    for (int i = 0; i < q; i++) printf(".");
    return 0;
  }
  for (int i = 0; i < q; i++) {
    if (n % 2 == 0) {
      if (k <= p) {
        if (a[i] <= n - 2 * k)
          printf(".");
        else if (a[i] % 2 == 1)
          printf(".");
        else
          printf("X");
      } else {
        if (a[i] > 2 * p)
          printf("X");
        else if (a[i] % 2 == 1)
          printf(".");
        else
          printf("X");
      }
    } else {
      if (p < k) {
        if (a[i] <= 2 * p) {
          if (a[i] % 2 == 1)
            printf(".");
          else
            printf("X");
        } else
          printf("X");
      } else {
        if (a[i] == n)
          printf("X");
        else if (a[i] <= p - k + 1)
          printf(".");
        else if (a[i] % 2 == 1)
          printf(".");
        else
          printf("X");
      }
    }
  }
  return 0;
}
