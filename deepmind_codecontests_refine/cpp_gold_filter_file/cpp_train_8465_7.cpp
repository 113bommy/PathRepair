#include <bits/stdc++.h>
using namespace std;
const int p1 = 17239;
const int q1 = 1e9 + 7;
const int p2 = 115249;
const int q2 = 1791791791;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  unordered_map<long long, int> mm;
  int n, m;
  long long hh1, hh2;
  cin >> n >> m;
  vector<int> g[n + 1];
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<long long> pp(n + 1);
  pp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pp[i] = (pp[i - 1] * p2) % q2;
  }
  for (int it = 1; it <= n; ++it) {
    hh1 = 0;
    hh2 = 0;
    for (int fr : g[it]) {
      hh1 = (hh1 + fr) % q1;
      hh2 = (hh2 + pp[fr]) % q2;
    }
    ++mm[(hh1 << 32) + hh2];
    hh1 = (hh1 + it) % q1;
    hh2 = (hh2 + pp[it]) % q2;
    ++mm[(hh1 << 32) + hh2];
  }
  long long ans = 0;
  for (auto it : mm) {
    ans += 1ll * (it.second - 1) * (it.second) / 2;
  }
  cout << ans;
}
