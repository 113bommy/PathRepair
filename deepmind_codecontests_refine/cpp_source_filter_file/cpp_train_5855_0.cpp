#include <bits/stdc++.h>
int GCD(int a, int b) {
  int c;
  while (b > 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
void SWAP(int *a, int *b) {
  int c;
  c = *a;
  *a = *b;
  *b = c;
}
int MAX(int a, int b) { return (a > b) ? a : b; }
int MIN(int a, int b) { return (a < b) ? a : b; }
int main() {
  int a, i, x;
  scanf("%d", &a);
  for (i = 3; i <= a; i += 2) {
    x = a / i;
    if (a % i == 0) {
      printf("%d%d\n", i, x);
      break;
    }
  }
  return 0;
}
