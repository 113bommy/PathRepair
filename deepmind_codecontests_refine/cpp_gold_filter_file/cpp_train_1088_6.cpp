#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
  int n, k, i;
  while (scanf("%d%d", &n, &k) == 2) {
    k -= 1;
    if (k % 2 == 0) {
      for (i = 1; i <= k + 1; i += 2) a[i] = (i + 1) / 2;
      for (i = 2; i <= k; i += 2) a[i] = n - a[i - 1] + 1;
      for (i = k + 2; i <= n; i++) a[i] = a[i - 1] + 1;
    } else {
      for (i = 1; i <= k; i += 2) a[i] = (i + 1) / 2;
      for (i = 2; i <= k + 1; i += 2) a[i] = n - a[i - 1] + 1;
      for (i = k + 2; i <= n; i++) a[i] = a[i - 1] - 1;
    }
    for (i = 1; i < n; i++) printf("%d ", a[i]);
    printf("%d\n", a[n]);
  }
  return 0;
}
