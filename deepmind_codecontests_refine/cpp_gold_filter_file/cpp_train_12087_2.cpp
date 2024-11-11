#include <bits/stdc++.h>
int main() {
  long long a[1000000], n, f = 0, i;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (i = 0; i < n; i++) {
    if (a[i] == 1) {
      f = 1;
      break;
    }
  }
  if (f == 1) {
    printf("HARD");
  } else {
    printf("EASY");
  }
  return 0;
}
