#include <bits/stdc++.h>
int main() {
  long long n, m, nn, j, l;
  while (~scanf("%I64d%I64d%I64d", &n, &nn, &m)) {
    int lk = 0;
    for (l = 1; l <= nn; l = l * m) {
      if (l >= n) {
        lk = 1;
        break;
      }
      if (l * m <= 0 || l * m % m != 0) break;
    }
    if (lk == 0)
      printf("-1\n");
    else {
      for (j = l; j <= nn; j = j * m) {
        printf("%I64d", j);
        if (j * m % m != 0) break;
        if (j <= nn / m) printf(" ");
      }
      printf("\n");
    }
  }
}
