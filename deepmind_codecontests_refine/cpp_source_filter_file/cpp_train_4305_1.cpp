#include <bits/stdc++.h>
using namespace std;
int parent[500001];
int size[500001];
vector<vector<int> > neighbours;
int get_parent(int i) {
  if (parent[i] == i)
    return i;
  else
    return parent[i] = get_parent(parent[i]);
}
bool merge(int a, int b) {
  int parent_a = get_parent(a);
  int parent_b = get_parent(b);
  if (parent_a == parent_b) return false;
  if (size[parent_a] > size[parent_b]) {
    parent[parent_b] = parent_a;
    size[parent_a] += size[parent_b];
  } else {
    parent[parent_a] = parent_b;
    size[parent_b] += size[parent_a];
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> temp;
  for (int i = 0; i <= n; i++) {
    neighbours.push_back(temp);
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a < b) {
      neighbours[b].push_back(a);
    } else {
      neighbours[a].push_back(b);
    }
  }
  for (int i = 1; i <= 100000; i++) {
    parent[i] = i;
    size[i] = 1;
  }
  set<int> components;
  for (int i = 1; i <= n; i++) {
    map<int, int> edges_with_components;
    for (int j = 0; j < neighbours[i].size(); j++) {
      int vertex = neighbours[i][j];
      int parent_of_vertex = get_parent(vertex);
      edges_with_components[parent_of_vertex]++;
    }
    map<int, int>::iterator it = edges_with_components.begin();
    map<int, bool> merged_with_components;
    for (set<int>::iterator it = components.begin(); it != components.end();
         it++) {
      int parent = get_parent(*it);
      int size_of_parent = size[parent];
      int edges_with_parent_component = edges_with_components[parent];
      if (edges_with_parent_component < size_of_parent) {
        merge(i, parent);
        merged_with_components[parent] = true;
      }
    }
    if (merged_with_components.size() == 0) {
      components.insert(i);
    } else if (merged_with_components.size() == 1) {
      continue;
    } else {
      int max_size = -1;
      int max_component = -1;
      for (map<int, bool>::iterator it = merged_with_components.begin();
           it != merged_with_components.end(); it++) {
        if (size[it->first] > max_size) {
          max_size = size[it->first];
          max_component = it->first;
        }
      }
      for (map<int, bool>::iterator it = merged_with_components.begin();
           it != merged_with_components.end(); it++) {
        if (it->first != max_component) {
          components.erase(it->first);
        }
      }
    }
  }
  map<int, bool> present;
  for (int i = 1; i <= n; i++) {
    present[get_parent(i)] = true;
  }
  cout << present.size() << endl;
  map<int, vector<int> > connected_components;
  for (int i = 1; i <= n; i++) {
    connected_components[parent[i]].push_back(i);
  }
  for (map<int, vector<int> >::iterator it = connected_components.begin();
       it != connected_components.end(); it++) {
    cout << it->second.size() << " ";
    for (int i = 0; i < it->second.size(); i++) {
      cout << it->second[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
