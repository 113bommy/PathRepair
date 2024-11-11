#include <bits/stdc++.h>
using namespace std;
const int N = 500500;
using pii = pair<int, int>;
set<pii> s[N];
int parent[N];
int w[N];
pii edge[N];
pii request[N];
int destroy[N];
int active[N];
int n, m, q;
int ex[N];
int ey[N];
int iii;
int get_parent(int x) {
  while (x != parent[x]) {
    x = parent[x];
  }
  return x;
}
int unite(int x, int y) {
  x = get_parent(x);
  y = get_parent(y);
  if (x == y) return 0;
  if (w[x] < w[y]) swap(x, y);
  ex[iii] = x;
  ey[iii] = y;
  parent[y] = x;
  w[x] += w[y];
  for (auto q : s[y]) {
    s[x].insert({q.first, y});
  }
  return 1;
}
void update_parent(int v, int x, int from) {
  if (parent[v] != v) {
    update_parent(parent[v], x, v);
  }
  s[v].erase({x, from});
}
void dbg() {
  cout << "OK" << endl;
  for (int i = 1; i <= n; ++i) {
    cout << "i=" << i << " parent=" << parent[i] << " w=" << w[i] << "   ... ";
    for (auto q : s[i]) cout << "(" << q.first << "," << q.second << ") ";
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    parent[i] = i;
    w[i] = 1;
    s[i].insert({-x, i});
  }
  for (int i = 1; i <= m; ++i) {
    cin >> edge[i].first >> edge[i].second;
  }
  for (int i = 1; i <= q; ++i) {
    cin >> request[i].first >> request[i].second;
    if (request[i].first == 2) {
      destroy[request[i].second] = true;
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (destroy[i]) continue;
    unite(edge[i].first, edge[i].second);
  }
  for (int i = q; i >= 1; --i) {
    if (request[i].first == 2) {
      int v = request[i].second;
      iii = v;
      if (unite(edge[v].first, edge[v].second)) active[i] = true;
    }
  }
  for (int i = 1; i <= q; ++i) {
    if (request[i].first == 2) {
      int index = request[i].second;
      if (!active[index]) continue;
      int x = ex[index];
      int y = ey[index];
      for (auto q : s[y]) {
        update_parent(x, q.first, y);
      }
      parent[y] = y;
      continue;
    }
    int v = request[i].second;
    v = get_parent(v);
    if (s[v].size() == 0) {
      cout << 0 << "\n";
      continue;
    }
    auto it = s[v].begin();
    cout << -it->first << "\n";
    while (it->second != v) {
      int vn = it->second;
      s[v].erase(it);
      v = vn;
      it = s[v].begin();
      if (it == s[v].end()) {
        cout << "Fuck!" << endl;
        return 0;
      }
    }
    s[v].erase(it);
  }
  return 0;
}
