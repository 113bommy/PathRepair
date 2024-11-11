#include <bits/stdc++.h>
int main() {
  long int a, i, c = 0, temp, j, d = 0;
  scanf("%ld", &a);
  long int x[a];
  for (i = 0; i < a; i++) scanf("%ld", &x[i]);
  for (i = 0; i < a; i++) {
    for (j = i + 1; j < a; j++) {
      if (x[i] > x[j]) {
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;
      }
    }
  }
  for (i = 0; i < a; i++) d = x[a - 1] - x[i] + d;
  printf("%ld", d);
  return 0;
}
