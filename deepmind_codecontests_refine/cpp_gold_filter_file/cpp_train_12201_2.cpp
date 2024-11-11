#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<pair<int, int>> cor;
vector<ll> c, k;
ll dist(int i, int j) {
  ll res =
      abs(cor[i].first - cor[j].first) + abs(cor[i].second - cor[j].second);
  res *= k[i] + k[j];
  return res;
}
struct dsu {
  vector<int> pred;
  vector<ll> rank;
  vector<pair<int, int>> edge;
  ll cost;
  int cnt_root;
  void init(int n) {
    pred.resize(n + 1);
    rank.resize(n + 1);
    cost = 0;
    cnt_root = n;
    for (int i = 1; i <= n; i++) {
      pred[i] = i;
      cost += c[i];
      rank[i] = c[i];
    }
  }
  int find(int v) { return (v == pred[v] ? v : pred[v] = find(pred[v])); }
  void merge(int ru, int rv, ll val) {
    int u = find(ru);
    int v = find(rv);
    if (u == v) return;
    if (rank[u] > rank[v]) swap(u, v);
    if (cost - rank[v] + val >= cost) return;
    cost = cost - rank[v] + val;
    pred[v] = u;
    edge.push_back({ru, rv});
    cnt_root--;
  }
} mst;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  cor.resize(n + 1);
  k.resize(n + 1);
  c.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> cor[i].first >> cor[i].second;
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
  }
  mst.init(n);
  vector<pair<int, int>> e;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      e.push_back({i, j});
    }
  }
  sort(e.begin(), e.end(),
       [](const pair<int, int>& x, const pair<int, int>& y) {
         return (dist(x.first, x.second) < dist(y.first, y.second));
       });
  for (const pair<int, int>& i : e) {
    mst.merge(i.first, i.second, dist(i.first, i.second));
  }
  cout << mst.cost << "\n";
  cout << mst.cnt_root << "\n";
  for (int i = 1; i <= n; i++) {
    if (mst.find(i) == i) cout << i << " ";
  }
  cout << "\n";
  cout << mst.edge.size() << "\n";
  for (const pair<int, int>& i : mst.edge) {
    cout << i.first << " " << i.second << "\n";
  }
  return 0;
}
