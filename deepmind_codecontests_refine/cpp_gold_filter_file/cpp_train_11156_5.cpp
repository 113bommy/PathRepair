#include <bits/stdc++.h>
using namespace std;
bitset<2001> primos;
bitset<1001> funf;
int main() {
  primos.set();
  for (int i = 2; i <= 2000; i++) {
    int s = sqrt(i);
    for (int j = 2; j <= s; j++)
      if (i % j == 0) primos[i] = false;
  }
  int n;
  scanf("%d", &n);
  int k = n - 1;
  while (++k && !primos[k])
    ;
  printf("%d\n", k);
  for (int i = 1; i <= n; i++) {
    if (i < n)
      printf("%d %d\n", i, i + 1);
    else
      printf("%d 1\n", n, 1);
  }
  for (int i = 1; i <= k - n; i++) {
    printf("%d %d\n", i, i + n / 2);
  }
}
