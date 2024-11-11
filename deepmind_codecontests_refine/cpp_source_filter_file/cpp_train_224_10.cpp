#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int a = 0, b = 100001, l, r;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &l, &r);
      if (l > a) a = l;
      if (r < b) b = r;
    }
    int d;
    d = a - b;
    if (d > 0)
      printf("%d\n", d);
    else
      printf("0\n");
  }
  return 0;
}
