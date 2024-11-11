#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int n, m;
vector<int> liga[200100];
vector<int> adj[200100];
int state[200100];
int id[200100], sz[200100];
int vis[200200];
vector<int> top;
int find(int x) {
  if (id[x] == x) return x;
  return id[x] = find(id[x]);
}
void join(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  id[b] = a;
  sz[a] += sz[b];
}
void dfs(int v) {
  vis[v] = 1;
  for (auto x : adj[v]) {
    if (vis[x]) continue;
    dfs(x);
  }
  top.push_back(v);
}
void dfs2(int v, int ori) {
  vis[v] = 1;
  for (auto x : adj[v]) {
    if (vis[x]) continue;
    join(ori, x);
    dfs2(x, ori);
  }
}
void add(int a, int b) { adj[a].push_back(b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> state[i];
  for (int i = 1; i <= 2 * m; i++) {
    id[i] = i;
    sz[i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int amt;
    cin >> amt;
    while (amt--) {
      int x;
      cin >> x;
      liga[x].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    int x = liga[i][0];
    int y = liga[i][1];
    if (state[i]) {
      add(2 * x - 1, 2 * y - 1);
      add(2 * y, 2 * x);
      add(2 * y - 1, 2 * x - 1);
      add(2 * x, 2 * y);
    } else {
      add(2 * x, 2 * y - 1);
      add(2 * y, 2 * x - 1);
      add(2 * x - 1, 2 * y);
      add(2 * y - 1, 2 * x);
    }
  }
  for (int i = 1; i <= 2 * m; i++)
    if (!vis[i]) dfs(i);
  reverse(top.begin(), top.end());
  memset(vis, 0, sizeof(vis));
  for (auto x : top)
    if (!vis[x]) dfs2(x, x);
  for (int i = 1; i <= m; i++) {
    if (find(2 * i) == find(2 * i - 1)) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
