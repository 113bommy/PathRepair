#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, LOG = 40;
int n, m, b[LOG], U[maxn], V[maxn], C[maxn], d[maxn], res = 0;
vector<pair<int, int> > G[maxn];
bool vis[maxn];
void Add(int x) {
  for (int i = LOG - 1; i >= 0; i--) {
    if (x >> i & 1) {
      if (b[i]) {
        x ^= b[i];
      } else {
        b[i] = x;
        for (int j = i - 1; j >= 0; j--)
          if (b[j] && (b[i] >> j & 1)) b[i] ^= b[j];
        for (int j = i + 1; j < LOG; j++)
          if (b[j] >> i & 1) b[j] ^= b[i];
        return;
      }
    }
  }
}
void dfs(int u) {
  vis[u] = true;
  for (auto v : G[u]) {
    if (vis[v.first]) continue;
    d[v.first] = d[u] ^ v.second;
    dfs(v.first);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    G[u].push_back(pair<int, int>(v, c));
    G[v].push_back(pair<int, int>(u, c));
    U[i] = u;
    V[i] = v;
    C[i] = c;
  }
  dfs(1);
  for (int i = 0; i < m; i++) Add(d[U[i]] ^ d[V[i]] ^ C[i]);
  res = d[n];
  for (int i = LOG - 1; i >= 0; i--) {
    if ((res >> i & 1) && b[i]) {
      res ^= b[i];
    }
  }
  printf("%d\n", res);
  return 0;
}
