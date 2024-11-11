#include <bits/stdc++.h>
using namespace std;
const int N = 200010, M = 200010;
int n, m;
int e, to[M], nxt[M], hd[N], deg[N];
int tag[N], sg[N], val[N], sum[N];
vector<int> vec[N];
void add(int x, int y) {
  to[++e] = y;
  nxt[e] = hd[x];
  hd[x] = e;
}
void topo() {
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 0) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = hd[u]; i; i = nxt[i]) {
      int v = to[i];
      deg[v]--;
      if (deg[v] == 0) q.push(v);
    }
    for (int i = 0; i < vec[u].size(); i++) {
      int v = vec[u][i];
      tag[sg[v]] = u;
    }
    while (tag[sg[u]] == u) sg[u]++;
    sum[sg[u]] ^= val[u];
  }
  return;
}
void solve() {
  for (int i = n; i >= 0; i--) {
    if (!sum[i]) continue;
    int pos = 0;
    for (int j = 1; j <= n; j++)
      if (sg[j] == i && (val[j] ^ sum[i]) < val[j]) pos = j;
    val[pos] ^= sum[i];
    for (int j = 0; j < vec[pos].size(); j++) {
      int v = vec[pos][j];
      val[v] ^= sum[sg[v]];
      sum[sg[v]] = 0;
    }
    puts("WIN");
    for (int j = 1; j <= n; j++) printf("%d ", val[j]);
    puts("");
    return;
  }
  puts("LOSE");
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d%d", &u, &v);
    vec[u].push_back(v);
    add(v, u);
    deg[u]++;
  }
  topo();
  solve();
  return 0;
}
