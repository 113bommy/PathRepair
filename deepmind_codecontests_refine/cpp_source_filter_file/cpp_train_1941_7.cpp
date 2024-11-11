#include <bits/stdc++.h>
using namespace std;
const int N = 3333;
int n, a[N], q, l, r, inv;
int main() {
  scanf("%d", &n);
  for (int i = 0, x; i < n; i++) {
    scanf("%d", &x);
    for (int j = x; j <= n; j++)
      if (a[j]) inv;
    a[x] = 1;
  }
  inv &= 1;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &l, &r);
    int len = r - l + 1;
    if ((len * (len - 1) / 2) & 1) inv = !inv;
    if (!inv)
      puts("odd");
    else
      puts("even");
  }
}
