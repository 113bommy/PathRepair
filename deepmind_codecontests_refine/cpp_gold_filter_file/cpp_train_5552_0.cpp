#include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000];
int main() {
  int n, i, f, j, r = 1, s = 0;
  scanf("%i", &n);
  for (i = 0; i < n; i++) {
    scanf("%i %i", &a[i], &b[i]);
  }
  a[i] = 100000;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - (i + 1); j++) {
      if (b[j] < b[j + 1]) {
        b[j] ^= b[j + 1];
        b[j + 1] ^= b[j];
        b[j] ^= b[j + 1];
        a[j] ^= a[j + 1];
        a[j + 1] ^= a[j];
        a[j] ^= a[j + 1];
      }
      if (b[j] == b[j + 1] && a[j] < a[j + 1]) {
        b[j] ^= b[j + 1];
        b[j + 1] ^= b[j];
        b[j] ^= b[j + 1];
        a[j] ^= a[j + 1];
        a[j + 1] ^= a[j];
        a[j] ^= a[j + 1];
      }
    }
  }
  j = 0;
  for (i = r; i > 0; i--) {
    s += a[j];
    i += b[j];
    if (a[j + 1] == 100000) break;
    j++;
  }
  printf("%i", s);
  return 0;
}
