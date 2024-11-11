#include <bits/stdc++.h>
using namespace std;
int Pow(int a, int b, int md, int res = 1) {
  for (; b; b >>= 1, a = 1ll * a * a % md) {
    if (b & 1) res = 1ll * res * a % md;
  }
  return res;
}
const int N = 110, MOD = 1e9 + 7;
long long int C[N][N], second[N], dp[N][N][N], dp2[N][N], dp3[N], n;
vector<int> adj[N];
void DFS(int v, int p = -1) {
  second[v] = 1;
  dp[v][1][0] = 1;
  for (int u : adj[v]) {
    if (u != p) {
      DFS(u, v);
      memset(dp2, 0, sizeof dp2);
      for (int i = 1; i <= second[v]; i++) {
        for (int j = 1; j <= second[u]; j++) {
          for (int k = 0; k < second[v]; k++) {
            for (int l = 0; l < second[u]; l++) {
              dp2[i + j][l + k + 1] =
                  (dp2[i + j][l + k + 1] +
                   1ll * dp[v][i][k] % MOD * dp[u][j][l] % MOD) %
                  MOD;
              dp2[i][l + k] = (dp2[i][l + k] +
                               1ll * dp[v][i][k] * dp[u][j][l] % MOD * j % MOD);
            }
          }
        }
      }
      second[v] += second[u];
      for (int i = 1; i <= second[v]; i++)
        for (int j = 0; j < second[v]; j++) dp[v][i][j] = dp2[i][j];
    }
  }
}
long long int nCr(int x, int y) {
  if (~C[x][y]) return C[x][y];
  if (y < 0 || x < y || x < 0) return C[x][y] = 0;
  if (x == y || !y) return C[x][y] = 1;
  return C[x][y] = (nCr(x - 1, y) + nCr(x - 1, y - 1)) % MOD;
}
int main() {
  memset(C, -1, sizeof C);
  scanf("%lld", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(1);
  dp3[n - 1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n - 1; j++) {
      dp3[j] = (dp3[j] +
                1ll * dp[1][i][j] * i % MOD * Pow(n, n - j - 2, MOD) % MOD) %
               MOD;
    }
  }
  for (int i = n - 1; ~i; i--) {
    for (int j = i + 1; j < n; j++) {
      dp3[i] = (dp3[i] - 1ll * nCr(j, i) * dp3[j] % MOD + 2ll * MOD) % MOD;
    }
  }
  for (int i = 0; i < n; i++) printf("%lld ", dp3[i]);
  return 0;
}
