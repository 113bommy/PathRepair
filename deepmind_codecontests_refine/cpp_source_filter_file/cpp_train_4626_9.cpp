#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, j, n, i;
  scanf("%d", &n);
  int a[103] = {0}, cnt = 0;
  int f, s, mx = 0;
  for (int i = (int)0; i < (int)n; i++) {
    scanf("%d", &l);
    scanf("%d", &r);
    mx = max(mx, r);
    if (i == 0) {
      f = l;
      s = r;
      cnt = r - l;
      continue;
    }
    for (j = l + 1; j <= r; j++) a[j] = 1;
  }
  for (i = f; i <= s; i++) {
    if (a[i] == 1) cnt--;
  }
  printf("%d\n", max(cnt, 0));
  return 0;
}
