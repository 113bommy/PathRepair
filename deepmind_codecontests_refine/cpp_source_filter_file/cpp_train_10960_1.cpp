#include <bits/stdc++.h>
using namespace std;
using INT = long long;
using pii = pair<int, int>;
using ppi = pair<int*, int>;
const int NN = 1006060;
int root[NN], col[NN], sz[NN];
int flag[NN], dis[NN];
map<pii, vector<pii>> mp;
vector<ppi> roll;
int find(int u) {
  if (u == root[u]) return u;
  int v = find(root[u]);
  roll.push_back(ppi(&root[u], root[u]));
  roll.push_back(ppi(&dis[u], dis[u]));
  dis[u] ^= dis[root[u]];
  return root[u] = v;
}
int merge(int u, int v) {
  int U = find(u);
  int V = find(v);
  if (U == V) return dis[u] == dis[v];
  if (sz[U] > sz[V]) swap(U, V);
  int d = (dis[u] ^ dis[v] ^ 1);
  roll.push_back(ppi(&root[U], root[U]));
  roll.push_back(ppi(&dis[U], dis[U]));
  roll.push_back(ppi(&sz[V], sz[V]));
  root[U] = V;
  dis[U] = d;
  sz[V] += sz[U];
  return 0;
}
void Roll_back() {
  while (!roll.empty()) {
    auto p = roll.back();
    roll.pop_back();
    *p.first = p.second;
  }
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) scanf("%d", col + i);
  for (int i = 1; i <= n; i++) root[i] = i, sz[i] = 1;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (col[u] == col[v]) {
      if (merge(u, v)) flag[col[u]] = 1;
    } else {
      if (col[u] > col[v]) swap(u, v);
      mp[pii(col[u], col[v])].push_back(pii(u, v));
    }
  }
  int t = k;
  for (int i = 1; i <= k; i++)
    if (flag[i]) t--;
  INT ans = (INT)t * (t - 1);
  roll.clear();
  for (auto p : mp) {
    if (flag[p.first.first]) continue;
    if (flag[p.first.second]) continue;
    for (auto q : p.second) {
      if (merge(q.first, q.second)) {
        ans--;
        break;
      }
    }
    Roll_back();
  }
  ans /= 2;
  cout << ans;
  return 0;
}
