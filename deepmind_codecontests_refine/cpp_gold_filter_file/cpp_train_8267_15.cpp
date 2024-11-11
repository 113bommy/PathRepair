#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool MinPlace(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool MaxPlace(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename S, typename T>
ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
int timer = 1;
vector<int> id(100005, 0);
vector<vector<int>> gr(100005, vector<int>());
vector<vector<pair<int, int>>> triples(100005, vector<pair<int, int>>());
bool dfs(int u, int p = 0) {
  vector<int> left;
  id[u] = timer++;
  for (int v : gr[u]) {
    if (v == p) continue;
    if (!id[v]) {
      if (dfs(v, u)) left.push_back(v);
    } else if (id[v] > id[u])
      left.push_back(v);
  }
  bool use = left.size() & 1;
  if (use) left.push_back(p);
  for (int i = 0; i < left.size(); i += 2)
    triples[u].push_back(make_pair(left[i], left[i + 1]));
  return !use;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  if (m & 1) {
    cout << "No solution";
    return 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++)
    for (auto pp : triples[i])
      cout << pp.first << " " << i << " " << pp.second << "\n";
}
