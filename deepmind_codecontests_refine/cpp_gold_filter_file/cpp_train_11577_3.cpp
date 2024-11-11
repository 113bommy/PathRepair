#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int Q, n, K, lnk[maxn], son[2 * maxn], nxt[2 * maxn], w[2 * maxn], tot;
long long f[maxn][2], a[maxn];
bool cmp1(int x, int y) { return x > y; }
void adde(int x, int y, int z) {
  son[++tot] = y, w[tot] = z, nxt[tot] = lnk[x], lnk[x] = tot;
}
void dfs(int x, int fa) {
  for (int j = lnk[x]; j; j = nxt[j])
    if (son[j] != fa) dfs(son[j], x);
  int tail = 0;
  f[x][0] = f[x][1] = 0;
  for (int j = lnk[x]; j; j = nxt[j])
    if (son[j] != fa)
      f[x][0] += f[son[j]][0], f[x][1] += f[son[j]][0],
          a[++tail] = f[son[j]][1] + w[j] - f[son[j]][0];
  sort(a + 1, a + 1 + tail, cmp1);
  for (int i = 1; i <= min(tail, K); i++)
    if (a[i] > 0) {
      if (i < K) f[x][1] += a[i];
      f[x][0] += a[i];
    } else
      break;
}
int main() {
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%d", &n, &K);
    tot = 0;
    for (int i = 1; i <= n; i++) lnk[i] = 0;
    for (int i = 1; i < n; i++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      adde(x, y, z);
      adde(y, x, z);
    }
    dfs(1, 0);
    printf("%lld\n", f[1][0]);
  }
  return 0;
}
