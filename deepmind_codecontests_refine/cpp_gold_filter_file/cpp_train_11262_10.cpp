#include <bits/stdc++.h>
using namespace std;
int n, m, q;
long long in[100012], out[100012];
long long res = 0;
vector<int> g[100012];
void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    in[u]++;
    out[v]++;
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    res += in[i] * out[i];
  }
  cout << res << "\n";
}
int main() {
  input();
  cin >> q;
  while (q--) {
    int v;
    cin >> v;
    res -= in[v] * out[v];
    out[v] += in[v];
    in[v] = 0;
    for (int u : g[v]) {
      res -= in[u] * out[u];
      in[u]++;
      out[u]--;
      res += in[u] * out[u];
      g[u].push_back(v);
    }
    g[v].clear();
    g[v].shrink_to_fit();
    cout << res << "\n";
  }
  return 0;
}
