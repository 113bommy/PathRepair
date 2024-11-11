#include <bits/stdc++.h>
using namespace std;
int a[550];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int ans = 1e9;
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int num = 0;
      int x = a[i - 1] - 1;
      for (int k = i; k <= j; k++) {
        int kk = x / a[k];
        x -= kk * a[k];
        num += kk;
      }
      x = a[i - 1] - 1 - x + a[j];
      num++;
      int xx = x;
      if (ans > xx) {
        for (int k = 1; k <= n; k++) {
          int kk = x / a[k];
          x -= kk * a[k];
          num -= kk;
        }
        if (num < 0) ans = xx;
      }
    }
  }
  if (ans == -1)
    printf("-1\n");
  else
    printf("%d\n", ans);
  return 0;
}
