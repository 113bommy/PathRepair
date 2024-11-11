#include <bits/stdc++.h>
int n, l, r;
int main() {
  scanf("%d", &n);
  do {
    scanf("%d%d", &l, &r);
    printf("%d\n",
           (((r - l - 1) & 1) * r + (l - r - 1) / 2) * ((l & 1) ? -1 : 1));
  } while (--n);
  return 0;
}
