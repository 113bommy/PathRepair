#include <bits/stdc++.h>
using namespace std;
int a[] = {0, 1023};
int b[5];
int main() {
  int n, m;
  char c;
  scanf("%d", &n);
  getchar();
  b[0] = 0;
  b[1] = 0;
  b[2] = 0;
  for (int i = 0; i < n; i++) {
    scanf("%c %d", &c, &m);
    getchar();
    if (c == '&') {
      for (int j = 0; j < 2; j++) {
        a[j] &= m;
      }
    }
    if (c == '|') {
      for (int j = 0; j < 2; j++) {
        a[j] |= m;
      }
    }
    if (c == '^') {
      for (int j = 0; j < 2; j++) {
        a[j] ^= m;
      }
    }
  }
  int w = 1;
  for (int i = 0; i < 10; i++) {
    int p = a[0] % 2;
    a[0] /= 2;
    int q = a[1] % 2;
    a[1] /= 2;
    if (p == 0 && q == 1) {
      b[0] += 1 * w;
      b[1] += 0 * w;
      b[2] += 0 * w;
    }
    if (p == 1 && q == 0) {
      b[0] += 1 * w;
      b[1] += 0 * w;
      b[2] += 1 * w;
    }
    if (p == 0 && q == 0) {
      b[0] += 0 * w;
      b[1] += 0 * w;
      b[2] += 1 * w;
    }
    if (p == 1 && q == 1) {
      b[0] += 1 * w;
      b[1] += 0 * w;
      b[2] += 0 * w;
    }
    w *= 2;
  }
  printf("3\n");
  printf("& %d\n", b[0]);
  printf("| %d\n", b[1]);
  printf("^ %d\n", b[2]);
  return 0;
}
