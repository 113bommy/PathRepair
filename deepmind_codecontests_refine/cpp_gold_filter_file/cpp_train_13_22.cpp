#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> G[maxn];
int sg[maxn], deg[maxn], Xor[maxn], topo[maxn], mem[maxn], cnt;
long long h[maxn], XOR[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%lld", &h[i]);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    ++deg[v];
  }
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 0) q.push(i);
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    topo[++cnt] = t;
    for (int i = 0; i < G[t].size(); ++i) {
      int c = G[t][i];
      --deg[c];
      if (!deg[c]) q.push(c);
    }
  }
  for (int i = n; i >= 1; --i) {
    int u = topo[i];
    for (int j = 0; j < G[u].size(); ++j) {
      int c = G[u][j];
      mem[sg[c]] = i;
    }
    while (mem[sg[u]] == i) ++sg[u];
    XOR[sg[u]] ^= h[u];
  }
  long long sghigh = -1;
  for (int i = 0; i < maxn; ++i)
    if (XOR[i] > 0) sghigh = i;
  if (sghigh == -1) return 0 * puts("LOSE");
  for (int i = 1; i <= n; ++i)
    if (sg[i] == sghigh && (XOR[sghigh] ^ h[i]) < h[i]) {
      h[i] ^= XOR[sghigh];
      for (int j = 0; j < G[i].size(); ++j) {
        int c = G[i][j];
        h[c] ^= XOR[sg[c]];
        XOR[sg[c]] = 0;
      }
      break;
    }
  printf("WIN\n");
  for (int i = 1; i <= n; ++i) printf("%lld ", h[i]);
  return 0;
}
