#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
long long pw(long long a, long long b) {
  long long ret = 1;
  long long mul = a;
  while (b > 0) {
    if (b & 1) ret = (ret * mul);
    mul = (mul * mul);
    b /= 2;
  }
  return ret;
}
long long to_int(string s) {
  long long ret = 0;
  for (int(i) = (0); (i) < (s.size()); (i)++) {
    ret += pw(10, s.size() - i - 1) * (long long)(s[i] - '0');
  }
  return ret;
}
const int MAXN = 1e5 + 15, mod = 1e9 + 7;
int n, p[MAXN], dp[MAXN][2], f[MAXN][2];
vector<int> adj[MAXN];
void dfs(int v) {
  for (int u : adj[v]) dfs(u);
  for (int(i) = (0); (i) < (adj[v].size() + 1); (i)++) f[i][0] = f[i][1] = 0;
  f[0][1] = 1;
  for (int(i) = (1); (i) < (adj[v].size() + 1); (i)++) {
    int u = adj[v][i - 1];
    f[i][1] = (1ll * dp[u][1] * f[i - 1][0] + 1ll * dp[u][0] * f[i - 1][1] +
               f[i - 1][1]) %
              mod;
    f[i][0] = (1ll * dp[u][1] * f[i - 1][1] + 1ll * dp[u][0] * f[i - 1][0] +
               f[i - 1][0]) %
              mod;
  }
  dp[v][1] = f[adj[v].size()][1];
  dp[v][0] = f[adj[v].size()][0];
  for (int(i) = (0); (i) < (adj[v].size() + 1); (i)++) f[i][0] = f[i][1] = 0;
  f[0][1] = 1;
  for (int(i) = (1); (i) < (adj[v].size() + 1); (i)++) {
    int u = adj[v][adj[v].size() - i];
    f[i][1] = (1ll * dp[u][1] * f[i - 1][0] + 1ll * dp[u][0] * f[i - 1][1] +
               f[i - 1][1]) %
              mod;
    f[i][0] = (1ll * dp[u][1] * f[i - 1][1] + 1ll * dp[u][0] * f[i - 1][0] +
               f[i - 1][0]) %
              mod;
  }
  dp[v][1] += f[adj[v].size()][1];
  if (dp[v][1] >= mod) dp[v][1] -= mod;
  dp[v][0] += f[adj[v].size()][0];
  if (dp[v][0] >= mod) dp[v][0] -= mod;
  for (int(i) = (0); (i) < (adj[v].size() + 1); (i)++) f[i][0] = f[i][1] = 0;
  f[0][1] = 1;
  for (int(i) = (1); (i) < (adj[v].size() + 1); (i)++) {
    int u = adj[v][i - 1];
    f[i][1] = (1ll * dp[u][0] * f[i - 1][1] + f[i - 1][1]) % mod;
    f[i][0] = (1ll * dp[u][0] * f[i - 1][0] + f[i - 1][0]) % mod;
  }
  dp[v][1] -= f[adj[v].size()][1];
  if (dp[v][1] < 0) dp[v][1] += mod;
  for (int(i) = (0); (i) < (adj[v].size() + 1); (i)++) f[i][0] = f[i][1] = 0;
  f[0][1] = 1;
  for (int(i) = (1); (i) < (adj[v].size() + 1); (i)++) {
    int u = adj[v][i - 1];
    f[i][1] = (1ll * dp[u][1] * f[i - 1][0] + f[i - 1][1]) % mod;
    f[i][0] = (1ll * dp[u][1] * f[i - 1][1] + f[i - 1][0]) % mod;
  }
  dp[v][0] -= f[adj[v].size()][0];
  if (dp[v][0] < 0) dp[v][0] += mod;
}
int main() {
  cin >> n;
  for (int(i) = (1); (i) < (n); (i)++) {
    cin >> p[i];
    p[i]--;
    adj[p[i]].push_back(i);
  }
  dfs(0);
  cout << (dp[0][0] + dp[0][1]) % mod << "\n";
}
