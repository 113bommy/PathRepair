#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, greatest = 0, i;
  scanf("%d %d", &a, &b);
  i = a;
  while (i != 0) {
    greatest = max(greatest, i % 10);
    i /= 10;
  }
  i = b;
  while (i != 0) {
    greatest = max(greatest, i % 10);
    i /= 10;
  }
  int res = 0, n = 0;
  while (a != 0 || b != 0) {
    n = (n + a % 10 + b % 10) / (greatest + 1);
    a /= 10;
    b /= 10;
    res++;
  }
  if (n != 0) res++;
  printf("%d", res);
  return 0;
}
