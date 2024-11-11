#include <bits/stdc++.h>
using namespace std;
int n;
int a[111111];
int l[111111], r[111111];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int ll = 0, rr = 0;
  for (int i = 0; i < n; i++) {
    if (ll == 0 || l[ll - 1] != a[i])
      l[ll++] = a[i];
    else if (rr == 0 || r[rr - 1] != a[i])
      r[rr++] = a[i];
  }
  int ans = 0;
  if (ll && rr && l[ll - 1] == r[rr - 1])
    ans = ll + rr - 1;
  else
    ans = ll + rr;
  printf("%d\n", ans);
  if (ans == ll + rr - 1) {
    for (int i = 0; i < ll - 1; i++) printf("%d ", l[i]);
    for (int i = 0; i < rr; i++) printf("%d ", r[rr - i - 1]);
  } else {
    for (int i = 0; i < ll; i++) printf("%d ", l[i]);
    for (int i = 0; i < rr; i++) printf("%d ", r[rr - i - 1]);
  }
  return 0;
}
