#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
struct djs {
  vi p, rank, mincost;
  djs(int n, vi cost) {
    p.assign(n, -1);
    rank.assign(n, 0);
    mincost = cost;
  };
  int find(int i) { return (p[i] == -1 ? i : (p[i] = find(p[i]))); }
  int mnCost(int i) { return mincost[find(i)]; }
  void joint(int i, int j) {
    int u = find(i), v = find(j);
    if (u == v) return;
    if (rank[u] > rank[v]) swap(u, v);
    p[u] = v;
    if (rank[u] == rank[v]) ++rank[v];
    mincost[v] = min(mincost[u], mincost[v]);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  map<string, int> mp;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    mp[x] = i;
  }
  vi cost(n, 0);
  for (int& e : cost) cin >> e;
  djs grp(n, cost);
  for (int i = 0; i < k; ++i) {
    int nc;
    cin >> nc;
    vi ele(nc, 0);
    for (int& e : ele) {
      cin >> e;
      --e;
    }
    for (int j = 0; j < (int)ele.size() - 1; ++j) grp.joint(ele[j], ele[j + 1]);
  }
  int res = 0;
  for (int i = 0; i < m; ++i) {
    string x;
    cin >> x;
    res += grp.mnCost(mp[x]);
  }
  cout << res;
  return 0;
}
