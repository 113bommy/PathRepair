#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
int n, a[maxn];
int main() {
  while (~scanf("%d", &n)) {
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      maxx = maxx > a[i] ? maxx : a[i];
    }
    a[n++] = -1;
    int ans = 1, tmp = 0;
    for (int i = 0; i < n; ++i)
      if (a[i] == maxx) {
        ++tmp;
      } else {
        ans = tmp > ans ? tmp : ans;
        tmp = 0;
      }
    printf("%d\n", ans);
  }
  return 0;
}
