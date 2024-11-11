#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int ones = n % 2;
  int twos = n / 2;
  while (twos) {
    if ((ones + twos) % m == 0) {
      printf("%d", ones + twos);
      exit(0);
    }
    twos--;
    ones = ones + 2;
  }
  printf("-1");
}
