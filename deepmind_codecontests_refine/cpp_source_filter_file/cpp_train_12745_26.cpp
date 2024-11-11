#include <bits/stdc++.h>
int main() {
  int n, p, k;
  scanf("%d%d%d", &n, &p, &k);
  int l = std::max(1, p - k);
  int r = std::min(n, p + k);
  bool l_b = (l == 1), r_b = (r == n);
  if (!l_b) printf("<< ");
  for (int i = l; i <= r; ++i) {
    if (i > l) printf(" ");
    if (i == p)
      printf("(%d)", p);
    else
      printf("%d", i);
  }
  if (!r_b) printf(">>");
  printf("\n");
}
