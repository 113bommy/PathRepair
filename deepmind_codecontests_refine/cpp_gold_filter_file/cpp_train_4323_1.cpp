#include <bits/stdc++.h>
using namespace std;
int power(int a) {
  int i, p = 1;
  for (i = 1; i <= a; i++) p *= 2;
  return p;
}
int main() {
  int n, l, z = 0;
  scanf("%d", &n);
  while (n) {
    l = log2l(n);
    printf("%d ", l + 1);
    n %= power(l);
  }
  return 0;
}
