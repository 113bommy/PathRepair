#include <bits/stdc++.h>
using namespace std;
const int N = 2000 * 1000 + 2;
int n, m, k, x, y, cnt, t, sum;
vector<int> adj[N];
bool vis[N];
void dfs(int v) {
  cnt++;
  vis[v] = 1;
  for (int i = 0; i < (int((adj[v]).size())); i++)
    if (!vis[adj[v][i]]) dfs(adj[v][i]);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      t++;
      cnt = 0;
      dfs(i);
      sum += min(k, cnt);
    }
  printf("%d", (k > 1) ? max(t - 1 - (sum / 2), 0) : (t - 2));
  return 0;
}
