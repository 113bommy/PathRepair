#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, x, y, deg[N], leaf[2];
vector<int> adj[N];
map<int, int> m;
void init() {
  for (int i = 0; i < N; i++) deg[i] = 0;
  leaf[0] = leaf[1] = -1;
}
int dist = -1;
void find_leaf(int u, int p, int depth, int index) {
  if (depth >= dist && deg[u] == 1) {
    leaf[index] = u;
    dist = depth;
  }
  for (int v : adj[u]) {
    if (v == p) continue;
    find_leaf(v, u, depth + 1, index);
  }
}
bool validate(int u, int p = 0, int depth = 1) {
  if (m.find(depth) == m.end()) m[depth] = deg[u];
  if (m.find(depth)->second != deg[u]) return false;
  bool rv = true;
  for (int v : adj[u]) {
    if (v == p) continue;
    rv = rv && validate(v, u, depth + 1);
  }
  return rv;
}
void check(int u) {
  m.clear();
  if (validate(u)) {
    cout << u << endl;
    exit(0);
  }
}
int diameter = -1;
int midPoint = -1;
bool trace(int u, int p = 0, int depth = 1) {
  if (u == leaf[1]) {
    diameter = depth + 1;
    return true;
  }
  for (int v : adj[u]) {
    if (v == p) continue;
    if (trace(v, u, depth + 1)) {
      if (diameter != -1 && diameter / 2 == depth) midPoint = u;
      return true;
    }
  }
  return false;
}
int nearestLeaf = -1;
int nearestLeafDistance = INT_MAX;
void findNearestLeaf(int u, int p = 0, int depth = 1) {
  if (deg[u] == 1 && depth <= nearestLeafDistance) {
    nearestLeafDistance = depth;
    nearestLeaf = u;
  }
  for (int v : adj[u]) {
    if (v == p) continue;
    findNearestLeaf(v, u, depth + 1);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  init();
  cin >> n;
  if (n == 1) {
    cout << "1" << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    deg[x]++;
    deg[y]++;
  }
  dist = -1;
  find_leaf(1, 0, 1, 0);
  dist = -1;
  find_leaf(leaf[0], 0, 1, 1);
  check(leaf[0]);
  check(leaf[1]);
  trace(leaf[0]);
  check(midPoint);
  findNearestLeaf(midPoint);
  check(nearestLeaf);
  cout << "-1" << endl;
  return 0;
}
