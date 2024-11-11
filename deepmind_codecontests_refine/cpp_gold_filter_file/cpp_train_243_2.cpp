#include <bits/stdc++.h>
using namespace std;
long long int nodes_size;
long long int edge_size;
class edge {
 public:
  long long int node;
  long long int cost;
  edge(long long int i, long long int j) {
    node = i;
    cost = j;
  }
};
class graph {
 public:
  long long int node;
  vector<edge> edges;
  long long int parent;
  long long int cost;
  vector<long long int> children;
} nodes[1005];
long long int visited[1005];
class point {
 public:
  long long int x;
  long long int y;
  point() {}
  point(long long int i, long long int j) {
    x = i;
    y = j;
  }
};
void fill_array(long long int ar[], long long int value, long long int size) {
  for (long long int i = 0; i < size; i++) ar[i] = value;
}
void print_ll_vector(vector<long long int> v) {
  for (long long int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
void input_graph(bool is_undirected, bool is_cost) {
  cin >> nodes_size;
  edge_size = nodes_size - 1;
  for (long long int i = 0; i < edge_size; i++) {
    long long int a, b, c;
    cin >> a >> b;
    if (is_cost) {
      cin >> c;
      nodes[a].edges.push_back(edge(b, c));
      if (is_undirected) nodes[b].edges.push_back(edge(a, c));
    } else {
      nodes[a].edges.push_back(edge(b, 1));
      if (is_undirected) nodes[b].edges.push_back(edge(a, 1));
    }
  }
}
vector<pair<long long int, long long int> > destroyed_edges;
long long int ctr = 0, c;
vector<long long int> ans;
void dfs(long long int node, long long int parent) {
  visited[node] = 1;
  for (long long int i = 0; i < nodes[node].edges.size(); i++) {
    if (nodes[node].edges[i].node != parent) {
      if (visited[nodes[node].edges[i].node]) {
        if (node > nodes[node].edges[i].node) {
          if (c > 0 || ctr == 1) {
            destroyed_edges.push_back(
                make_pair(node, nodes[node].edges[i].node));
            c++;
          } else {
            c++;
            ans.push_back(node);
            ans.push_back(nodes[node].edges[i].node);
          }
        }
      } else
        dfs(nodes[node].edges[i].node, node);
    }
  }
}
vector<long long int> new_edges;
int main() {
  input_graph(true, false);
  fill_array(visited, 0, nodes_size + 1);
  for (long long int i = 1; i <= nodes_size; i++) {
    if (!visited[i]) {
      c = 0;
      ctr++;
      dfs(i, -1);
      if (c == 0 && i != 1) new_edges.push_back(i);
    }
  }
  cout << (ans.size() / 2) + new_edges.size() << endl;
  for (long long int i = 0; i < ans.size();) {
    cout << ans[i] << " " << ans[i + 1] << " " << ans[i] << " " << 1 << endl;
    i = i + 2;
  }
  for (long long int i = 0; i < new_edges.size(); i++)
    cout << destroyed_edges[i].first << " " << destroyed_edges[i].second << " "
         << destroyed_edges[i].first << " " << new_edges[i] << endl;
  return 0;
}
