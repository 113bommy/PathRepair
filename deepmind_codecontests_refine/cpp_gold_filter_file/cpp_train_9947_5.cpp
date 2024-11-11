#include <bits/stdc++.h>
long long a, b, n, i, e = 0;
int main() {
  scanf("%lld %lld %lld", &a, &b, &n);
  if (a + b <= n) {
    if ((n - a) % b == 0 || (n - a) % b == 1)
      printf("YES");
    else
      printf("NO");
  } else {
    if (a == n)
      printf("YES");
    else
      printf("NO");
  }
  return 0;
}
