#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  e = (max(abs(a - b) + 1, 2) + max(abs(c - d) + 1, 2)) * 2;
  printf("%d\n", e);
  return 0;
}
