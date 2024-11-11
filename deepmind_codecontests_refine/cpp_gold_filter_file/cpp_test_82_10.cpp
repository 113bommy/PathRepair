#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5, H = 18;
int n, q, k, a[N], mn[N], sta[N], go[N][20];
long long s[N][20];
int main() {
  scanf("%d%d%d", &n, &q, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = n, l = 1, r = 0; i; --i) {
    while (l <= r && a[sta[r]] >= a[i]) --r;
    sta[++r] = i;
    while (l <= r && sta[l] > i + k) ++l;
    mn[i] = a[sta[l]];
  }
  for (int i = n + k; i > n - k; --i)
    for (int j = 0; j <= H; ++j) go[i][j] = n + k;
  for (int i = n - k; i; --i) {
    if (mn[i + k] >= mn[i]) {
      int now = i + k;
      for (int t = H; ~t; --t)
        if (mn[go[now][t]] >= mn[i]) now = go[now][t];
      go[i][0] = go[now][0];
    } else
      go[i][0] = i + k;
    s[i][0] = 1ll * mn[i] * (go[i][0] - i) / k;
    for (int t = 1; t <= H; ++t)
      go[i][t] = go[go[i][t - 1]][t - 1],
      s[i][t] = s[i][t - 1] + s[go[i][t - 1]][t - 1];
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    r -= (r - l) % k;
    long long ans = a[l];
    for (int i = H; ~i; --i)
      if (go[l][i] <= r) ans += s[l][i], l = go[l][i];
    ans += 1ll * mn[l] * (r - l) / k;
    printf("%lld\n", ans);
  }
  return 0;
}
