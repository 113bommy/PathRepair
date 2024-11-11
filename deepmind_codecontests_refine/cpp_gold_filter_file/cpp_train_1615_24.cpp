#include <bits/stdc++.h>
using namespace std;
const int maxn = 123456 + 10;
int n, m;
bool mark[maxn];
int dis[maxn], size[maxn];
vector<int> vertex[maxn];
void dfs(int root, int par) {
  size[root] = 0;
  if (mark[root]) size[root] = 1;
  for (int i = 0; i < ((int(vertex[root].size()))); i++) {
    int adj = vertex[root][i];
    if (adj == par) continue;
    dis[adj] = dis[root] + 1;
    dfs(adj, root);
    size[root] += size[adj];
  }
  return;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    vertex[u].push_back(v);
    vertex[v].push_back(u);
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    x--;
    mark[x] = true;
  }
  dfs(0, -1);
  int D1 = -1, D2 = maxn;
  for (int i = 0; i < n; i++)
    if (mark[i] && (D1 == -1 || dis[D1] < dis[i])) D1 = i;
  memset(dis, 0, sizeof dis);
  dfs(D1, -1);
  int ans = 0, max_dis = 0;
  for (int i = 0; i < n; i++) {
    if (size[i] > 0 && i != D1) ans++;
    if (mark[i]) max_dis = max(max_dis, dis[i]);
  }
  for (int i = 0; i < n; i++) {
    if (mark[i] && dis[i] == max_dis) {
      D2 = i;
      break;
    }
  }
  cout << min(D1, D2) + 1 << endl << 2 * ans - max_dis << endl;
  return 0;
}
