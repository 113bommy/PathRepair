#include <bits/stdc++.h>
long int max(long int a, long int b) { return (a + b + abs(a - b)) / 2; }
int main() {
  long int x, y, z, w, maximum, a, b, c, d;
  scanf("%li %li %li %li\n", &x, &y, &z, &w);
  maximum = max(max(max(x, y), z), w);
  a = maximum - x;
  b = maximum - y;
  c = maximum - z;
  d = maximum - w;
  if (a != 0) printf("%li ", a);
  if (b != 0) printf("%li ", b);
  if (c != 0) printf("%li ", c);
  if (d != 0) printf("%li ", d);
  return 0;
}
