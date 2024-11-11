#include <bits/stdc++.h>
int b[10];
bool is(int n) {
  for (; n; n /= 10)
    if (b[n % 10]) return 1;
  return 0;
}
int main() {
  int i, n, j;
  for (scanf("%d", &n), i = n; i; b[i % 10] = 1, i /= 10)
    ;
  for (j = 0, i = 1; i * i < n; i++)
    if (n % i) j += is(i) + is(n / i);
  j += i * i == n && is(i);
  printf("%d\n", j);
  return 0;
}
