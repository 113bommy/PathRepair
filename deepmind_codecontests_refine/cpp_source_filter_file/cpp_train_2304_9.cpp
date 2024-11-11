#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007;
const int N = 100005, M = 205;
struct edge {
  int to, next;
} e[N * 2];
int head[N], sz[N], tot;
int P[N], S[M][M], n, K;
int f[N][M], tmp[M], sum[M], ans;
void init() {
  P[0] = S[0][0] = 1;
  for (int i = (int)(1); i <= (int)(N - 1); i++) P[i] = 2ll * P[i - 1] % mo;
  for (int i = (int)(1); i <= (int)(M - 1); i++)
    for (int j = (int)(1); j <= (int)(i); j++)
      S[i][j] = 1ll * j * (S[i - 1][j - 1] + S[i - 1][j]) % mo;
}
void add(int x, int y) {
  e[++tot] = (edge){y, head[x]};
  head[x] = tot;
}
void dfs(int x, int fa) {
  f[x][0] = 2;
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa) {
      dfs(e[i].to, x);
      for (int j = (int)(0); j <= (int)(min(sz[x], K)); j++)
        for (int k = (int)(0); k <= (int)(min(sz[e[i].to], K - j)); k++)
          tmp[j + k] = (tmp[j + k] + 1ll * f[x][j] * f[e[i].to][k]);
      for (int j = (int)(0); j <= (int)(min(sz[e[i].to], K)); j++)
        sum[j] = (sum[j] + mo - f[e[i].to][j]) % mo;
      sz[x] += sz[e[i].to];
      for (int j = (int)(0); j <= (int)(min(sz[x], K)); j++)
        f[x][j] = tmp[j], tmp[j] = 0;
    }
  ++sz[x];
  for (int j = (int)(0); j <= (int)(min(sz[x], K)); j++)
    sum[j] = (sum[j] + f[x][j]) % mo;
  for (int j = (int)(min(sz[x], K)); j >= (int)(1); j--)
    f[x][j] = (f[x][j] + f[x][j - 1]) % mo;
  f[x][1] = (f[x][1] + mo - 1) % mo;
}
int main() {
  init();
  scanf("%d%d", &n, &K);
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs(1, 0);
  for (int i = (int)(1); i <= (int)(K); i++)
    ans = (ans + 1ll * sum[i] * S[K][i]) % mo;
  printf("%d\n", ans);
}
