#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long INF = 1e18;
int pri[5] = {2, 3, 5, 7, 11};
int a[10000];
int main() {
  int n;
  scanf("%d", &n);
  int m = 2 * n * n;
  for (int lim = 1; lim <= 5; lim++) {
    int tt, tot = 1;
    a[0] = 1;
    for (int o = 0; o < lim; o++) {
      tt = tot;
      for (int i = 0; i < tot; i++) {
        int ret = a[i];
        while (m / pri[o] >= ret) {
          ret *= pri[o];
          a[tt++] = ret;
        }
      }
      tot = tt;
    }
    if (tot > n) {
      sort(a, a + tot);
      reverse(a, a + tot);
      for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        i + 1 == n ? puts("") : printf(" ");
      }
      return 0;
    }
  }
  return 0;
}
