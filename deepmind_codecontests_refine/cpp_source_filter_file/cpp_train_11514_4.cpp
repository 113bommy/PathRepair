#include <bits/stdc++.h>
using namespace std;
const int Base = 13131;
const int N = 300000 + 5;
const int mod = 1000000000 + 7;
int n, m;
int id[N], pa[N], ans[N];
long long H[N];
vector<int> ori[N], G[N];
long long Hash(int u) {
  sort((ori[u]).begin(), (ori[u]).end());
  long long ret = 0;
  for (auto v : ori[u]) ret = (ret * Base + v) % mod;
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int u = 1; u <= n; u++) ori[u].push_back(u);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    ori[u].push_back(v);
    ori[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) H[i] = Hash(i), id[i] = i;
  sort(id + 1, id + 1 + n, [](int x, int y) { return H[x] < H[y]; });
  pa[1] = 1;
  for (int i = 2; i <= n; i++) {
    int u = id[i], v = id[i - 1];
    pa[u] = (H[u] == H[v]) ? pa[v] : u;
  }
  for (int u = 1; u <= n; u++) {
    for (auto v : ori[u]) {
      if (pa[u] != pa[v]) G[pa[u]].push_back(pa[v]);
    }
  }
  int start;
  for (int u = 1; u <= n; u++) {
    if (pa[u] != u) continue;
    sort((G[u]).begin(), (G[u]).end());
    G[u].erase(unique((G[u]).begin(), (G[u]).end()), G[u].end());
    if (G[u].size() > 2) return puts("NO"), 0;
    if (G[u].size() <= 1) start = u;
  }
  queue<int> q;
  q.push(start);
  ans[start] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (ans[v] == 0) q.push(v), ans[v] = ans[u] + 1;
    }
  }
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d%c", ans[pa[i]], " \n"[i == n]);
  return 0;
}
