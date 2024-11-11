#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 3e5 + 5;
int n, k;
long long a[maxn], suf[maxn];
int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];
  long long ans = suf[1];
  sort(suf + 1, suf + n + 1, greater<long long>());
  for (int i = 1; i <= k - 1; i++) {
    ans += suf[i];
  }
  printf("%lld\n", ans);
  return 0;
}
