#include <bits/stdc++.h>
using namespace std;
int n, k, a[1050], f[1000050];
int main() {
  cin >> n >> k;
  int num = 0;
  for (register int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  for (register int i = 2; i <= n; i++) a[i] -= a[1];
  memset(f, 0x3f3f3f3f, sizeof(f));
  f[0] = 0;
  for (register int i = 2; i <= n; i++)
    for (register int j = 0; j <= a[n] * k; j++)
      if (j >= a[i]) f[j] = min(f[j], f[j - a[i]] + 1);
  for (register int i = 0; i <= a[n] * k; i++)
    if (f[i] <= k) cout << f[1] * k + i << " ";
  return 0;
}
