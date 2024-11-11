#include <bits/stdc++.h>
using namespace std;
const int N = 111111;
vector<int> g[N];
bool s[N], f[N], used[N], foo[N], bar[N];
int q[N], qb, qe;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n; i++) cin >> f[i];
  vector<int> x;
  q[qe++] = 1;
  used[1] = true;
  if (s[1] != f[1]) {
    x.push_back(1);
    foo[1] = 1;
  }
  while (qb < qe) {
    int u = q[qb++];
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (used[v]) continue;
      q[qe++] = v;
      used[v] = true;
      if ((s[v] ^ bar[u]) != f[v]) {
        x.push_back(v);
        foo[v] = bar[u] ^ 1;
        bar[v] = foo[u];
      } else {
        foo[v] = bar[u];
        bar[v] = foo[u];
      }
    }
  }
  cout << x.size() << endl;
  for (int i = 0; i < x.size(); i++) cout << x[i] << endl;
}
