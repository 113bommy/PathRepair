#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
struct EDGE {
  int v, next;
} edge[200100];
int n;
int k;
int tot = 0;
int ind[100100];
int ax[100100];
int bx[100100];
long long s[230][230];
long long jc[230];
long long dp[100100][230];
long long f[100100];
long long ans[100100];
int sz[100100];
long long ksm(long long aa, long long bb) {
  long long ret = 1;
  while (bb != 0) {
    if (bb % 2 == 1) ret = (ret % mod) * (aa % mod) % mod;
    bb /= 2;
    aa = (aa % mod) * (aa % mod) % mod;
  }
  return ret;
}
void add(int aa, int bb) {
  tot++;
  edge[tot].v = bb;
  edge[tot].next = ind[aa];
  ind[aa] = tot;
}
void ycl() {
  int i, j;
  s[1][1] = 1;
  for (i = 2; i <= k; i++)
    for (j = 1; j <= i; j++)
      s[i][j] = (s[i - 1][j - 1] + (1ll * j * s[i - 1][j]) % mod) % mod;
  jc[0] = 1;
  for (i = 1; i <= k; i++) jc[i] = (1ll * i * jc[i - 1]) % mod;
}
void dfs(int x, int fx) {
  int i, j, l;
  sz[x] = 1;
  dp[x][0] = 1;
  for (i = ind[x]; i != -1; i = edge[i].next) {
    if (fx == edge[i].v) continue;
    dfs(edge[i].v, x);
    for (j = 0; j <= min(k, sz[x]); j++) f[j] = dp[x][j];
    for (j = 1; j <= min(k, sz[edge[i].v]); j++)
      dp[x][j] =
          ((dp[x][j] + dp[edge[i].v][j - 1]) % mod + dp[edge[i].v][j]) % mod;
    dp[x][0] = (dp[x][0] + dp[edge[i].v][0]) % mod;
    for (j = 0; j <= min(sz[x], k); j++) {
      for (l = 0; l <= min(sz[edge[i].v], k - j); l++) {
        dp[x][j + l] += (dp[edge[i].v][l] * f[j]) % mod;
        dp[x][j + l] %= mod;
        ans[j + l] = (ans[j + l] + (dp[edge[i].v][l] * f[j]) % mod) % mod;
        dp[x][j + l + 1] += (dp[edge[i].v][l] * f[j]) % mod;
        dp[x][j + l + 1] %= mod;
        ans[j + l + 1] =
            (ans[j + l + 1] + (dp[edge[i].v][l] * f[j]) % mod) % mod;
      }
    }
    sz[x] += sz[edge[i].v];
  }
}
int main() {
  int i, aa, bb, cc, j;
  scanf("%d%lld", &n, &k);
  memset(ind, -1, sizeof(ind));
  for (i = 1; i < n; i++) {
    scanf("%d%d", &ax[i], &bx[i]);
    add(ax[i], bx[i]);
    add(bx[i], ax[i]);
  }
  ycl();
  dfs(1, 0);
  long long shuchu = 0;
  for (i = 1; i <= k; i++) {
    shuchu = (shuchu + ((s[k][i] * jc[i]) % mod * ans[i]) % mod) % mod;
  }
  printf("%lld", shuchu);
  return 0;
}
