#include <bits/stdc++.h>
int main() {
  int i, n;
  scanf("%d", &n);
  for (i = n; i > 0; i--) {
    if (n % i == 0) {
      printf("%d ", i);
      n = i;
    }
  }
}
