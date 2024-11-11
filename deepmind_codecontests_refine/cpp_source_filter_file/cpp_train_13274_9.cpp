#include <bits/stdc++.h>
using namespace std;
char a[1100][1100];
int n, p, flag, m;
int qpow(int base, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r *= base;
    base *= base;
    b >>= 1;
  }
  return r;
}
int main() {
  a[1][1] = '*';
  p = 1;
  for (int i1 = 2; i1 < 10; i1++) {
    for (int i = 1; i <= p; i++) {
      for (int i0 = 1; i0 <= p; i0++) {
        a[i][i0 + p] = a[i + p][i0] = a[i][i0];
        if (a[i][i0] == '*')
          a[i + p][i0 + p] = '+';
        else
          a[i + p][i0 + p] = '*';
      }
    }
    p *= 2;
  }
  while (scanf("%d", &n) != EOF) {
    n = qpow(2, n);
    for (int i = 1; i <= n; i++) {
      for (int i0 = 1; i0 <= n; i0++) printf("%c", a[i][i0]);
      printf("\n");
    }
  }
  return 0;
}
