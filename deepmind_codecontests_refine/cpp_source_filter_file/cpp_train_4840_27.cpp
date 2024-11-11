#include <bits/stdc++.h>
using namespace std;
void DFSTraversal(vector<vector<int> > &graph, int node);
vector<int> results;
int visited[100];
int main() {
  vector<vector<int> > graph;
  int n, temp;
  cin >> n;
  graph.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> temp;
      if (temp == 1 || temp == 3) {
        graph[i].push_back(j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) DFSTraversal(graph, i);
  }
  int x = results.size();
  sort(results.begin(), results.begin() + x);
  cout << results.size() << "\n";
  for (int i = 0; i < results.size(); i++) {
    cout << results[i] << " ";
  }
  return 0;
}
void DFSTraversal(vector<vector<int> > &graph, int node) {
  visited[node] = 1;
  if (graph[node].size() == 0) {
    results.push_back(node);
    return;
  }
  for (int i = 0; i < graph[node].size(); i++) {
    if (visited[graph[node][i]] == 0) DFSTraversal(graph, graph[node][i]);
  }
}
