#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int l, r;
int ax[1005];
int main() {
  scanf("%d%d%d", &n, &m, &c);
  int x, i, j;
  while (l + r != n) {
    fflush(stdout);
    scanf("%d", &x);
    if (x < c / 2) {
      i = upper_bound(ax + 1, ax + 1 + l, x) - ax;
      printf("%d\n", i);
      ax[i] = x;
      if (i == 1 + l) l++;
    } else {
      i = lower_bound(ax + n + 1 - r, ax + n + 1, x) - ax - 1;
      ax[i] = x;
      printf("%d\n", i);
      if (i == n - r) r++;
    }
  }
  return 0;
}
