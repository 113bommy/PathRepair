#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int t, m, n;
long long su, s[maxn], cf[maxn];
int a[maxn], b[maxn], c[maxn], x, y;
int main() {
  scanf("%d %d", &n, &m);
  scanf("%d", a + 1);
  for (int i = 2; i <= m; ++i) {
    scanf("%d", a + i);
    su += abs(a[i] - a[i - 1]);
  }
  for (int i = 1; i <= n; ++i) s[i] = su;
  for (int i = 1; i <= m - 1; ++i) {
    x = min(a[i], a[i + 1]), y = max(a[i], a[i + 1]);
    if (x == y) continue;
    s[x] += x - 1;
    s[y] += 2 * x - y;
    if (x + 1 == y) continue;
    b[i] = x + 1;
    c[i] = y - 1;
  }
  for (int i = 1; i <= m - 1; ++i) {
    x = b[i];
    y = c[i];
    --cf[x];
    ++cf[y + 1];
  }
  for (int i = 1; i <= m - 1; i++) {
    cf[i] = cf[i - 1] + cf[i];
    s[i] += cf[i];
  }
  for (int i = 1; i <= n; ++i) printf("%lld ", s[i]);
  return 0;
}
