#include <bits/stdc++.h>
int main() {
  int n, l[100002];
  scanf("%d", &n);
  long long int sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &l[i]);
    sum = sum + l[i];
  }
  std::sort(l + 1, l + n + 1);
  sum -= l[n];
  if (sum <= l[n])
    printf("%lld", l[n] + 1 - sum);
  else
    putchar('0');
  return 0;
}
