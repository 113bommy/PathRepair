#include <bits/stdc++.h>
long long int min(long long int a, long long int b) { return a < b ? a : b; }
int main() {
  int n, i;
  long long int a[300005], x, y;
  long long int sum;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  sum = x = y = 0;
  for (i = 1; i <= n; i++) {
    sum += a[i] / 2;
    if (a[i] % 2 == 1) {
      if (i % 2 == 1)
        x++;
      else
        y++;
    }
  }
  sum += min(x, y);
  printf("%lld\n", sum);
  return 0;
}
