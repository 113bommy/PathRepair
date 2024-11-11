#include <bits/stdc++.h>
using namespace std;
void _read();
const int nax = 2001;
const int inf = 1e9 + 11;
void NO() {
  cout << "NO\n";
  exit(0);
}
int mat[nax][nax];
using tp = tuple<int, int, int>;
struct Solution {
  int n;
  bool in_a[nax];
  vector<vector<pair<int, int>>> adj;
  void inp() {
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> mat[i][j];
        if (i == j && mat[i][j]) NO();
        if (i != j && !mat[i][j]) NO();
      }
    }
  }
  void rec() {
    vector<tuple<int, int, int>> vec;
    for (int i = 2; i <= n; i++) {
      vec.emplace_back(mat[i][1], 1, i);
    }
    sort((vec).begin(), (vec).end(), greater<tp>());
    while (!vec.empty()) {
      auto &[d, u, v] = vec.back();
      adj[u].emplace_back(v, d);
      adj[v].emplace_back(u, d);
      vec.pop_back();
      for (int i = 0; i < ((int)(vec).size()); i++) {
        int a, b, c;
        tie(a, b, c) = vec[i];
        if (mat[v][c] < a) {
          b = c;
          a = mat[v][c];
          vec[i] = {a, b, c};
        }
      }
      sort((vec).begin(), (vec).end(), greater<tp>());
    }
  }
  void bfs(int src) {
    vector<int> dis(n + 1);
    vector<int> q = {src};
    vector<int> vis(n + 1);
    vis[src] = 1;
    dis[src] = 0;
    for (int i = 0; i < ((int)(q).size()); i++) {
      int u = q[i];
      for (auto &[v, w] : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        dis[v] = dis[u] + w;
        q.push_back(v);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (dis[i] != mat[src][i]) NO();
      if (dis[i] != mat[i][src]) NO();
    }
  }
  void check() {
    for (int i = 1; i <= n; i++) {
      bfs(i);
    }
  }
  void test() {
    inp();
    in_a[1] = true;
    rec();
    check();
    cout << "YES\n";
  }
};
int main() {
  _read();
  Solution().test();
  return 0;
};
void _read() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
}
