#include <bits/stdc++.h>
int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  int e = a | b;
  int f = !(c | d);
  int g = b & c;
  int h = a | d;
  int i = e & f;
  int j = !(g | h);
  int k = i | j;
  printf("%d\n", k);
  return 0;
}
