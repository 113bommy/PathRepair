#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1100], b[1100], i, x;
  char c;
  int h, t;
  for (i = 0; i <= 1000; i++) b[i] = 0;
  int n = 0;
  for (;;) {
    scanf("%d", &x);
    if (b[x] == 0) {
      b[x] = 1;
      a[n] = x;
      n++;
    }
    c = getchar();
    if (c == '\n') break;
  }
  sort(a, a + n);
  h = t = a[0];
  i = 0;
  for (;;) {
    while (a[i + 1] - a[i] == 1) {
      i++;
    }
    t = a[i];
    if (h == t) {
      printf("%d", h);
    } else
      printf("%d-%d", h, t);
    h = a[i + 1];
    i++;
    if (i != n) printf(",");
    if (i > n - 1) break;
    ;
  }
  return 0;
}
