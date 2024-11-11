#include <bits/stdc++.h>
int main() {
  int n, m, k, l;
  scanf("%d%d%d%d", &n, &m, &k, &l);
  if (k != l) {
    if (m == n) {
      printf("Second");
      return 0;
    } else {
      n > m ? printf("First") : printf("Second");
      return 0;
    }
  } else if (k == l) {
    if (m > n)
      printf("Second");
    else
      printf("First");
  }
  return 0;
}
