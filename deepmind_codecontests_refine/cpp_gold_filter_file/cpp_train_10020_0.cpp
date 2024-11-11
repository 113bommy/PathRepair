#include <bits/stdc++.h>
using namespace std;
vector<int> edges[1111];
int counts[1111];
int dfs(int par, int u) {
  int nv = 1;
  for (int v : edges[u]) {
    if (v == par) continue;
    nv += dfs(u, v);
  }
  counts[u] = nv;
  return nv;
}
string Solve(const vector<int>& A) {
  if (A.size() <= 1) return "Ayush";
  int ct = 0;
  for (int a : A) {
    ct += a;
  }
  if (ct % 2 == 0) {
    return "Ashish";
  } else {
    return "Ayush";
  }
  return "";
}
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
      edges[i].clear();
      counts[i] = 0;
    }
    for (int j = 1; j <= n - 1; j++) {
      int u, v;
      cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    dfs(-1, x);
    vector<int> A;
    for (int u : edges[x]) {
      A.push_back(counts[u]);
    }
    cout << Solve(A) << endl;
  }
}
