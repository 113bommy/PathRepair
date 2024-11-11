#include <bits/stdc++.h>
int main() {
  long long n, x, a, sum;
  scanf("%lld%lld", &n, &x);
  sum = n - 1;
  while (n > 0) {
    n--;
    scanf("%lld", &a);
    sum = sum + a;
  }
  if (sum == x)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
