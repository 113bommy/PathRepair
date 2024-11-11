#include <bits/stdc++.h>
int main() {
  int a, i = 1;
  scanf("%d", &a);
  while (i <= a) {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    if (n == 1) {
      printf("0\n");
    } else if (n == 2) {
      printf("%lld\n", m);
    } else {
      printf("%lld\n", 2 * m);
    }
    i++;
  }
  return 0;
}
