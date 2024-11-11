#include <bits/stdc++.h>
using namespace std;
int dfs(int marker[], vector<int> graph[], int vertex, int helper[]) {
  int x = 0;
  for (auto iter = graph[vertex].begin(); iter != graph[vertex].end(); iter++) {
    x = dfs(marker, graph, *iter, helper);
    helper[vertex] = x || helper[vertex];
  }
  helper[vertex] = helper[vertex] || x || marker[vertex];
  if (marker[vertex]) return 1;
  return 0;
}
void printVertex(vector<int> graph[], int helper[], int vertex) {
  if (!helper[vertex]) cout << vertex << " ";
  for (auto iter = graph[vertex].begin(); iter != graph[vertex].end(); iter++) {
    printVertex(graph, helper, *iter);
  }
}
int main() {
  int num_nodes, pi, ci, root;
  cin >> num_nodes;
  int marker[num_nodes + 1], helper[num_nodes + 1];
  for (int i = 0; i <= num_nodes; i++) helper[i] = 0;
  vector<int> graph[num_nodes + 1];
  for (int i = 1; i <= num_nodes; i++) {
    cin >> pi >> ci;
    if (pi == -1) root = i;
    if (pi != -1) graph[pi].push_back(i);
    marker[i] = !ci;
  }
  dfs(marker, graph, root, helper);
  int flag = 1;
  for (int i = 1; i <= num_nodes; i++)
    if (!helper[i]) {
      cout << i << " ";
      flag = 0;
    }
  if (flag) cout << "-1";
  return 0;
}
