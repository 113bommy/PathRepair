#include <bits/stdc++.h>
int A, B, n;
long long bites(int l, int r, int m) {
  long long result = 0;
  long long len = r - l + 1;
  long long h1 = A + (l - 1) * (long long)B;
  long long h2 = A + (r - 1) * (long long)B;
  result = ((h1 + h2) * len) / 2;
  result = (result - 1) / m + 1;
  if (result < h2) return h2;
  return result;
}
int main() {
  int l, t, m, r, r0, r1;
  scanf("%d %d %d\n", &A, &B, &n);
  while (n--) {
    scanf("%d %d %d\n", &l, &t, &m);
    r0 = l - 1;
    r1 = l + 10000000;
    while (r0 + 1 < r1) {
      r = (r0 + r1) / 2;
      if (bites(l, r, m) <= t)
        r0 = r;
      else
        r1 = r;
    }
    if (r0 < l)
      printf("-1\n");
    else
      printf("%d\n", r0);
  }
}
