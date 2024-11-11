#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int s = n / 2 + 1;
  printf("%d\n", s);
  printf("1 1\n");
  int l = 1, r = 2;
  for (int i = 2; i <= n; i++) {
    printf("%d %d\n", l, r);
    if (l < r)
      l++;
    else
      r++;
  }
}
