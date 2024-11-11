#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int tc, n, m, a[200200], b[200200], c[200200], chk[200200];
ll mod = 998244353;
int main() {
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= m; i++) scanf("%d", b + i);
    for (int i = 1; i <= n; i++) chk[i] = 0;
    for (int i = 1; i <= n; i++) c[a[i]] = i;
    for (int i = 1; i <= n; i++) a[i] = c[a[i]];
    for (int i = 1; i <= m; i++) b[i] = c[b[i]];
    ll ans = 1;
    for (int i = m; i >= 1; i--) {
      if (b[i] == n) {
        if (chk[b[i] - 1]) ans = 0;
      } else if (b[i] == 1) {
        if (chk[b[i] + 1]) ans = 0;
      } else {
        if (chk[b[i] - 1] && chk[b[i] + 1])
          ans = 0;
        else if (!chk[b[i] - 1] && !chk[b[i] + 1])
          ans = (ans * 2) % mod;
      }
      chk[b[i]] = 1;
    }
    printf("%lld\n", ans);
  }
}
