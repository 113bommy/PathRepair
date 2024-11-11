#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
long long l, r, a[10], b[MAXN], ans = 0x3f3f3f3f3f3f3f3f;
int n, cnt[MAXN];
pair<long long, int> d[MAXN << 3];
int main() {
  for (int i = 1; i <= 6; i++) scanf("%lld", &a[i]);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
  for (int i = 1; i <= 6; i++)
    for (int j = 1; j <= n; j++) d[(i - 1) * n + j] = make_pair(b[j] - a[i], j);
  sort(d + 1, d + 6 * n + 1);
  l = 1, r = 1;
  int tot = 0;
  for (; r <= 6 * n; r++) {
    if (!cnt[d[r].second]) tot++;
    cnt[d[r].second]++;
    while (cnt[d[l].second] > 1) --cnt[d[l++].second];
    if (tot == n) ans = min(ans, d[r].first - d[l].first);
  }
  printf("%lld\n", ans);
  return 0;
}
