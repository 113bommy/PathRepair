#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 9;
int n, dist[2][MAX], parent[MAX];
vector<int> adj[MAX];
void Dfs(int id, int currentNode, int parentNode) {
  for (int childNode : adj[currentNode]) {
    if (childNode != parentNode) {
      parent[childNode] = currentNode;
      dist[id][childNode] = dist[id][currentNode] + 1;
      Dfs(id, childNode, currentNode);
    }
  }
}
int GetFarthestNode(int id) {
  pair<int, int> best = {-1, -1};
  for (int i = 1; i <= n; ++i) {
    best = max(best, make_pair(dist[id][i], i));
  }
  return best.second;
}
vector<int> GetTreeDiameter() {
  Dfs(0, 1, -1);
  int firstNode = GetFarthestNode(0);
  parent[firstNode] = -1;
  Dfs(1, firstNode, -1);
  vector<int> diameter;
  int secondNode = GetFarthestNode(1);
  for (int currentNode = secondNode; currentNode != -1;
       diameter.push_back(currentNode), currentNode = parent[currentNode])
    ;
  dist[0][secondNode] = 0;
  Dfs(0, secondNode, -1);
  return diameter;
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> diameter = GetTreeDiameter();
  vector<bool> visited(n + 1);
  stack<pair<int, int> > stk;
  long long answer = 0;
  queue<int> q;
  for_each(diameter.begin(), diameter.end(),
           [&visited](int node) { visited[node] = true; });
  for (int i = 0; i < diameter.size(); ++i) {
    int node = diameter[i];
    answer += dist[1][node];
    if (i) {
      stk.push({diameter[0], node});
    }
    for (int child : adj[node]) {
      if (!visited[child]) {
        q.push(child);
        visited[child] = true;
      }
    }
  }
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    pair<int, int> best = max(make_pair(dist[0][node], diameter.back()),
                              make_pair(dist[1][node], diameter[0]));
    stk.push({best.second, node});
    answer += best.first;
    for (int child : adj[node]) {
      if (!visited[child]) {
        q.push(child);
        visited[child] = true;
      }
    }
  }
  cout << answer << "\n";
  while (!stk.empty()) {
    cout << stk.top().first << " " << stk.top().second << " "
         << stk.top().second << "\n";
    stk.pop();
  }
  return 0;
}
