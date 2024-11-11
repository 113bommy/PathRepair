#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 1e6 + 6;
int n, a[maxn], p[maxm], vis[maxm], fa[maxm];
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 2, m = 1e6; i <= m; i++) {
    if (!vis[i]) p[++p[0]] = i;
    fa[i] = i;
    for (int j = 1; j <= p[0] && i * p[j] <= m; j++) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
  int pd = 0;
  for (int i = 1, x, y; i <= n; i++) {
    if (pd)
      x = get(2), y = sqrt(x);
    else
      x = get(a[i]), y = sqrt(x), pd |= (x > a[i]);
    printf("%d%c", x, i == n ? '\n' : ' ');
    for (int j = 1; p[j] <= y; j++) {
      if (x % p[j]) continue;
      while (!(x % p[j])) x /= p[j];
      for (int o = p[j]; o < maxm; o += p[j]) fa[get(o)] = get(o + 1);
    }
    if (x > 1)
      for (int o = x; o < maxm; o += x) fa[get(o)] = get(o + 1);
  }
  return 0;
}
