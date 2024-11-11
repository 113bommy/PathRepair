#include <bits/stdc++.h>
using namespace std;
class UnionFind {
 private:
  vector<int> p, rank, sz;
  long long ans;

 public:
  UnionFind(int n) {
    ans = 0;
    p.assign(n, 0);
    rank.assign(n, 0);
    for (int i = int(0); i < int(n); i++) p[i] = i;
    sz.assign(n, 1);
  }
  int findSet(int i) { return (i == p[i] ? i : p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void uionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
        ans -= (long long)sz[x] * (sz[x] - 1) / 2;
        sz[x] += sz[y];
        ans -= (long long)sz[y] * (sz[y] - 1) / 2;
        ans += (long long)sz[x] * (sz[x] - 1) / 2;
      } else {
        p[x] = y;
        ans -= (long long)sz[y] * (sz[y] - 1) / 2;
        sz[y] += sz[x];
        ans -= (long long)sz[x] * (sz[x] - 1) / 2;
        ans += (long long)sz[y] * (sz[y] - 1) / 2;
        if (rank[x] == rank[y]) {
          rank[y]++;
        }
      }
    }
  }
  long long getAns() { return ans; }
};
int n, m;
vector<pair<int, pair<int, int> > > e;
vector<pair<int, int> > queries;
bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
  return a.first < b.first;
}
void solve() {
  UnionFind uf(n + 1);
  vector<long long> ans(m);
  int cur = 0;
  for (int i = int(0); i < int(m); i++) {
    pair<int, int> p = queries[i];
    while (cur < n - 1 && e[cur].first <= p.first) {
      uf.uionSet(e[cur].second.first, e[cur].second.second);
      cur++;
    }
    ans[p.second] = uf.getAns();
  }
  for (int i = int(0); i < int(m); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int u, v, w;
  for (int i = int(1); i < int(n); i++) {
    cin >> u >> v >> w;
    e.push_back(make_pair(w, pair<int, int>(u, v)));
  }
  sort(e.begin(), e.end(), cmp);
  int q;
  for (int i = int(0); i < int(m); i++) {
    cin >> q;
    queries.push_back(pair<int, int>(q, i));
  }
  sort(queries.begin(), queries.end());
  solve();
  return 0;
}
