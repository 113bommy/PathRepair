#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> edges;
vector<int> labels[2];
int dfs(int u, int p, int w0, int label) {
  int ret = 1;
  labels[w0][u] = label;
  for (auto it : edges[u])
    if (it.first != p && it.second == w0) {
      ret += dfs(it.first, u, w0, label);
    }
  return ret;
}
int main(int argc, char** argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (argc == 2 && atoi(argv[1]) == 123456789) {
    freopen("d:\\code\\cpp\\stdin", "r", stdin);
  }
  int n;
  cin >> n;
  edges.resize(n + 1);
  labels[0].resize(n + 1);
  labels[1].resize(n + 1);
  for (int(i) = 0; (i) < (n - 1); (i)++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }
  map<int, int> H[2];
  for (int w0 = 0; w0 < 2; w0++) {
    int lbl = 1;
    for (int(u) = 1; (u) <= (n); (u)++)
      if (labels[w0][u] == 0) {
        int cnt = dfs(u, -1, w0, lbl);
        H[w0][lbl] = cnt;
        lbl++;
      }
  }
  long long sol = 0;
  for (int(i) = 1; (i) <= (n); (i)++) {
    long long two = H[0][labels[0][i]] + H[1][labels[1][i]] - 2;
    long long one = (H[0][labels[0][i]] - 1) * (H[1][labels[1][i]] - 1);
    sol += two + one;
  }
  cout << sol << '\n';
  if (argc == 2 && atoi(argv[1]) == 123456789)
    cout << clock() * 1.0 / CLOCKS_PER_SEC << " sec\n";
  return 0;
}
