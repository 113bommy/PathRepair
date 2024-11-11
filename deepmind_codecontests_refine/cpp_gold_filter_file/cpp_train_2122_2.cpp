#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int cnt1 = 0;
bool present[105] = {false};
class Graph {
  int V;
  list<int> *adj;
  void DFSUtil(int v, bool visited[]);

 public:
  Graph(int V);
  void addEdge(int v, int w);
  void DFS();
};
Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}
void Graph::addEdge(int v, int w) { adj[v].push_back(w); }
void Graph::DFSUtil(int v, bool visited[]) {
  visited[v] = true;
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i]) DFSUtil(*i, visited);
}
void Graph::DFS() {
  bool *visited = new bool[V];
  for (int i = 1; i < V; i++) visited[i] = false;
  for (int i = 1; i < V; i++) {
    if (!visited[i] && present[i] == true) {
      cnt++;
      DFSUtil(i, visited);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  Graph g(m + 1);
  int prev, p, a;
  for (int i = 0; i < n; i++) {
    cin >> p;
    if (p == 0)
      cnt1++;
    else if (p == 1) {
      cin >> a;
      present[a] = true;
      g.addEdge(a, a);
    } else {
      cin >> prev;
      p -= 1;
      while (p--) {
        cin >> a;
        present[prev] = true;
        present[a] = true;
        g.addEdge(prev, a);
        g.addEdge(a, prev);
        prev = a;
      }
    }
  }
  g.DFS();
  if (cnt > 0)
    cout << (cnt - 1) + cnt1;
  else
    cout << cnt1;
}
