#include <bits/stdc++.h>
int main() {
  int n, m, l, r, x, pos = 0, neg = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    (x == 1) ? pos++ : neg++;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &l, &r);
    if ((r - l + 1) % 2 != 0)
      printf("0\n");
    else {
      if (pos >= (r - l + 1) / 2 && neg >= (r - l + 1) / 2)
        printf("1\n");
      else
        printf("0\n");
    }
  }
}
