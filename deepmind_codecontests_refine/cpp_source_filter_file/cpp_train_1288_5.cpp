#include <bits/stdc++.h>
using namespace std;
int n, k, i, a[1000021], j;
int main() {
  scanf("%d%d", &n, &k);
  if (n / k <= 2) {
    cout << -1;
    exit(0);
  }
  for (i = 1; i <= k * ((n / k) - 1); i++) a[i] = (i - 1) / ((n / k) - 1) + 1;
  j = ((n / k) - 1) * k;
  while (j <= n)
    for (i = 1; i <= k; i++)
      if (j <= n) a[++j] = i;
  for (i = 1; i <= n; i++) printf("%d", a[i]);
  return 0;
}
