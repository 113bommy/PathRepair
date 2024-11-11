#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 * 1000 + 5;
const long long mod = 1000 * 1000 * 1000 + 7;
bool mark[maxN];
vector<int> adj[maxN];
int sz;
void dfs(int x) {
  mark[x] = 1;
  sz++;
  for (int i = 0; i < ((int)(adj[x]).size()); i++) {
    int u = adj[x][i];
    if (!mark[u]) dfs(u);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  long long k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long long comp = 0, ans = 1;
  for (int i = 0; i < n; i++) {
    sz = 0;
    if (!mark[i]) {
      dfs(i);
      comp++;
      ans *= sz;
      ans %= k;
    }
  }
  for (int i = 0; i < comp - 2; i++) ans *= n, ans %= k;
  if (comp == 0) ans = 1;
  cout << ans << endl;
  return 0;
}
