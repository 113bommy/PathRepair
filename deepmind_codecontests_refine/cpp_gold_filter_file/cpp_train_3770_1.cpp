#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005, mod = 998244353, maxm = maxn << 1;
int n;
int f[maxn][4], pre[maxn], now[maxn], suf[maxn];
vector<int> v[maxn];
void dfs(int x, int last) {
  for (int i = 0; i < v[x].size(); i++)
    if (v[x][i] != last) dfs(v[x][i], x);
  int cnt = 0, fa = 0;
  for (int i = 0; i < v[x].size(); i++) {
    int y = v[x][i];
    if (y != last)
      cnt++, pre[cnt] = (f[y][0] + f[y][1]) % mod,
             now[cnt] = (f[y][2] + f[y][3]) % mod,
             suf[cnt] = ((f[y][0] + f[y][2]) % mod + f[y][3]) % mod;
    else
      fa = cnt;
  }
  pre[0] = suf[cnt + 1] = 1;
  for (int i = 1; i <= cnt; i++) pre[i] = 1ll * pre[i - 1] * pre[i] % mod;
  for (int i = cnt; i >= 1; i--) suf[i] = 1ll * suf[i + 1] * suf[i] % mod;
  for (int i = 1; i <= cnt; i++)
    f[x][i <= fa ? 0 : 2] =
        (f[x][i <= fa ? 0 : 2] +
         1ll * pre[i - 1] * now[i] % mod * suf[i + 1] % mod) %
        mod;
  f[x][1] = 1ll * pre[fa] * suf[fa + 1] % mod, f[x][3] = pre[cnt];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y), v[y].push_back(x);
  }
  dfs(1, 0);
  printf("%d\n", ((f[1][0] + f[1][2]) % mod + f[1][3]) % mod);
  return 0;
}
