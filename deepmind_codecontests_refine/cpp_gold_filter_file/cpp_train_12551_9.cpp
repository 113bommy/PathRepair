#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int Mx = 50;
const int M = 1e9 + 7;
const int INF = 0x3f3f3f3f;
vector<int> nex[N];
long long dp[N][Mx], f[Mx];
int n, k;
void dfs(int u, int p) {
  dp[u][0] = dp[u][k + 1] = 1;
  for (auto v : nex[u])
    if (v != p) {
      dfs(v, u);
      memset(f, 0, sizeof(f));
      for (int i = 0; i <= 2 * k; i++)
        for (int j = 0, t; j <= 2 * k; j++) {
          t = (i + j <= 2 * k) ? min(i, j + 1) : max(i, j + 1);
          (f[t] += dp[u][i] * dp[v][j]) %= M;
        }
      for (int i = 0; i <= 2 * k; i++) dp[u][i] = f[i];
    }
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    nex[u].push_back(v);
    nex[v].push_back(u);
  }
  memset(dp, 0, sizeof(dp));
  dfs(1, -1);
  long long ans = 0;
  for (int i = 0; i <= k; i++) (ans += dp[1][i]) %= M;
  printf("%lld\n", ans);
  return 0;
}
