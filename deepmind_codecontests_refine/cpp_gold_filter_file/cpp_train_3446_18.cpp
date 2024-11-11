#include <bits/stdc++.h>
using namespace std;
int n, m, a[300005], t;
long long ans[300005], s[300005];
struct node {
  int x, k, op;
  bool operator<(const node o) const { return k < o.k; }
} u[300005];
void calc(int l, int r) {
  int k = u[l].k;
  if (k <= t) {
    for (int i = 1; i <= k; i++) s[n - i + 1] = a[n - i + 1];
    for (int i = n - k; i >= 1; i--) s[i] = s[i + k] + a[i];
    for (int i = l; i <= r; i++) ans[u[i].op] = s[u[i].x];
  } else {
    for (int i = l; i <= r; i++) {
      int now = u[i].x;
      while (now <= n) ans[u[i].op] += a[now], now += u[i].k;
    }
  }
}
int main() {
  scanf("%d", &n);
  t = sqrt(n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &u[i].x, &u[i].k), u[i].op = i;
  sort(u + 1, u + m + 1);
  int pre = 1;
  for (int i = 2; i <= m; i++)
    if (u[i].k != u[i - 1].k) calc(pre, i - 1), pre = i;
  calc(pre, m);
  for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
  return 0;
}
