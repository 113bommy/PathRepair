#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4005;
const long long INF = 1e18;
template <typename T>
void chkmax(T& x, T y) {
  if (y > x) x = y;
}
template <typename T>
void chkmin(T& x, T y) {
  if (y < x) x = y;
}
int N, M, a[MAXN], stk[MAXN], slen, ls[MAXN], rs[MAXN], rt;
long long f[MAXN][MAXN];
int siz[MAXN];
void dfs(int u) {
  if (ls[u]) dfs(ls[u]);
  if (rs[u]) dfs(rs[u]);
  if (!ls[u] && !rs[u]) {
    f[u][0] = 0;
    f[u][1] = (M - 1) * a[u];
    siz[u] = 1;
  } else {
    siz[u] = siz[ls[u]] + siz[rs[u]] + 1;
    for (int i = 1; i <= siz[u]; ++i) f[u][i] = -INF;
    for (int i = 0; i <= siz[ls[u]]; ++i)
      for (int j = 0; j <= siz[rs[u]]; ++j) {
        long long tmp = f[ls[u]][i] + f[rs[u]][j] - 2ll * a[u] * i * j;
        if (tmp > f[u][i + j]) f[u][i + j] = tmp;
        tmp = f[ls[u]][i] + f[rs[u]][j] - 2ll * a[u] * (i * j + i + j) +
              1ll * a[u] * (M - 1);
        if (tmp > f[u][i + j + 1]) f[u][i + j + 1] = tmp;
      }
  }
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= N; ++i) {
    while (slen && a[stk[slen]] > a[i]) ls[i] = stk[slen], --slen;
    rs[stk[slen]] = i, stk[++slen] = i;
  }
  rt = stk[1];
  dfs(rt);
  printf("%lld", f[rt][M]);
  return 0;
}
