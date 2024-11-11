#include <bits/stdc++.h>
using namespace std;
const int magic = 37;
const int maxn = 1e6 + 5;
vector<int> G[maxn];
unsigned long long hsh_adj[maxn];
unsigned long long hsh[maxn], pw[maxn];
int n, m;
int MAIN() {
  scanf("%d%d", &n, &m);
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pw[i] = pw[i - 1] * magic;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v), G[v].push_back(u);
  }
  for (int u = 1; u <= n; ++u) {
    for (int i = 0; i < G[u].size(); ++i) {
      int v = G[u][i];
      hsh_adj[u] += pw[v];
    }
    hsh[u] = hsh_adj[u];
  }
  sort(hsh + 1, hsh + n + 1);
  long long cnt = 1;
  long long res = 0;
  for (int u = 1; u <= n; ++u) {
    if (u == n || hsh[u] != hsh[u + 1]) {
      if (cnt & 1)
        res += (cnt - 1) / 2 * cnt;
      else
        res += cnt / 2 * (cnt - 1);
      cnt = 0;
    }
    ++cnt;
  }
  for (int u = 1; u <= n; ++u) {
    for (int i = 0; i < G[u].size(); ++i) {
      int v = G[u][i];
      if (v > u && hsh_adj[u] - pw[v] == hsh_adj[v] - pw[u]) ++res;
    }
  }
  printf("%I64d\n", res);
  return 0;
}
int main() {
  ios ::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  return MAIN();
}
