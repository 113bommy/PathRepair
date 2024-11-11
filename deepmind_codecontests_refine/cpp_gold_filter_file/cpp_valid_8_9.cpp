#include <bits/stdc++.h>
int main() {
  int t, i;
  scanf("%d", &t);
  long n[t], n1[t], n2[t];
  for (i = 0; i < t; i++) {
    scanf("%ld", &n[i]);
    if ((n[i] % 3) == 1) {
      n1[i] = (n[i] / 3) + 1;
      n2[i] = n1[i] - 1;
    } else if ((n[i] % 3) == 2) {
      n1[i] = n[i] / 3;
      n2[i] = n1[i] + 1;
    } else if ((n[i] % 3) == 0) {
      n1[i] = n[i] / 3;
      n2[i] = n1[i];
    }
  }
  for (i = 0; i < t; i++) printf("%ld %ld\n", n1[i], n2[i]);
}
