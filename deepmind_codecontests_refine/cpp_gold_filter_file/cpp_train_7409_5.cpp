#include <bits/stdc++.h>
using namespace std;
int a[2002];
int main() {
  int n, d;
  int i;
  scanf("%d%d", &n, &d);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  int m = 0;
  int now = a[0];
  for (i = 1; i < n; i++) {
    if (a[i] == now) {
      m++;
      now = now + d;
    } else if (a[i] < now) {
      int ka = now - a[i];
      int ta = ka / d + 1;
      m += ta;
      now = a[i] + (ka / d + 1) * d;
    } else
      now = a[i];
  }
  printf("%d\n", m);
  return 0;
}
