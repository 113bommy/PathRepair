#include <bits/stdc++.h>
using namespace std;
int q[55], qs, n, b[55];
long long a[60], k;
int main() {
  int i, j = 0, s, p = 0;
  scanf("%d %I64d", &n, &k);
  a[0] = a[1] = 1;
  for (i = 2; i <= 50; i++) a[i] = a[i - 1] + a[i - 2];
  a[51] = 1e18;
  while (k && p < n) {
    for (i = 1; i <= 50; i++)
      if (a[i] >= k) break;
    for (j = n - i; j > p; j--) b[j] = j;
    k -= a[i - 1];
    if (i == 1)
      b[n] = n;
    else
      b[n - i + 1] = n - i + 2, b[n - i + 2] = n - i + 1;
    p = n - i + 2;
  }
  for (i = 1; i <= n; i++) printf("%d ", b[i]);
}
