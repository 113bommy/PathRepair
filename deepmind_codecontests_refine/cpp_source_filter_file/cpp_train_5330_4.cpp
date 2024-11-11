#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000050], adr[1000050];
int vis[1000050];
int comp[1000050];
vector<int> jury;
vector<int> cat;
vector<int> topSortArr;
void topSort(int i) {
  vis[i] = 1;
  for (int v : adj[i])
    if (!vis[v]) topSort(v);
  topSortArr.push_back(i);
}
void scc_dfs(int i, int c) {
  comp[i] = c;
  vis[i] = 1;
  for (int v : adr[i])
    if (!vis[v]) scc_dfs(v, c);
}
int graphCompress(int n) {
  topSortArr.clear();
  for (int i = 0; i < n; i++) vis[i] = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) topSort(i);
  }
  reverse(topSortArr.begin(), topSortArr.end());
  for (int i = 0; i < n; i++) vis[i] = 0;
  int componentNo = 0;
  for (int i : topSortArr) {
    if (!vis[i]) {
      scc_dfs(i, componentNo);
      componentNo++;
    }
  }
  for (int i = 0; i < n; i++) vis[i] = 0;
  return componentNo;
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (u == v) continue;
    u--;
    v--;
    adj[u].push_back(v);
    adr[v].push_back(u);
  }
  int v = graphCompress(n);
  if (v == 1) {
    cout << "No";
  } else {
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
      if (comp[i] == 0)
        jury.push_back(i);
      else
        cat.push_back(i);
    int js = jury.size();
    int rem = n - js;
    cout << js << " " << rem << "\n";
    for (int i = 0; i < jury.size(); i++) cout << jury[i] + 1 << " ";
    cout << "\n";
    for (int i = 0; i < rem; i++) cout << cat[i] + 1 << " ";
  }
  jury.clear();
  cat.clear();
  for (int i = 0; i < n; i++) {
    vis[i] = 0;
    adj[i].clear();
    adr[i].clear();
    comp[i] = 0;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
