#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, p, r, i, x = 1, y = 2, s;
  double w, wp;
  scanf("%I64d %I64d", &n, &k);
  s = k - n / 2 + 1;
  if (s <= 0)
    printf("-1");
  else if (n == 1 && k != 0)
    printf("-1");
  else if (n == 1 && k == 0)
    printf("1");
  else {
    p--;
    printf("%I64d %I64d ", s, s * 2);
    for (i = 1; i <= n / 2;) {
      if (x != s && y != s * 2 && x != s * 2 && y != s) {
        printf("%I64d %I64d", x, y);
        if (i < n / 2) printf(" ");
        i++;
      }
      x += 2;
      y += 2;
    }
    if (n % 2 == 1) printf("%I64d", 1e9 - 1);
  }
  return 0;
}
