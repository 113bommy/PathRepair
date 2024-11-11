#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int mod = 998244353;
int n, k;
int col[maxn], num[maxn];
vector<int> g[maxn];
bool flag = 1;
long long dp[maxn][2];
int now[maxn], siz[maxn];
vector<long long> tmp;
long long tmp1[maxn], tmp2[maxn];
void dfs(int u, int fa) {
  for (int i = 0; i < g[u].size(); i++)
    if (g[u][i] != fa) dfs(g[u][i], u);
  if (col[u]) now[u] = col[u], siz[u] = 1;
  for (int i = 0; i < g[u].size(); i++)
    if (g[u][i] != fa && now[g[u][i]]) {
      int v = g[u][i];
      if (now[u] && now[u] != now[v]) {
        flag = 0;
      }
      now[u] = now[v], siz[u] += siz[v];
    }
  if (now[u]) {
    dp[u][0] = 1;
    for (int i = 0; i < g[u].size(); i++)
      if (g[u][i] != fa) {
        int v = g[u][i];
        if (now[v])
          dp[u][0] *= dp[v][0];
        else
          dp[u][0] *= dp[v][1];
        dp[u][0] %= mod;
      }
  } else {
    dp[u][1] = 1;
    tmp.clear();
    tmp.push_back(1);
    for (int i = 0; i < g[u].size(); i++)
      if (g[u][i] != fa) {
        int v = g[u][i];
        dp[u][1] *= dp[v][1];
        dp[u][1] %= mod;
        tmp.push_back(dp[v][1]);
      } else
        tmp.push_back(1);
    tmp.push_back(1);
    long long tmp3 = 1;
    for (int i = 0; i < tmp.size(); i++) {
      tmp3 *= tmp[i];
      tmp3 %= mod;
      tmp1[i] = tmp3;
    }
    tmp3 = 1;
    for (int i = tmp.size() - 1; i >= 0; i--) {
      tmp3 *= tmp[i];
      tmp3 %= mod;
      tmp2[i] = tmp3;
    }
    for (int i = 0; i < g[u].size(); i++)
      if (g[u][i] != fa) {
        int v = g[u][i];
        dp[u][0] += dp[v][0] * (tmp1[i] * tmp2[i + 2]) % mod;
        dp[u][0] %= mod;
      }
  }
  if (num[now[u]] == siz[u]) now[u] = 0, siz[u] = 0;
  if (!now[u]) {
    dp[u][1] += dp[u][0];
    dp[u][1] %= mod;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &col[i]), num[col[i]]++;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  if (flag)
    printf("%lld\n", dp[1][0]);
  else
    printf("0\n");
}
