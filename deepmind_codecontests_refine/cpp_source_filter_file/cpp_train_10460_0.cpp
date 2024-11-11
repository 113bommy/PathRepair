#include <bits/stdc++.h>
double eps = 1e-9;
using namespace std;
const int maxn = 100050;
int n, m;
vector<vector<int> > graph;
int up[maxn][20];
int in[maxn], out[maxn];
int timer = 0;
int subtree[maxn], depth[maxn];
bool upper(int a, int b) {
  if (in[b] >= in[a] && out[b] <= out[a]) {
    return true;
  }
  return false;
}
void dfs(int source, int parent, int dep) {
  up[source][0] = parent;
  depth[source] = dep;
  in[source] = ++timer;
  int sum = 0;
  for (int i = 0; i < graph[source].size(); i++) {
    int v = graph[source][i];
    if (v == parent) {
      continue;
    }
    dfs(v, source, dep + 1);
    sum += subtree[v];
  }
  out[source] = ++timer;
  sum++;
  subtree[source] = sum;
}
int lca(int a, int b) {
  if (upper(a, b)) return a;
  if (upper(b, a)) return b;
  for (int i = 19; i >= 0; i--) {
    if (up[i][a] != -1 && !upper(up[i][a], b)) {
      a = up[i][a];
    }
  }
  return up[0][a];
}
int dist(int a, int b) {
  int l = lca(a, b);
  return depth[a] + depth[b] - 2 * depth[l];
}
int ancestor(int a, int k) {
  int ans = a;
  for (int i = 19; i >= 0; i--) {
    if ((1 << i) & k) {
      ans = up[ans][i];
    }
  }
  return ans;
}
void pre() {
  memset(up, -1, sizeof(up));
  dfs(0, -1, 0);
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < n; j++) {
      if (up[j][i - 1] != -1) up[j][i] = up[up[j][i - 1]][i - 1];
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  graph.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }
  pre();
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a == b) {
      cout << n << "\n";
      continue;
    }
    int l = lca(a, b);
    int distance = dist(a, b);
    if (distance % 2 != 0) {
      cout << "0\n";
      continue;
    }
    if (dist(a, l) == dist(b, l)) {
      int j = ancestor(a, dist(a, l) - 1);
      int k = ancestor(b, (dist(b, l) - 1));
      cout << n - subtree[j] - subtree[k] << "\n";
      continue;
    }
    if (depth[a] > depth[b]) {
      int mid = ancestor(a, distance / 2);
      int j = ancestor(a, distance / 2 - 1);
      cout << subtree[mid] - subtree[j] << "\n";
      continue;
    } else {
      int mid = ancestor(b, distance / 2);
      int j = ancestor(b, distance / 2 - 1);
      cout << subtree[mid] - subtree[j] << "\n";
      continue;
    }
  }
  return 0;
}
