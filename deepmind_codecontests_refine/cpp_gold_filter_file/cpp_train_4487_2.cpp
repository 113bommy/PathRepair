#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main() {
  int n, m;
  scanf("%d", &m);
  n = m * 2;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  long long ans = 1ll * (a[m - 1] - a[0]) * (a[n - 1] - a[m]);
  for (int i = 1; i + m < n; i++)
    ans = min(ans, 1ll * (a[n - 1] - a[0]) * (a[i + m - 1] - a[i]));
  printf("%lld\n", ans);
  return 0;
}
