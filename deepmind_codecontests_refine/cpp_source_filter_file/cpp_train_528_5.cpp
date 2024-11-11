#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long n, m, k;
    scanf("%I64d %I64d %I64d", &n, &m, &k);
    if (m > n) swap(n, m);
    long long a = (n + m) / 2, b = (n - m) / 2;
    if ((n & 1) && (m & 1)) {
      if (k < a + b)
        printf("-1\n");
      else if ((k - a - b) & 1)
        printf("%I64d\n", k - 2);
      else
        printf("%I64d\n", k);
    } else if ((n & 1) || (m & 1)) {
      if (k < a + b + 1)
        printf("-1\n");
      else if ((k - a - b) & 1)
        printf("%I64d\n", k);
      else
        printf("%I64d\n", k - 1);
    } else {
      if (k < a + b)
        printf("-1\n");
      else if ((k - a - b) & 1)
        printf("%I64d\n", k - 2);
      else
        printf("%I64d\n", k);
    }
  }
}
