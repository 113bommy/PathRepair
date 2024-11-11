#include <bits/stdc++.h>
using namespace std;
double PI = 3.141592653589793;
const int mx = 1e5 + 1;
int cnt[mx] = {};
vector<int> adj[mx];
bool com[mx] = {};
void solve() {
  int n, m, hm, tm;
  cin >> n >> m >> hm >> tm;
  vector<int> proc;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    cnt[u]++;
    cnt[v]++;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (cnt[i] > hm) proc.push_back(i);
  }
  for (auto u : proc) {
    for (auto v : adj[u]) {
      if (cnt[v] <= tm) continue;
      int h = hm, t = tm;
      if (cnt[v] > tm + hm) {
        set<int> proc;
        cout << "YES\n" << u + 1 << ' ' << v + 1 << '\n';
        for (int i = 0; i < (int)((adj[u]).size()); i++) {
          if (h == 0) break;
          if (adj[u][i] == v) continue;
          cout << adj[u][i] + 1 << ' ';
          h--;
          proc.insert(adj[u][i]);
        }
        cout << '\n';
        for (int i = 0; i < (int)((adj[v]).size()); i++) {
          if (m == 0) break;
          if (proc.count(adj[v][i]) || adj[v][i] == u) continue;
          cout << adj[v][i] + 1 << ' ';
          m--;
        }
        return;
      }
      if (cnt[u] > tm + hm) {
        set<int> proc;
        cout << "YES\n" << u + 1 << ' ' << v + 1 << '\n';
        vector<int> buf;
        for (int i = 0; i < (int)((adj[v]).size()); i++) {
          if (m == 0) break;
          if (adj[v][i] == u) continue;
          buf.push_back(adj[v][i]);
          m--;
          proc.insert(adj[v][i]);
        }
        for (int i = 0; i < (int)((adj[u]).size()); i++) {
          if (h == 0) break;
          if (proc.count(adj[u][i]) || adj[u][i] == v) continue;
          cout << adj[u][i] + 1 << ' ';
          h--;
        }
        cout << '\n';
        for (auto i : buf) cout << i + 1 << ' ';
        return;
      }
      vector<int> tem;
      for (auto m : adj[u]) {
        if (m == v) continue;
        com[m] = 1;
      }
      for (auto m : adj[v]) {
        if (m == u) continue;
        if (com[m]) tem.push_back(m);
      }
      for (auto m : adj[u]) {
        if (m == v) continue;
        com[m] = 0;
      }
      for (auto m : tem) com[m] = 1;
      int a = cnt[u] - 1 - (int)((tem).size()),
          b = cnt[v] - 1 - (int)((tem).size());
      int k = max(0, hm - a);
      if (b + (int)((tem).size()) - k < tm) continue;
      cout << "YES\n" << u + 1 << ' ' << v + 1 << '\n';
      for (auto m : adj[u]) {
        if (h == 0) break;
        if (m == v || com[m]) continue;
        cout << m + 1 << ' ';
        h--;
      }
      while (h > 0) {
        cout << tem.back() + 1 << ' ';
        tem.pop_back();
        h--;
      }
      cout << '\n';
      for (auto m : adj[v]) {
        if (t == 0) break;
        if (m == u || com[m]) continue;
        cout << m + 1 << ' ';
        t--;
      }
      while (t > 0) {
        cout << tem.back() + 1 << ' ';
        tem.pop_back();
        t--;
      }
      for (auto m : adj[u]) com[m] = 0;
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  for (int c = 1; c < T + 1; c++) {
    solve();
  }
}
