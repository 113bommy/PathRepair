#include <bits/stdc++.h>
using namespace std;
int n, x, a[512];
void read() {
  int i, la = 0, p = 0, q = 0, ma = 2000000000;
  scanf("%d%d", &n, &x);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == x) la = 1;
  }
  if (la == 0) {
    a[n + 1] = x;
    n++;
    q = 1;
  }
  sort(a + 1, a + n + 1);
  printf("\n");
  for (i = 1; i <= n; i++) {
    if (a[i] == x) {
      if (i < (n + 1) / 2) {
        p = n - 2 * i;
        if (p < ma) ma = p;
      } else if (i > (n + 1) / 2) {
        p = (i - 1) - (n - i);
        if (p < ma) ma = p;
      } else
        ma = 0;
    }
  }
  printf("%d\n", ma + q);
}
int main() {
  read();
  return 0;
}
