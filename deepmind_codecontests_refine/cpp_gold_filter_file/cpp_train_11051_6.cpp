#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<int, int>;
constexpr int N = 2e6 + 5, mod = 1e9 + 7;
constexpr ld eps = 1e-9, inf = 1e50;
int ma, a[N], b[N], cnt[N], n, m;
ll ans, sm;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) ans += 1ll * a[i] * m;
  for (int i = 1; i <= m; ++i) scanf("%d", b + i), sm += b[i];
  sort(b + 1, b + m + 1);
  if (b[1] < a[n]) {
    puts("-1");
    return 0;
  } else if (b[1] == a[n])
    ans += sm - 1ll * a[n] * m;
  else
    ans += sm - 1ll * a[n] * (m - 1) - a[n - 1];
  printf("%lld\n", ans);
  return 0;
}
