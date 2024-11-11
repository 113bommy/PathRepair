#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int> > suka;
vector<int> colour;
void dfs(int vertex, int last, int c) {
  colour[vertex] = c;
  for (int i = 0; i < suka[vertex].size(); ++i) {
    int to = suka[vertex][i];
    if (to == last) continue;
    dfs(to, vertex, 3 - c);
  }
}
int mx = -1, W = -1;
void dfs2(int vertex, int last, int d) {
  if (d > mx) {
    mx = d, W = vertex;
  }
  for (int i = 0; i < suka[vertex].size(); ++i) {
    int to = suka[vertex][i];
    if (to == last) continue;
    dfs2(to, vertex, d + 1);
  }
}
vector<int> path;
void dfs3(int vertex, int target, int last, vector<int> &p) {
  p.push_back(vertex);
  if (target == vertex) path = p;
  for (int i = 0; i < suka[vertex].size(); ++i) {
    int to = suka[vertex][i];
    if (to == last) continue;
    dfs3(to, target, vertex, p);
  }
  p.pop_back();
}
vector<bool> in_path;
void dfs4(int vertex, int last, int d) {
  mx = max(mx, d);
  for (int i = 0; i < suka[vertex].size(); ++i) {
    int to = suka[vertex][i];
    if (to == last) continue;
    dfs4(to, vertex, d + 1);
  }
}
void dfs5(int vertex, int last, int cur, int q) {
  colour[vertex] = ((cur % k) + k) % k;
  for (int i = 0; i < suka[vertex].size(); ++i) {
    int to = suka[vertex][i];
    if (to == last) continue;
    dfs5(to, vertex, cur + q, q);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  suka.assign(n, {});
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    suka[u].push_back(v);
    suka[v].push_back(u);
  }
  colour.assign(n, -1);
  if (k == 2) {
    cout << "Yes\n";
    dfs(0, -1, 1);
    for (int i = 0; i < n; i++) cout << colour[i] << " ";
    return 0;
  }
  dfs2(0, -1, 0);
  int good = W;
  W = -1, mx = -1;
  dfs2(good, -1, 0);
  vector<int> K;
  dfs3(good, W, -1, K);
  if (path.size() < k) {
    cout << "Yes\n";
    for (int i = 0; i < n; i++) cout << 1 << " ";
    return 0;
  }
  in_path.assign(n, false);
  for (int i = 0; i < path.size(); ++i) {
    colour[path[i]] = i % k;
    in_path[path[i]] = true;
  }
  for (int i = 0; i < path.size(); ++i) {
    mx = -1;
    int vertex = path[i];
    for (int j = 0; j < suka[vertex].size(); ++j) {
      int to = suka[vertex][j];
      if (in_path[to]) continue;
      dfs4(to, vertex, 1);
    }
    int A = i + 1, B = path.size() - i;
    if (mx + A >= k && mx + B >= k) {
      cout << "No";
      return 0;
    }
  }
  for (int i = 0; i < path.size(); ++i) {
    int tut = i % k;
    int vertex = path[i];
    for (int j = 0; j < suka[vertex].size(); j++) {
      int to = suka[vertex][j];
      if (in_path[to]) continue;
      if (i < path.size() / 2) {
        dfs5(to, vertex, tut - 1, -1);
      } else
        dfs5(to, vertex, tut + 1, 1);
    }
  }
  cout << "Yes\n";
  for (int i = 0; i < n; ++i) cout << colour[i] + 1 << " ";
}
