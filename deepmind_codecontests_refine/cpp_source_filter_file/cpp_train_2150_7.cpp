#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
const int mod = 1e9 + 7;
pair<int, int> f[maxn * 4], g[maxn * 4];
void update(pair<int, int> &a, pair<int, int> b) {
  a.first = min(a.first, b.first);
  a.second = max(a.second, b.second);
}
int main() {
  int n, i, x, y;
  scanf("%d", &n);
  for (i = 0; i < maxn; i++) f[i] = pair<int, int>(mod, -mod);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    update(f[x + y + n + n], pair<int, int>(x - y, x - y));
  }
  memcpy(g, f, sizeof(f));
  for (i = 2; i < maxn; i++) update(f[i], f[i - 2]);
  for (i = maxn - 3; i >= 0; i--) update(g[i], g[i + 2]);
  long long ans = 0;
  for (i = 1; i < maxn - 1; i++) {
    x = max(f[i - 1].first, g[i + 1].first);
    y = min(f[i - 1].second, g[i + 1].second);
    if (x <= y) ans += y - x;
  }
  printf("%lld\n", ans >> 1);
  return 0;
}
