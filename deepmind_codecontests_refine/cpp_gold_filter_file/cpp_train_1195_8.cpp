#include <bits/stdc++.h>
void g(long long &xx) {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  xx = x * f;
}
int main() {
  long long m, h1, a1, h2, a2, x1, x2, y1, y2, p1, p2, rx1, rx2;
  g(m), g(h1), g(a1), g(x1), g(y1), g(h2), g(a2), g(x2), g(y2);
  p1 = p2 = rx1 = rx2 = -1;
  for (int i = 1; i <= 2 * m; ++i) {
    h1 = (h1 * x1 + y1) % m;
    if (h1 == a1) {
      if (p1 == -1)
        p1 = i;
      else if (rx1 == -1)
        rx1 = i - p1;
    }
    h2 = (h2 * x2 + y2) % m;
    if (h2 == a2) {
      if (p2 == -1)
        p2 = i;
      else if (rx2 == -1)
        rx2 = i - p2;
    }
  }
  if (p1 == -1 || p2 == -1)
    printf("-1\n");
  else if (p1 == p2)
    printf("%I64d\n", p1);
  else {
    for (int i = 1; i <= 2 * m; ++i) {
      if (p1 < p2)
        p1 += rx1;
      else
        p2 += rx2;
      if (p1 == p2) {
        printf("%I64d\n", p1);
        return 0;
      }
    }
    printf("-1\n");
  }
  return 0;
}
