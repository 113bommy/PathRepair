#include <bits/stdc++.h>
using namespace std;
long long x, n, m;
int q, i;
int main() {
  scanf("%I64d%I64d%d", &n, &m, &q);
  for (i = 1; i <= q; i++) {
    scanf("%I64d", &x);
    if (n % 2 == 0) {
      if ((x % 2 == 0) && ((n - x) / 2 + 1 <= m))
        printf("X");
      else if ((x % 2 == 1) && ((n - x) / 2 + 1 + n / 2 <= m))
        printf("X");
      else
        printf(".");
    } else {
      if ((x == n) && (m))
        printf("X");
      else if ((x % 2 == 0) && ((n - x) / 2 + 2 <= m))
        printf("X");
      else if ((x % 2 == 1) && ((n - x) / 2 + 2 + n / 2 <= m))
        printf("X");
      else
        printf(".");
    }
  }
}
