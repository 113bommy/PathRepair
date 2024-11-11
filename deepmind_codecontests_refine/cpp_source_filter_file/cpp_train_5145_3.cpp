#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main() {
  int i, n, l, r, mid, sum, num;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", a + i);
  sort(a + 1, a + 1 + n);
  a[n + 1] = 0x7fffffff;
  a[0] = -1;
  r = n + 1;
  sum = 0;
  for (i = 0, num = a[n - i] / 2; i * 2 + 2 <= n; i++, num = a[n - i] / 2) {
    l = 0;
    while (l + 1 < r) {
      mid = (l + r) >> 1;
      if (a[mid] <= num)
        l = mid;
      else
        r = mid;
    }
    if (l) {
      r = l;
      a[r] = 0x7fffffff;
      sum++;
    }
  }
  printf("%d", n - sum);
  return 0;
}
