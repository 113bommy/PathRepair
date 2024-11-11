#include <bits/stdc++.h>
int n, m;
long long a[200010];
long long q;
int l, r;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]), a[i] += a[i - 1];
  while (m--) {
    scanf("%I64d", &q);
    l = 0;
    r = n;
    while (l < r) {
      register int mid = (l + r) >> 1;
      if (a[mid] < q)
        l = mid + 1;
      else
        r = mid;
    }
    printf("%d %I64d\n", l, q - a[l - 1]);
  }
  return 0;
}
