#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[204], y[204], i, j, n, cnt = 0, r, l, u, d;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
  for (i = 1; i < n; i++) {
    r = 0, l = 0, u = 0, d = 0;
    for (j = 1; j <= n; j++) {
      if (i == j) continue;
      if ((x[j] > x[i]) && (y[j] == y[i])) r++;
      if ((x[j] < x[i]) && (y[j] == y[i])) l++;
      if ((y[j] < y[i]) && (x[j] == x[i])) u++;
      if ((y[j] > y[i]) && (x[j] == x[i])) d++;
    }
    if (r > 0 && l > 0 && u > 0 && d > 0) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
