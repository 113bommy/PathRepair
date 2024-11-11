#include <bits/stdc++.h>
using namespace std;
int a[200005], f[200005], d[200005];
int main() {
  int n, sum1 = 0, sum2 = 0, cnt = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i % 2 == 0)
      f[i] = a[i] + f[i - 2];
    else {
      d[i] = a[i] + d[i - 2];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1 && n % 2 == 0) {
      if ((d[i] - a[i - 1] + f[n] - f[i - 1]) == (f[i - 1] + d[n - 1] - d[i]))
        cnt++;
    }
    if (i % 2 == 1 && n % 2 == 1) {
      if ((d[i] - a[i] + f[n - 1] - f[i - 1]) == (f[i - 1] + d[n] - d[i]))
        cnt++;
    }
    if (i % 2 == 0 && n % 2 == 1) {
      if ((f[i] - a[i] + d[n] - d[i - 1]) == (d[i - 1] + f[n - 1] - f[i]))
        cnt++;
    }
    if (i % 2 == 0 && n % 2 == 0) {
      if ((f[i] - a[i] + d[n - 1] - d[i - 1]) == (d[i - 1] + f[n] - f[i]))
        cnt++;
    }
  }
  printf("%d\n", cnt);
}
