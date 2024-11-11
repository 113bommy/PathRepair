#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
const int M = 100 + 5;
const int md = (int)1e9 + 7;
inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}
inline int mul(int a, int b) { return (int)((long long)a * b % md); }
int n, m;
vector<int> adj[N];
int sz[N];
int f[N][M];
int g[N][M];
int s[M][M];
int fact[N];
void dfs(int u, int par) {
  f[u][0] = 1;
  g[u][0] = 1;
  sz[u] = 1;
  for (auto v : adj[u]) {
    if (v == par) continue;
    dfs(v, u);
    static int nextf[M];
    static int nextg[M];
    memset(nextf, 0, sizeof nextf);
    memset(nextg, 0, sizeof nextg);
    for (int i = 0; i <= m; i++) {
      add(nextf[i], f[u][i]);
      add(nextg[i], g[u][i]);
      add(nextf[i], f[v][i]);
      add(nextg[i], g[v][i]);
      if (i) {
        add(nextg[i], g[v][i - 1]);
      }
    }
    for (int cu = min(sz[u] - 1, m); cu >= 0; cu--) {
      for (int cv = min(sz[v] - 1, m); cv >= 0; cv--) {
        int value = mul(g[u][cu], g[v][cv]);
        if (cu + cv <= m) {
          add(nextf[cu + cv], value);
          add(nextg[cu + cv], value);
        }
        if (cu + cv + 1 <= m) {
          add(nextf[cu + cv + 1], value);
          add(nextg[cu + cv + 1], value);
        }
      }
    }
    sz[u] += sz[v];
    for (int i = 0; i < min(sz[u], m + 1); i++) {
      f[u][i] = nextf[i];
      g[u][i] = nextg[i];
    }
  }
}
void solve() {
  cin >> n >> m;
  s[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      s[i][j] = mul(s[i - 1][j], j);
      add(s[i][j], s[i - 1][j - 1]);
    }
  }
  fact[0] = 1;
  for (int i = 1; i <= m; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    add(ans, mul(s[m][i], mul(fact[i], f[0][i])));
  }
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
