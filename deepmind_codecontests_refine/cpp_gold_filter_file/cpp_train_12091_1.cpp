#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, k, m;
int a[N];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  long long ans = 0;
  ans += 1ll * (m / (k + 1)) * (1ll * k * a[n] + a[n - 1]);
  ans += 1ll * (m % (k + 1)) * a[n];
  printf("%lld\n", ans);
}
