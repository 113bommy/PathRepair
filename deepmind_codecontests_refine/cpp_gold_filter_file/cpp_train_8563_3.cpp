#include <bits/stdc++.h>
int cmmdc(int a, int b) {
  if (a == b)
    return a;
  else if (a > b)
    return cmmdc(a - b, b);
  else
    return cmmdc(b - a, a);
}
int n, s, b, z, numitor, numarator, dc;
int main() {
  scanf("%d", &n);
  numitor = n - 2;
  for (b = 2; b < n; b++) {
    z = n;
    while (z > 0) {
      s = s + z % b;
      z = z / b;
    }
  }
  numarator = s;
  dc = cmmdc(numarator, numitor);
  printf("%d/%d", numarator / dc, numitor / dc);
  return 0;
}
