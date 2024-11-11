#include <bits/stdc++.h>
int main() {
  long int n, m;
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%ld%ld", &n, &m);
    if (n == 1)
      printf("0\n");
    else if (n == 2) {
      printf("%ld\n", m);
    } else {
      printf("%ld\n", 2 * m);
    }
  }
  return 0;
}
