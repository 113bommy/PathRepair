#include <bits/stdc++.h>
using namespace std;
const int N = int(1e6);
int ans[N], l[N], r[N], n, m, a[N];
int pref[N + 10];
int val[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &l[i], &r[i]);
  }
  int res;
  for (int i = 1; i <= N; i++) pref[i] = pref[i - 1] ^ i;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    mx = 0;
    for (int j = i; j <= n; j++) {
      res = pref[a[i]] ^ pref[a[j]] ^ (a[i] < a[j] ? a[i] : a[j]);
      mx = max(mx, res);
      val[a[j]] = mx;
    }
    for (int j = 1; j <= m; j++) {
      if (l[j] <= i && r[j] >= i) ans[j] = max(ans[j], val[a[r[j]]]);
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
