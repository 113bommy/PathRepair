#include <bits/stdc++.h>
using namespace std;
long long value[100005], inc[100005], de[100005];
bool visited[100005];
class Graph {
  long long V;
  list<long long> *adj;

 public:
  Graph(long long V);
  void addEdge(long long v, long long w);
  void DFSUtil(long long v);
};
Graph::Graph(long long V) {
  this->V = V;
  adj = new list<long long>[V];
}
void Graph::addEdge(long long v, long long w) {
  adj[v].push_back(w);
  adj[w].push_back(v);
}
void Graph::DFSUtil(long long v) {
  visited[v] = true;
  list<long long>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i) {
    if (!visited[*i]) {
      DFSUtil(*i);
      inc[v] = max(inc[v], inc[*i]);
      de[v] = max(de[v], de[*i]);
    }
  }
  value[v] = value[v] + inc[v] - de[v];
  if (value[v] > 0)
    inc[v] += abs(value[v]);
  else
    de[v] += abs(value[v]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  Graph g(n);
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    g.addEdge(a, b);
  }
  for (long long i = 0; i < n; i++) {
    cin >> value[i];
  }
  g.DFSUtil(0);
  cout << inc[0] + de[0] << endl;
}
