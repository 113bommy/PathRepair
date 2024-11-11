#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
vector<int> G[100005];
int n, k;
long long dp[100005][205], S[205][205];
long long Add(long long a, long long b) {
  if (b < 0) return a >= -b ? a + b : a + MOD + b;
  return a + b >= MOD ? a + b - MOD : a + b;
}
long long Mul(long long a, long long b) { return 1ll * a * b % MOD; }
void Pre() {
  S[1][1] = 1;
  for (int i = 2; i <= k; i++)
    for (int j = 1; j <= i; j++)
      S[i][j] = Add(Mul(S[i - 1][j], j), S[i - 1][j - 1]);
}
int siz[205];
long long tmp[205], Ans[205];
void dfs(int u, int fa) {
  siz[u] = 1;
  dp[u][0] = 2;
  for (int qwq = 0; qwq < (int)G[u].size(); qwq++) {
    int v = G[u][qwq];
    if (v == fa) continue;
    dfs(v, u);
    for (int i = 0; i <= k; i++) tmp[i] = 0;
    for (int i = 0; i <= min(k, siz[u]); i++) {
      for (int j = 0; j <= min(k - i, siz[v]); j++)
        tmp[i + j] = Add(tmp[i + j], Mul(dp[u][i], dp[v][j]));
    }
    for (int i = 0; i <= k; i++)
      dp[u][i] = tmp[i], Ans[i] = Add(Ans[i], -dp[v][i]);
    siz[u] += siz[v];
  }
  for (int i = 0; i <= k; i++) Ans[i] = Add(Ans[i], dp[u][i]);
  for (int i = k; i; i--) dp[u][i] = Add(dp[u][i], dp[u][i - 1]);
  dp[u][1] = Add(dp[u][1], -1);
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  Pre();
  dfs(1, 0);
  long long ans = 0, Fac = 1;
  for (int i = 0; i <= k; i++, Fac = Mul(Fac, i))
    ans = Add(ans, Mul(Ans[i], Mul(S[k][i], Fac)));
  printf("%lld", ans);
  return 0;
}
