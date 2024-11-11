#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--, b--;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int aa, bb;
      cin >> aa >> bb;
      aa--, bb--;
      g[aa].push_back(bb);
      g[bb].push_back(aa);
    }
    bool alicewin = 0;
    if (db <= da) alicewin = 1;
    vector<int> d(n, -1);
    function<void(int)> dfs = [&](int x) {
      for (auto u : g[x])
        if (d[u] == -1) {
          d[u] = d[x] + 1;
          dfs(u);
        }
    };
    d[0] = 0;
    dfs(0);
    int maxpos = -1, dmax = -1;
    for (int i = 0; i < n; i++)
      if (d[i] > dmax) {
        maxpos = i;
        dmax = d[i];
      }
    for (auto& u : d) u = -1;
    d[maxpos] = 0;
    dfs(maxpos);
    int diameter = *max_element(d.begin(), d.end());
    for (auto& u : d) u = -1;
    d[a] = 0;
    dfs(a);
    if (d[b] <= da) alicewin = 1;
    if ((diameter + 1) / 2 <= da) alicewin = 1;
    cout << (alicewin ? "Alice" : "Bob") << '\n';
  }
  return 0;
}
