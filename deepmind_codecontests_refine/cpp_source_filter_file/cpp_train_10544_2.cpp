#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int T, n, m, a[200005], l[200005], r[200005], b[200005];
bool used[200005];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 5; i++) l[i] = 0, r[i] = 0, used[i] = 0, a[i] = 0;
    int ans = 1;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
      scanf("%d", &b[i]);
      used[b[i]] = 1;
    }
    for (int i = 1; i <= n; i++) l[a[i]] = a[i - 1], r[a[i]] = a[i + 1];
    for (int i = 1; i <= m; i++) {
      int cnt = 0, x = b[i];
      if (l[x] != 0 && !used[l[x]]) cnt++;
      if (r[x] != 0 && !used[r[x]]) cnt++;
      ans = 1ll * ans * cnt % mod;
      r[l[x]] = r[x], l[r[x]] = l[x];
    }
    printf("%d\n", ans);
  }
  return 0;
}
