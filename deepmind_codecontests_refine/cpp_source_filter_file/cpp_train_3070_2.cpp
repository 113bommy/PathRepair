#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char c[111111];
int a[111111], b[111111], d[111111];
int main() {
#pragma comment(linker, "/STACK:536870912")
  int n, i, j, r, k;
  gets(c);
  n = strlen(c);
  for (i = 0; i < n; i++) {
    a[i] = c[i] - '0';
  }
  gets(c);
  for (i = 0; i < n; i++) {
    b[i] = c[i] - '0';
  }
  r = 0;
  k = 0;
  for (i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      d[i] = a[i];
    } else {
      r++;
      if (k == 0) {
        k = 1;
        d[i] = a[i];
      } else {
        k = 0;
        d[i] = b[i];
      }
    }
  }
  if (r % 2 == 0) {
    for (i = 0; i < n; i++) {
      printf("%d", d[i]);
    }
  } else {
    printf("Impossible");
  }
  return 0;
}
