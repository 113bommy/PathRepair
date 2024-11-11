#include <bits/stdc++.h>
using namespace std;
void solve(int *arr, int size, int resta, vector<vector<int>> &nodes) {
  if (size == 1) {
    int V = arr[0] + 1 - resta;
    nodes.assign(V, vector<int>());
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (i != j) {
          nodes[i].push_back(j);
        }
      }
    }
  } else if (size == 2) {
    int V = arr[1] + 1 - resta;
    int d1 = arr[0] - resta;
    nodes.assign(V, vector<int>());
    for (int i = 0; i < d1; i++) {
      for (int j = 0; j < V; j++) {
        if (i != j) {
          nodes[i].push_back(j);
        }
      }
    }
  } else {
    int d1 = arr[0] - resta;
    int V = arr[size - 1] + 1 - resta;
    int aislados = arr[size - 1] - arr[size - 2];
    solve(arr + 1, size - 2, resta + d1, nodes);
    for (int i = 0; i < aislados; i++) {
      nodes.push_back(vector<int>());
    }
    int begin_all_connected = nodes.size();
    for (int i = 0; i < d1; i++) {
      nodes.push_back(vector<int>());
    }
    for (int i = begin_all_connected; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (i != j) {
          nodes[i].push_back(j);
        }
      }
    }
    for (int i = 0; i < begin_all_connected; i++) {
      for (int j = begin_all_connected; j < V; j++) {
        nodes[i].push_back(j);
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  int d[1005];
  for (int i = 0; i < n; i++) cin >> d[i];
  vector<vector<int>> nodes;
  solve(d, n, 0, nodes);
  vector<pair<int, int>> edges;
  for (int i = 0; i < nodes.size(); i++) {
    for (int j = 0; j < nodes[i].size(); j++) {
      if (nodes[i][j] > i) {
        edges.push_back(pair<int, int>(i + 1, nodes[i][j] + 1));
      }
    }
  }
  cout << edges.size() << '\n';
  for (int i = 0; i < edges.size(); i++) {
    cout << edges[i].first << ' ' << edges[i].second << '\n';
  }
}
