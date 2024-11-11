#include <bits/stdc++.h>
int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  long long modfac = 1;
  int count = 0;
  while (count < n) {
    modfac *= 2;
    if (modfac > m) {
      printf("%d\n", m);
      return 0;
    }
    count += 1;
  }
  if (n >= m) {
    printf("%d\n", m);
    return 0;
  }
  printf("%lld\n", m % modfac);
}
