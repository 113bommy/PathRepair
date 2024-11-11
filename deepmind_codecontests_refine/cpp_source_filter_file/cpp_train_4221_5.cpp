#include <bits/stdc++.h>
int n, res;
int main() {
  scanf("%d", &n);
  while (n > 7) {
    res += n % 8 == 0;
    n /= 8;
  }
  printf("%d", res + (n == 0));
}
