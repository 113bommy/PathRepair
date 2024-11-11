#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, visit[150010], cnt, nodes, edge;
vector<int> adj[150010];
map<pair<int, int>, int> mps;
void dfs(int cur) {
  if (visit[cur]) return;
  visit[cur] = true;
  nodes++;
  for (int i = 0; i < adj[cur].size(); i++) {
    if (mps[make_pair(cur, adj[cur][i])]) continue;
    mps[make_pair(cur, adj[cur][i])] = mps[make_pair(adj[cur][i], cur)] = 1;
    edge++;
    dfs(adj[cur][i]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!visit[i]) {
      nodes = 0;
      edge = 0;
      dfs(i);
      nodes = (nodes) * (nodes - 1) / 2;
      if (nodes != edge) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
