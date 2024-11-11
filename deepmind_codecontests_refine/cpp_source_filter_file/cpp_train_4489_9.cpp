#include <bits/stdc++.h>
using namespace std;
vector<int> A, AO, R, RE, RO;
vector<vector<int>> E;
void dfs(int u, int p) {
  for (int v : E[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    A[u] += A[v];
    AO[u] += AO[v];
    A[u] += R[v] + RE[v] + RO[v] + 1;
    AO[u] += RE[v] + 1;
    A[u] += R[u] * (RE[v] + RO[v] + 1) +
            (R[v] + RE[v] + RO[v] + 1) * (RE[u] + RO[u]);
    AO[u] += RO[u] * RO[v] + RE[u] * (RE[v] + 1);
    R[u] += R[v] + RE[v] + RO[v] + 1;
    RE[u] += RO[v];
    RO[u] += RE[v] + 1;
  }
}
int main() {
  int n;
  cin >> n;
  E.assign(1 + n, vector<int>());
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  A.assign(1 + n, 0);
  AO.assign(1 + n, 0);
  R.assign(1 + n, 0);
  RE.assign(1 + n, 0);
  RO.assign(1 + n, 0);
  dfs(1, -1);
  cout << (A[1] - AO[1]) / 2 + AO[1] << endl;
  return 0;
}
