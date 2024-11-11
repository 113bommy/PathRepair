#include <bits/stdc++.h>
int main() {
  int n, i, c = 0;
  scanf("%d", &n);
  for (i = 2; i < sqrt(n); i++) {
    if (n % i == 0 && i != n / i) c = c + 2;
  }
  for (i = 2; i <= n / 2; i++) {
    if (i * i == n && n % i == 0) c++;
  }
  c++;
  printf("%d", c);
}
