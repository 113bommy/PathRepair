#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 10;
int mn[N], to[N][20], n, q, k, a[N], pw[N], b[N], l, r;
long long s[N][20];
int main() {
  scanf("%d%d%d", &n, &q, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  l = 1;
  r = 0;
  pw[0] = k;
  for (int i = 1; i < 20 && pw[i - 1] <= n; ++i) pw[i] = pw[i - 1] << 1;
  for (int i = n; i >= 1; --i) {
    while (l <= r && a[b[r]] > a[i]) --r;
    b[++r] = i;
    while (l <= r && b[l] > i + k) ++l;
    mn[i] = a[b[l]];
  }
  a[n + k] = -1;
  for (int i = n + k; i > n - k; --i)
    for (int j = 0; j < 20; ++j) to[i][j] = n + k;
  for (int i = n - k; i >= 1; --i) {
    to[i][0] = i + k;
    if (mn[to[i][0]] >= mn[i]) {
      int x = to[i][0];
      for (int j = 19; j >= 0; --j)
        if (mn[to[x][j]] >= mn[i]) x = to[x][j];
      to[i][0] = x;
    }
    s[i][0] = 1ll * mn[i] * (to[i][0] - i) / k;
    for (int j = 1; j < 20; ++j) {
      to[i][j] = to[to[i][j - 1]][j - 1];
      s[i][j] = s[i][j - 1] + s[to[i][j - 1]][j - 1];
    }
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    r -= (r - l) % k;
    long long ans = a[l];
    for (int i = 19; i >= 0; --i)
      if (to[l][i] <= r) ans += s[l][i], l = to[l][i];
    printf("%lld\n", ans + 1ll * mn[l] * ((r - l) / k));
  }
  return 0;
}
