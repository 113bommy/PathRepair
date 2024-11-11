#include <bits/stdc++.h>
using namespace std;
const int Q = 3e5 + 5;
vector<pair<int, int>> tree[4 * Q];
long long res[Q], ans = 0;
int cur = 0, par[2 * Q], sizeX[2 * Q], sizeY[2 * Q], val[50 * Q];
int* where[50 * Q];
void update(int idx, int b, int e, int l, int r, pair<int, int> p) {
  if (b == l && r == e) {
    tree[idx].push_back(p);
    return;
  }
  int m = (b + e) / 2;
  if (l < m) update(idx * 2 + 1, b, m, l, min(m, r), p);
  if (r > m) update(idx * 2 + 2, m, e, max(m, l), r, p);
}
void change(int& a, int b) {
  where[cur] = &a;
  val[cur] = a;
  a = b;
  ++cur;
}
int find(int u) { return u == par[u] ? u : find(par[u]); }
void unite(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  ans -= 1LL * sizeX[u] * sizeY[u];
  ans -= 1LL * sizeX[v] * sizeY[v];
  if (sizeX[u] + sizeY[u] < sizeX[v] + sizeY[v]) swap(u, v);
  change(par[v], u);
  change(sizeX[u], sizeX[u] + sizeX[v]);
  change(sizeY[u], sizeY[u] + sizeY[v]);
  ans += 1LL * sizeX[u] * sizeY[u];
}
void rollback() {
  --cur;
  *where[cur] = val[cur];
}
void dfs(int idx, int b, int e) {
  long long lastAns = ans;
  int state = cur;
  for (auto [x, y] : tree[idx]) unite(x * 2, y * 2 + 1);
  if (b + 1 == e) {
    res[b] = ans;
  } else {
    int m = (b + e) / 2;
    dfs(idx * 2 + 1, b, m);
    dfs(idx * 2 + 2, m, e);
  }
  while (cur != state) rollback();
  ans = lastAns;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  map<pair<int, int>, int> last;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    if (last.count({x, y})) {
      update(0, 0, q, last[{x, y}], i, {x, y});
      last.erase({x, y});
    } else {
      last[{x, y}] = i;
    }
  }
  for (auto [p, i] : last) {
    update(0, 0, q, i, q, p);
  }
  for (int i = 0; i < 2 * Q; ++i) {
    par[i] = i;
    if (i & 1)
      sizeY[i] = 1;
    else
      sizeX[i] = 1;
  }
  dfs(0, 0, q);
  for (int i = 0; i < q; ++i) cout << res[i] << ' ';
}
