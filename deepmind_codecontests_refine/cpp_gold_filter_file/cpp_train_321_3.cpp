#include <bits/stdc++.h>
using namespace std;
void dfs(int x, vector<vector<int> > &graph, vector<bool> &is_in_subgraph,
         vector<bool> &used, int &ans) {
  if (used[x]) return;
  used[x] = true;
  if (is_in_subgraph[x]) {
    ans = x;
    return;
  }
  for (int i = 0; i < graph[x].size(); ++i)
    dfs(graph[x][i], graph, is_in_subgraph, used, ans);
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, a, b, k, x, k2;
    cin >> n;
    vector<vector<int> > graph(n);
    for (int i = 0; i < n - 1; ++i) {
      cin >> a >> b;
      --a;
      --b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    cin >> k;
    vector<bool> is_in_subgraph(n);
    for (int i = 0; i < k; ++i) {
      cin >> x;
      --x;
      is_in_subgraph[x] = true;
    }
    cin >> k2;
    set<int> his_subgraph;
    for (int i = 0; i < k2; ++i) {
      cin >> x;
      his_subgraph.insert(x);
    }
    cout << "B " << x << endl;
    cout.flush();
    cin >> x;
    --x;
    vector<bool> used(n);
    int ans = -1;
    dfs(x, graph, is_in_subgraph, used, ans);
    cout << "A " << ans + 1 << endl;
    cout.flush();
    cin >> x;
    if (his_subgraph.find(x) != his_subgraph.end()) {
      cout << "C " << ans + 1 << endl;
      cout.flush();
    } else {
      cout << "C " << -1 << endl;
      cout.flush();
    }
  }
  return 0;
}
