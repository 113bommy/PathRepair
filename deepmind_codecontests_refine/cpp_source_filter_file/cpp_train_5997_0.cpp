#include <bits/stdc++.h>
using namespace std;
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
const int MAX = 1e5 + 5;
int lst_req[MAX];
int par[MAX];
vector<int> g[MAX];
int n, m, k, q;
int tin[MAX];
int tout[MAX];
int pool;
int subsz[MAX];
void dfs(int u) {
  subsz[u] = 1;
  tin[u] = ++pool;
  for (auto v : g[u]) {
    dfs(v);
    subsz[u] += subsz[v];
  }
  tout[u] = pool;
}
int main(int argc, char* argv[]) {
  io();
  cin >> n >> m >> k >> q;
  int a, b;
  while (k--) {
    cin >> a >> b;
    if (lst_req[b] != 0) {
      g[lst_req[b]].push_back(a);
      par[a] = lst_req[b];
    }
    lst_req[b] = a;
  }
  for (int i = 1; i <= n; i++) {
    if (par[i] == 0) {
      dfs(i);
    }
  }
  while (q--) {
    cin >> a >> b;
    if (lst_req[b] == 0) {
      cout << 0 << '\n';
    } else {
      int v = lst_req[b];
      if (tin[a] <= tout[v] && tout[v] <= tout[a]) {
        cout << subsz[a] << '\n';
      } else {
        cout << 0 << '\n';
      }
    }
  }
  return 0;
}
