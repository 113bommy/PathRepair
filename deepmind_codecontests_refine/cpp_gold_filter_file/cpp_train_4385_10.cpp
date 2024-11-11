#include <bits/stdc++.h>
int main() {
  int x, y, z, t1, t2, t3, m, n, o;
  scanf("%d %d %d %d %d %d", &x, &y, &z, &t1, &t2, &t3);
  m = t1 * abs(x - y);
  o = abs(x - z);
  n = (t3 * 3) + (t2 * (abs(x - y) + o));
  if (m >= n) {
    printf("YES");
  } else {
    printf("NO");
  }
}
