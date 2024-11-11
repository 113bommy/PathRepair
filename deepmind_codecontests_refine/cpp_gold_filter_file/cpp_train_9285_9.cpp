#include <bits/stdc++.h>
using namespace std;
long long n, a[100005], m, ans, x, y;
int main() {
  scanf("%I64d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  sort(a + 1, a + 1 + n);
  int m = n / 2;
  for (int i = 1; i <= m; i++) x += a[i];
  for (int i = m + 1; i <= n; i++) y += a[i];
  ans = x * x + y * y;
  printf("%I64d\n", ans);
}
