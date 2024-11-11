#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[59], b[59];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%lld", &b[i]);
  long long p1, p2, maxv = -2e18;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i] * b[j] > maxv) {
        maxv = a[i] * b[j];
        p1 = i;
        p2 = j;
      }
  maxv = -2e18;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (i != p1 && a[i] * b[j] > maxv) maxv = a[i] * b[j];
  printf("%lld\n", maxv);
  return 0;
}
