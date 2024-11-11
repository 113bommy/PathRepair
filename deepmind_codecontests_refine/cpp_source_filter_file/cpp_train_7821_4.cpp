#include <bits/stdc++.h>
int main() {
  long long n, sum = 0;
  scanf("%d", &n);
  int chocolates[200000];
  for (int i = 0; i < n; i++) scanf("%d", &chocolates[i]);
  long long menor = chocolates[n - 1] + 1;
  long long i = n - 1;
  while (i != -1) {
    if (chocolates[i] < menor) {
      menor = chocolates[i];
      sum += chocolates[i];
    } else {
      menor--;
      if (menor < 0) menor = 0;
      sum += menor;
    }
    i--;
  }
  printf("%d\n", sum);
}
