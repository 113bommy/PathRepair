#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[100100];
int tin[100100], fup[100100], used[100100], timer = 0;
vector<pair<int, int> > ans;
bool ansex = true;
void dfs(int v, int p) {
  if (!ansex) return;
  used[v] = 1;
  tin[v] = timer++;
  fup[v] = tin[v];
  for (int to : g[v]) {
    if (to == p) continue;
    if (used[to]) {
      fup[v] = min(tin[to], fup[v]);
      if (tin[v] < tin[to]) ans.push_back({to, v});
    } else {
      ans.push_back({v, to});
      dfs(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] > tin[v]) {
        ansex = false;
      }
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < 100100; i++) {
    used[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, -1);
  if (ansex) {
    for (pair<int, int> a : ans) {
      cout << a.first << " " << a.second << endl;
    }
  } else {
    cout << 0;
  }
}
int main() {
  cin.tie(NULL);
  long long q;
  q = 1;
  for (long long i = 0; i < q; i++) {
    solve();
  }
  return 0;
}
