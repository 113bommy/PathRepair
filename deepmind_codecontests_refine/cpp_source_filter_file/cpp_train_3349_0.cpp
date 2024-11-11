#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
struct Edge {
  int to, next, id;
} e[MAXN * 4];
int head[MAXN], te = 1;
int deg[MAXN];
inline void addE(int u, int v, int id) {
  e[++te] = (Edge){v, head[u], id}, head[u] = te, deg[u]++;
}
vector<int> euler;
int vis[MAXN], vise[MAXN], mark[MAXN];
int n, m, u, v;
void dfs(int u) {
  vis[u] |= 1;
  for (int &j = head[u]; j > 0; j = e[j].next) {
    if (vise[j >> 1]) continue;
    vise[j >> 1] = 1;
    int v = e[j].to, id = e[j].id;
    dfs(e[j].to);
    euler.push_back(id);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    addE(u, v, i);
    addE(v, u, i);
  }
  for (int i = 1, j = 0; i <= n; i++) {
    if (deg[i] % 2 != 0) {
      ++j;
      addE(0, i, m + j);
      addE(i, 0, m + j);
    }
  }
  int cnt = m;
  for (int i = 0; i <= n; i++) {
    if (!vis[i]) {
      euler.clear();
      dfs(i);
      int sz = euler.size();
      reverse(euler.begin(), euler.end());
      for (int j = 1; j < sz; j += 2) {
        if (euler[j] > m) continue;
        int x = (j - 1 + sz) % sz, y = (j + 1) % sz;
        if (euler[x] > m || euler[y] > m) continue;
        mark[euler[j]] = 1;
        --cnt;
      }
    }
  }
  cout << cnt << endl;
  for (int i = 1; i <= m; i++) {
    if (!mark[i]) {
      int x = (i << 1), y = (x | 1);
      cout << e[y].to << " " << e[x].to << endl;
    }
  }
  return 0;
}
