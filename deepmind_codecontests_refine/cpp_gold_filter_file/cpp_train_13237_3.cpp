#include <bits/stdc++.h>
using namespace std;
const long long SZ = 1e6 + 100, INF = 1e9 * 1e9 + 100, MOD = 1e9 + 7, K = 510;
long long n, m, c, q;
map<pair<long long, long long>, long long> ind;
long long par[SZ];
set<long long> st[SZ];
long long find(long long v) {
  if (par[v] == v)
    return v;
  else
    return par[v] = find(par[v]);
}
void uni(int v, int u) {
  v = find(v);
  u = find(u);
  if (v != u) {
    if (st[v].size() > st[u].size()) {
      swap(v, u);
    }
    par[v] = u;
    for (auto c : st[v]) {
      st[u].insert(c);
    }
    st[v].clear();
  }
}
void create(int v, int c) {
  if (ind.find({v, c}) != ind.end()) return;
  long long k = ind.size();
  ind[{v, c}] = k;
  par[k] = k;
  if (c == 0) {
    st[k].insert(v);
  }
}
void add(int v, int u, int c) {
  create(v, c);
  create(u, c);
  uni(ind[{v, c}], ind[{u, 0}]);
  uni(ind[{u, c}], ind[{v, 0}]);
  st[find(v)].insert(u);
  st[find(u)].insert(v);
}
bool ask(int v, int u) {
  v = find(v);
  if (v == find(u) || st[v].find(u) != st[v].end()) {
    return true;
  }
  return false;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  cin >> n >> m >> c >> q;
  for (int i = 0; i < n; i++) {
    create(i, 0);
  }
  for (int i = 0; i < m; i++) {
    long long u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;
    add(u, v, c);
  }
  while (q--) {
    char t;
    cin >> t;
    if (t == '+') {
      long long u, v, c;
      cin >> u >> v >> c;
      u--;
      v--;
      add(v, u, c);
    } else {
      long long u, v;
      cin >> u >> v;
      u--;
      v--;
      if (ask(u, v)) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
  return 0;
}
