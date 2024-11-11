#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
ll a[maxn];
int n;
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    sort(a + 1, a + 1 + n, [&](int a, int b) { return a > b; });
    ll ans = a[1], mx = a[1];
    bool x = 0, y = 0, z = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] * 2 == mx) x = 1;
      if (a[i] * 3 == mx) y = 1;
      if (a[i] * 5 == mx) z = 1;
      if (!(mx % a[i])) a[i] = -1;
    }
    if (x && y && z) ans = max(ans, ans / 2 + ans / 3 + ans / 5);
    sort(a + 1, a + 1 + n, [&](int a, int b) { return a > b; });
    while (a[n] == -1 && n) --n;
    if (!n) {
      printf("%lld\n", ans);
      continue;
    }
    ll a1 = a[1];
    ans = max(ans, a1 + ans);
    for (int i = 1; i <= n; ++i)
      if (a[1] % a[i]) ans = max(ans, a[i] + mx + a1);
    printf("%lld\n", ans);
  }
  return 0;
}
