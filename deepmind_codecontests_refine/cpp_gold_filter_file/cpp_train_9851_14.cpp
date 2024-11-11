#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005, MOD = 1e9 + 7;
int n, x[maxn], y[maxn], a[maxn], b[maxn], pw[maxn];
int fa[maxn], siz[maxn], ed[maxn];
inline int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &x[i], &y[i]), a[++a[0]] = x[i], b[++b[0]] = y[i];
  sort(a + 1, a + 1 + a[0]);
  a[0] = unique(a + 1, a + 1 + a[0]) - a - 1;
  sort(b + 1, b + 1 + b[0]);
  b[0] = unique(b + 1, b + 1 + b[0]) - b - 1;
  for (int i = 1; i <= n; i++)
    x[i] = lower_bound(a + 1, a + 1 + a[0], x[i]) - a,
    y[i] = lower_bound(b + 1, b + 1 + b[0], y[i]) - b;
  pw[0] = 1;
  for (int i = 1; i <= a[0] + b[0]; i++)
    fa[i] = i, siz[i] = 1, pw[i] = pw[i - 1] * 2 % MOD;
  for (int i = 1; i <= n; i++) {
    int fx = getfa(x[i]), fy = getfa(y[i] + a[0]);
    if (fx == fy)
      ed[fx]++;
    else
      fa[fx] = fy, siz[fy] += siz[fx], ed[fy] += ed[fx] + 1;
  }
  long long ans = 1;
  for (int i = 1; i <= a[0] + b[0]; i++)
    if (getfa(i) == i)
      if (ed[i] == siz[i] - 1)
        (ans *= pw[siz[i]] - 1) %= MOD;
      else
        (ans *= pw[siz[i]]) %= MOD;
  printf("%lld", (ans + MOD) % MOD);
  return 0;
}
