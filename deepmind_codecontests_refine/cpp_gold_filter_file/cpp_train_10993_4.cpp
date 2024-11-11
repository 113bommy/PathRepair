#include <bits/stdc++.h>
int main() {
  int x, i, y, z;
  int p, q;
  int n, r;
  int sum = 0;
  scanf("%d", &n);
  for (i = 0;; i++) {
    x = 5 * pow(2, i);
    sum = sum + x;
    if (n <= sum) break;
  }
  y = sum - x;
  z = n - y;
  p = x / 5;
  q = z / p;
  r = z % p;
  if (r == 0) {
    if (q == 1) printf("Sheldon");
    if (q == 2) printf("Leonard");
    if (q == 3) printf("Penny");
    if (q == 4) printf("Rajesh");
    if (q == 5) printf("Howard");
  } else {
    if (q == 0) printf("Sheldon");
    if (q == 1) printf("Leonard");
    if (q == 2) printf("Penny");
    if (q == 3) printf("Rajesh");
    if (q == 4) printf("Howard");
  }
  return 0;
}
