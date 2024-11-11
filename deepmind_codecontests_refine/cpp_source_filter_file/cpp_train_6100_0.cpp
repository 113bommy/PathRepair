#include <bits/stdc++.h>
using namespace std;
const int N = 200050, mo = 1e9 + 7;
int nn[N][3], d[N], cnt = 1, g[N], c[N], f[N], ni[N], dw[N], up[N], head[N];
int fap(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) s = 1ll * s * a % mo;
    b >>= 1, a = 1ll * a * a % mo;
  }
  return s;
}
void dfs1(int x, int fa) {
  if (d[x] == 1) return;
  for (int i = head[x], y; i; i = nn[i][0])
    if ((i ^ 1) != fa && d[y = nn[i][1]] > 1) dfs1(y, i), dw[x] += f[i];
  if (fa)
    f[fa] = 1ll * ni[x] * fap(mo + 1 - 1ll * dw[x] * ni[x] % mo, mo - 2) % mo;
  return;
}
void dfs2(int x, int fa) {
  if (fa) {
    int id = fa ^ 1, y = nn[id][1];
    up[x] = f[id] =
        1ll * ni[y] *
        fap(mo + 1 - 1ll * ((up[y] + dw[y] - f[fa]) % mo + mo) * ni[y] % mo,
            mo - 2) %
        mo;
    g[x] = 1ll * ni[y] *
           fap(mo + 1 - 1ll * ((up[y] + dw[y] - f[fa]) % mo + mo) * ni[y] % mo,
               mo - 2) %
           mo * g[y] % mo;
  }
  for (int i = head[x], y; i; i = nn[i][0])
    if ((i ^ 1) != fa && d[y = nn[i][1]] > 1) dfs2(y, i);
  return;
}
int main() {
  int n, u, v, w;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    scanf("%d%d%d", &u, &v, &w), ++u, ++v;
    (nn[++cnt][1] = v, nn[cnt][0] = head[u], head[u] = cnt, nn[cnt][2] = w,
     ++d[v]),
        (nn[++cnt][1] = u, nn[cnt][0] = head[v], head[v] = cnt, nn[cnt][2] = w,
         ++d[u]);
  }
  if (d[1] <= 1) return puts("0"), 0;
  for (int i = 1; i <= n; ++i) ni[i] = fap(d[i], mo - 2);
  dfs1(1, 0), g[1] = 1, dfs2(1, 0);
  int ans = 0;
  for (int i = 2; i <= cnt; ++i) {
    int id = nn[i ^ 1][1];
    c[i] = 1ll * ni[id] *
           fap(mo + 1 - 1ll * (up[id] + dw[id]) * ni[id] % mo, mo - 2) % mo;
    (ans += 1ll * nn[i][2] * g[id] % mo * c[i] % mo) %= mo;
  }
  cout << ans;
  return 0;
}
