#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
vector<int> ne[200010];
int m, pos;
int ans;
int a[200010], b[200010], c[200010], dp[200010][4];
inline int mo(int x) {
  if (x >= MOD) return x - MOD;
  return x;
}
void dfs(int u, int fa) {
  for (int v : ne[u]) {
    if (v == fa) continue;
    dfs(v, u);
  }
  a[0] = 1;
  pos = m = 0;
  for (int v : ne[u]) {
    if (v == fa)
      pos = m;
    else
      ++m, a[m] = 1ll * a[m - 1] * mo(dp[v][0] + dp[v][1]) % MOD,
           b[m] = mo(dp[v][2] + dp[v][3]), c[m] = mo(dp[v][0] + b[m]);
  }
  c[m + 1] = 1;
  for (int i = m; i; i--) c[i] = 1ll * c[i] * c[i + 1] % MOD;
  for (int i = 1; i <= m; i++)
    dp[u][i > pos ? 2 : 0] = mo(dp[u][i > pos ? 2 : 0] +
                                1ll * a[i - 1] * b[i] % MOD * c[i + 1] % MOD);
  dp[u][1] = 1ll * a[pos] * c[pos + 1] % MOD;
  dp[u][3] = a[m];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ne[x].push_back(y);
    ne[y].push_back(x);
  }
  dfs(1, -1);
  ans = mo(mo(dp[1][0] + dp[1][2]) + dp[1][3]);
  printf("%d\n", ans);
}
