#include <bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<int> odd;
vector<int> ans;
void visit(int x) {
  ans.push_back(x);
  odd[x] ^= 1;
}
void dfs(vector<vector<int> > &graph, int x) {
  vis[x] = 1;
  visit(x);
  for (int i = 0; i < graph[x].size(); i++) {
    if (vis[graph[x][i]]) continue;
    dfs(graph, graph[x][i]);
    visit(x);
    if (odd[graph[x][i]]) {
      visit(graph[x][i]);
      visit(x);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > graph(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u - 1].push_back(v - 1);
    graph[v - 1].push_back(u - 1);
  }
  int head = 0;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    vis.push_back(0);
    odd.push_back(temp);
    if (temp && head == 0) {
      head = i;
    }
  }
  dfs(graph, head);
  if (odd[head]) {
    ans.pop_back();
    odd[head] = 0;
  }
  for (int i = 0; i < n; i++)
    if (odd[i]) {
      cout << -1;
      return 0;
    }
  cout << ans.size() << endl;
  if (ans.size() == 0) {
    return 0;
  }
  for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] + 1 << " ";
  cout << ans[ans.size() - 1] + 1;
  return 0;
}
