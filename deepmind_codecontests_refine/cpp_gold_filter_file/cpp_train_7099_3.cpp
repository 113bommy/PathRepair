#include <bits/stdc++.h>
using namespace std;
class Graph {
 public:
  Graph(int V) {
    this->V = V;
    G.resize(V);
  }
  void addEdge(int v, int w) { G[v].push_back(w); }
  void DFS(int s) {
    bool *visited = new bool[this->V];
    for (int i = 0; i < this->V; i++) visited[i] = false;
    int *arrival = new int[this->V];
    int *departure = new int[this->V];
    int t = 0;
    DFSUtil(s, visited, arrival, departure, t);
    cout << departure[s] / 2 << " ";
  }
  void printGraph() {
    vector<list<int> >::iterator i;
    list<int>::iterator j;
    int k = 0;
    int t = 0;
    for (i = G.begin(); i != G.end(); ++i) {
      cout << "Node " << k++ << "->";
      for (j = G[t].begin(); j != G[t].end(); ++j) cout << *j << "->";
      cout << "NULL\n";
      t++;
    }
  }

 private:
  int V;
  vector<list<int> > G;
  void DFSUtil(int s, bool *visited, int *arrival, int *departure, int &t) {
    visited[s] = true;
    arrival[s] = ++t;
    list<int>::iterator i;
    for (i = G[s].begin(); i != G[s].end(); ++i) {
      if (!visited[*i]) DFSUtil(*i, visited, arrival, departure, t);
    }
    departure[s] = ++t;
  }
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int V;
    cin >> V;
    Graph g(V);
    int arr[V];
    int x;
    for (int y = 0; y < V; y++) {
      cin >> x;
      g.addEdge(y, x - 1);
      arr[x - 1] = y;
    }
    for (int k = 0; k < V; k++) {
      g.DFS(k);
    }
    cout << endl;
  }
  return 0;
}
