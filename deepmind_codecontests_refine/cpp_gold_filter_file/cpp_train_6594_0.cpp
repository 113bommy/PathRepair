#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int a[40], b[40], k[40], p[40];
int n, u, r;
long long ans;
void dfs(int dep, int is) {
  int tmp[40];
  memcpy(tmp, a, sizeof(a));
  if (dep > u) return;
  long long s = 0;
  int i;
  if (!is) {
    for (i = 0; i < n; i++) s += a[i] * (k[i] + 0ll);
    ans = max(ans, s);
  }
  if (dep >= u) return;
  if (is) {
    s = 0;
    for (i = 0; i < n; i++) s += (a[i] ^ b[i]) * (k[i] + 0ll);
    ans = max(ans, s);
  }
  for (i = 0; i < n; i++) tmp[i] ^= b[i];
  for (i = 0; i < n; i++) a[i] = tmp[p[i] - 1] + r;
  dfs(dep + 2, is);
  for (i = 0; i < n; i++) tmp[i] ^= b[i];
  for (i = 0; i < n; i++) a[i] = (tmp[p[i] - 1]) + r;
  dfs(dep + 1, !is);
  memcpy(a, tmp, sizeof(a));
}
int main() {
  int i, j;
  scanf("%d%d%d", &n, &u, &r);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) scanf("%d", &b[i]);
  for (i = 0; i < n; i++) scanf("%d", &k[i]);
  for (i = 0; i < n; i++) scanf("%d", &p[i]);
  ans = (1ll << 63);
  dfs(0, u & 1);
  printf("%I64d\n", ans);
}
