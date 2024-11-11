#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> gr[n + 1];
  for (long long i = 1; i <= m; i++) {
    long long u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  vector<long long> v[n + 1];
  long long colour_graph[n + 1];
  for (long long i = 1; i <= n; i++) {
    long long colour;
    cin >> colour;
    colour_graph[i] = colour;
    v[colour].push_back(i);
  }
  long long flag = 0;
  vector<long long> result;
  for (long long i = 1; i <= m; i++) {
    for (auto nodes : v[i]) {
      set<long long> s;
      for (auto neigh : gr[nodes]) {
        if (colour_graph[neigh] < colour_graph[nodes]) {
          s.insert(colour_graph[neigh]);
        }
        if (colour_graph[neigh] == colour_graph[nodes]) {
          flag = 1;
          break;
        }
      }
      if (s.size() != colour_graph[nodes] - 1) {
        flag = 1;
        break;
      }
      result.push_back(nodes);
    }
  }
  if (flag == 1) {
    cout << "-1"
         << "\n";
  } else {
    for (long long i = 0; i < result.size(); i++) {
      cout << result[i] << " ";
    }
  }
  return 0;
}
