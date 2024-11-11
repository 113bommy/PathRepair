#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[1000], n, i, m = 1, l, k;
  scanf("%d", &n);
  l = 1;
  for (i = 0; i < n; i++) scanf("%d", &x[i]);
  sort(x, x + n);
  for (i = 0; i < n - 1; i++) {
    if (x[i + 1] != x[i]) {
      m++;
      k = max(k, l);
      l = 1;
    } else
      l++;
  }
  k = max(k, l);
  printf("%d %d", k, m);
  return 0;
}
