#include <bits/stdc++.h>
int n, A[1000111], H[1000111], k;
int main() {
  int i, j, ii, x;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &x);
    A[x] = i;
  }
  scanf("%d", &x);
  H[0] = A[x];
  k = 0;
  for (ii = 1; ii < n; ++ii) {
    scanf("%d", &x);
    x = A[x];
    if (H[k] > x)
      H[++k] = x;
    else {
      for (i = -1, j = 20; j >= 0; --j)
        if (i + (1 << (j)) <= k && H[i + (1 << (j))] > x) i += (1 << (j));
      H[i + 1] = x;
    }
  }
  printf("%d\n", k + 1);
  return 0;
}
