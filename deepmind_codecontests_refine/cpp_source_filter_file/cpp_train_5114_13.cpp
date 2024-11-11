#include <bits/stdc++.h>
int main() {
  int n = 0, i = 0, it = 0;
  int k = 0;
  scanf("%d", &n);
  int ar[n];
  for (; i < n; i++) {
    scanf("%d", ar + i);
  }
  do {
    if (ar[it] == 0) {
      if ((it >= 1) && (it <= n - 2) && (ar[it - 1] == 1) &&
          (ar[it + 1] == 1)) {
        k += 1;
        it += 3;
      }
      it += 2;
    } else
      it++;
  } while (it < n - 1);
  printf("%d", k);
  return 0;
}
