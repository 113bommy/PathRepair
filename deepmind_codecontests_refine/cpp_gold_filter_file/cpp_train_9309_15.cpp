#include <bits/stdc++.h>
int main() {
  long long t, l, r, n, m;
  scanf("%I64d", &t);
  while (t--) {
    scanf("%I64d%I64d%I64d", &n, &l, &r);
    if (r < l) {
      printf("No\n");
      continue;
    } else {
      m = n / l;
      m* r >= n ? printf("Yes\n") : printf("No\n");
    }
  }
  return 0;
}
