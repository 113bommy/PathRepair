#include <bits/stdc++.h>
int main(void) {
  long long int pos, i, n, dif, p;
  i = 1;
  pos = 0;
  scanf("%lld", &p);
  while (pos < p) {
    pos += i++;
  }
  dif = pos - p + 1;
  printf("%lld\n", i - dif);
  return 0;
}
