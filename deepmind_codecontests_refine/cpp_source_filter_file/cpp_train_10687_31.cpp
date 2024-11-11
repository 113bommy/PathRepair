#include <bits/stdc++.h>
int main() {
  long int n, k, i;
  scanf("%lli%lli", &n, &k);
  for (i = 0; i < k; i++) {
    if (n % 10 == 0 && n != 0)
      n = n / 10;
    else
      n--;
  }
  printf("%lli", n);
  return 0;
}
