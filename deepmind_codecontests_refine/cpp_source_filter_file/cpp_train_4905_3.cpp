#include <bits/stdc++.h>
using namespace std;
const int maxn = 50 + 2;
int n;
struct Edge {
  int to, nxt;
};
Edge edge[maxn << 1];
int cnt, head[maxn];
void addedge(int u, int v) {
  cnt++;
  edge[cnt].to = v;
  edge[cnt].nxt = head[u];
  head[u] = cnt;
}
double fac[maxn];
void Fact() {
  fac[1] = 1;
  for (int i = 2; i < n; i++) fac[i] = fac[i - 1] * i;
}
double C[maxn][maxn];
void Com() {
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }
}
int siz[maxn];
double dp[maxn][maxn], f[maxn], g[maxn];
void DP(int u, int fa) {
  siz[u] = 0;
  dp[u][0] = 1;
  for (int i = head[u]; ~i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    DP(v, u);
    for (int i = 0; i <= siz[v]; i++) f[i] = 0;
    for (int i = 0; i <= siz[v]; i++)
      for (int j = 1; j <= siz[v]; j++)
        if (j <= i)
          f[i] += dp[v][min(i, j - 1)] * 0.5;
        else
          f[i] += dp[v][min(i, j - 1)];
    for (int i = 0; i <= siz[u] + siz[v]; i++) g[i] = 0;
    for (int i = 0; i <= siz[u]; i++)
      for (int j = 0; j <= siz[v]; j++)
        g[i + j] += dp[u][i] * f[j] * C[i + j][j] *
                    C[siz[u] + siz[v] - i - j][siz[v] - j];
    for (int i = 0; i <= siz[u] + siz[v]; i++) dp[u][i] = g[i];
    siz[u] += siz[v];
  }
  siz[u]++;
}
void init() {
  cnt = 0;
  memset(head, -1, sizeof(head));
}
int main() {
  init();
  scanf("%d", &n);
  Com();
  Fact();
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  for (int i = 1; i <= n; i++) {
    DP(i, 0);
    printf("%.10lf\n", dp[i][n - 1] / fac[n - 1]);
  }
  return 0;
}
