#include <bits/stdc++.h>
using namespace std;
int n, m, d;
bool seen[100010];
int dist[100010][2];
int marked[100010];
vector<int> V[100010];
void dfs(int id, int l, int k) {
  dist[id][k] = l;
  seen[id] = true;
  for (int i = 0; i < ((int)(V[id]).size()); i++)
    if (!seen[V[id][i]]) dfs(V[id][i], l + 1, k);
}
int getMax(int k) {
  int mmax = -1;
  for (int i = 0; i < m; i++)
    if (mmax == -1 || dist[marked[i]][k] > dist[mmax][k]) mmax = marked[i];
  return mmax;
}
void solve() {
  int id;
  memset(seen, false, sizeof(seen));
  dfs(0, 0, 0);
  id = getMax(0);
  memset(seen, false, sizeof(seen));
  dfs(id, 0, 0);
  id = getMax(0);
  memset(seen, false, sizeof(seen));
  dfs(id, 0, 1);
}
int main(int argc, char** argv) {
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) cin >> marked[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    V[u].push_back(v);
    V[v].push_back(u);
  }
  solve();
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (dist[i][0] <= d && dist[i][1] <= d) ans++;
  cout << ans << endl;
  return 0;
}
