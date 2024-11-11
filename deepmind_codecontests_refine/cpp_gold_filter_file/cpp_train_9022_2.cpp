#include <bits/stdc++.h>
using namespace std;
const int maxn = 4002;
const int maxk = 200;
const int mod = 998244353;
int k;
long long C[maxk * 2][maxk * 2];
struct TreePointDivide {
  vector<int> tree[maxn];
  int centroid, sz[maxn], w[maxn], sum, n;
  int order[maxn], tot;
  long long ans[maxk], f[maxk][maxn], g[maxk][maxn];
  bool vis[maxn];
  void addedge(int u, int v) {
    tree[u].push_back(v);
    tree[v].push_back(u);
    n++;
  }
  void getcentroid(int u, int fa) {
    sz[u] = 1;
    w[u] = 0;
    for (int v : tree[u]) {
      if (v == fa || vis[v]) continue;
      getcentroid(v, u);
      sz[u] += sz[v];
      w[u] = max(w[u], sz[v]);
    }
    w[u] = max(w[u], sum - sz[u]);
    if (!centroid || w[u] < w[centroid]) centroid = u;
  }
  void getvertice(int u, int fa) {
    order[++tot] = u;
    sz[u] = 1;
    for (int v : tree[u])
      if (v != fa && !vis[v]) {
        getvertice(v, u);
        sz[u] += sz[v];
      }
  }
  void calc(int u) {
    tot = 0;
    getvertice(u, 0);
    for (int i = 1; i <= tot; i++) f[0][order[i]] = 0;
    g[0][u] = f[0][u] = 1;
    for (int i = 1; i <= k; i++)
      for (int j = 1; j <= tot; j++) {
        int now = order[j];
        f[i][now] = g[i][now] = 0;
        for (int v : tree[now]) {
          if (vis[v]) continue;
          g[i][now] = (g[i][now] + g[i - 1][v]) % mod;
          if (v != u)
            f[i][now] = (f[i][now] + f[i - 1][v]) % mod;
          else if (i == 1)
            f[i][now] = (f[i][now] + f[i - 1][v]) % mod;
        }
      }
    for (int v = 1; v <= tot; v++) {
      int now = order[v];
      if (now == u)
        for (int i = 0; i <= k; i++) ans[i] = (ans[i] + g[i][now]) % mod;
      else
        for (int i = 0; i <= k; i++)
          for (int j = 0; i + j <= k; j++)
            ans[i + j] = (ans[i + j] + f[i][now] * g[j][now] % mod) % mod;
    }
    vis[u] = true;
    for (int v : tree[u]) {
      if (vis[v]) continue;
      centroid = 0;
      sum = sz[v];
      getcentroid(v, u);
      calc(centroid);
    }
  }
  void solve() {
    centroid = 0;
    sum = n;
    getcentroid(1, 0);
    calc(centroid);
  }
} A, B;
int main() {
  for (int i = 0; i < maxk; i++) C[i][0] = 1;
  for (int i = 1; i < maxk; i++)
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  int n1, n2;
  cin >> n1 >> n2 >> k;
  for (int i = 1; i <= n1 - 1; i++) {
    int u, v;
    cin >> u >> v;
    A.addedge(u, v);
  }
  for (int i = 1; i <= n2 - 1; i++) {
    int u, v;
    cin >> u >> v;
    B.addedge(u, v);
  }
  A.solve();
  B.solve();
  long long ans = 0;
  for (int i = 0; i <= k; i++)
    ans = (ans + C[k][k - i] * A.ans[i] % mod * B.ans[k - i] % mod) % mod;
  cout << ans << endl;
}
