#include <bits/stdc++.h>
using namespace std;
long long a[111111], b[111111];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long suma = 0ll, sumb = 0ll;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), suma += a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) scanf("%lld", &b[i]), sumb += b[i];
  sort(b + 1, b + m + 1);
  long long t1 = sumb, t2 = suma;
  for (int i = 1; i <= n; i++) t1 += min(sumb, a[i]);
  for (int i = 1; i <= m; i++) t2 += min(suma, b[i]);
  printf("%lld\n", min(t1, t2));
  return 0;
}
