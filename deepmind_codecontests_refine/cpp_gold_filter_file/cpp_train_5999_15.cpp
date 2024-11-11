#include <bits/stdc++.h>
int main() {
  int k, i, a, m = 0;
  scanf("%d", &k);
  for (i = 0; i < k; i++) {
    scanf("%d", &a);
    if (a > m) {
      m = a;
    }
  }
  if (m < 25) {
    printf("0");
  }
  if (m >= 25) {
    printf("%d", m - 25);
  }
}
