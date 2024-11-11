#include <bits/stdc++.h>
using namespace std;
void load() {}
const int N = 1e5 + 123;
int lab[N], pr[N], dep[N], sz[N], l[N], r[N];
vector<int> ed[N];
map<int, int> Map[N], Map1[N];
bool vis[N];
int Findset(int u) { return (u == lab[u]) ? u : lab[u] = Findset(lab[u]); }
void dfs(int u, int p) {
  vis[u] = 1;
  for (int v : ed[u]) {
    if (v == p) continue;
    if (!vis[v]) {
      Map1[u][v] = v;
      Map1[v][u] = v;
      dep[v] = dep[u] + 1;
      pr[v] = u;
      dfs(v, u);
    } else {
      int tmp = u;
      if (dep[tmp] > dep[v]) ++sz[Findset(tmp)], Map[v][u] = u, Map[u][v] = u;
      tmp = Findset(tmp);
      while (dep[tmp] > dep[v]) {
        int l = Findset(tmp), r = Findset(pr[tmp]);
        if (dep[pr[tmp]] > dep[v]) lab[l] = r, sz[r] += sz[l];
        tmp = r;
      }
    }
  }
}
void trungtt() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    ed[u].push_back(v), ed[v].push_back(u);
    Map[u][v] = Map[v][u] = -1;
    l[i] = u, r[i] = v;
  }
  for (int i = 1; i <= n; ++i) lab[i] = i;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) dfs(i, 0);
  vector<int> ans;
  for (int i = 1; i <= m; ++i) {
    int u = l[i], v = r[i];
    if (Map[u][v] != -1 && sz[Findset(Map[u][v])] == 1) ans.push_back(i);
    if (Map[u][v] == -1 && sz[Findset(Map1[u][v])] == 1) ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  for (int v : ans) printf("%d ", v);
}
int main() {
  load();
  trungtt();
  return 0;
}
