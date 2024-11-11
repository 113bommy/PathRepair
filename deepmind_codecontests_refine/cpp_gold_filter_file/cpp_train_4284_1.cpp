#include <bits/stdc++.h>
using namespace std;
class dsu {
  vector<long long int> parent, rank;
  long long int totalComponents;

 public:
  dsu(long long int n) {
    parent.resize(n);
    rank.resize(n);
    for (long long int i = 0; i < n; i++) parent[i] = i, rank[i] = 0;
    totalComponents = n;
  }
  long long int get(long long int a) {
    if (a == parent[a]) return a;
    return parent[a] = get(parent[a]);
  }
  void union_set(long long int a, long long int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
      if (rank[a] < rank[b]) swap(a, b);
      parent[b] = a;
      if (rank[a] == rank[b]) rank[a]++;
      totalComponents--;
    }
  }
};
vector<pair<long long int, long long int> > edges;
vector<long long int> adjList[3004];
long long int depth[3004] = {0};
bool KyaNodeAlreadyVisitedHai[3004] = {0};
bool visited[3004] = {0};
bool KyaCycleHai = false;
void FindDepth(long long int node) {
  if (visited[node]) return;
  if (KyaCycleHai) return;
  if (KyaNodeAlreadyVisitedHai[node]) {
    KyaCycleHai = true;
    return;
  }
  KyaNodeAlreadyVisitedHai[node] = true;
  long long int d = 0;
  for (auto children : adjList[node]) {
    FindDepth(children);
    d = max(d, depth[children]);
  }
  depth[node] = d + 1;
  KyaNodeAlreadyVisitedHai[node] = false;
  visited[node] = true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  dsu g(n + m);
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      if (ch == '=')
        g.union_set(i, n + j);
      else if (ch == '>')
        edges.push_back({i, n + j});
      else
        edges.push_back({n + j, i});
    }
  }
  for (auto e : edges) adjList[g.get(e.first)].push_back(g.get(e.second));
  for (long long int i = 0; i < n + m; i++) {
    if (!visited[g.get(i)]) {
      FindDepth(g.get(i));
    }
  }
  if (KyaCycleHai) {
    cout << "No";
  } else {
    cout << "Yes" << endl;
    for (long long int i = 0; i < n; i++) cout << depth[g.get(i)] << ' ';
    cout << endl;
    for (long long int j = 0; j < m; j++) cout << depth[g.get(n + j)] << ' ';
    cout << endl;
  }
  return 0;
}
