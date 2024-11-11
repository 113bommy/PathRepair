#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], b[200005], l, r, x;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  b[n] = -1;
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] == a[i + 1])
      b[i] = b[i + 1];
    else
      b[i] = i + 1;
  }
  while (m--) {
    scanf("%d %d %d", &l, &r, &x);
    if (a[l] != x)
      printf("%d\n", l);
    else {
      if (b[l] <= r)
        printf("%d\n", b[l]);
      else
        printf("-1\n");
    }
  }
  return 0;
}
