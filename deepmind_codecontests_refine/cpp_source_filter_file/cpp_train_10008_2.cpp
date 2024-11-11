#include <bits/stdc++.h>
using namespace std;
struct edge {
  int x, y, z;
  bool operator<(const edge& b) const { return z < b.z; }
};
struct DisjointSet {
  vector<int> p, r;
  DisjointSet(int n) : p(n + 1, 0), r(n + 1, 1){};
  int root(int i) { return p[i] ? p[i] = root(p[i]) : i; }
  void merge(int i, int j) {
    i = root(i), j = root(j);
    if (i == j) return;
    if (r[i] < r[j]) swap(i, j);
    p[j] = i;
    r[i] += r[j];
  }
};
int main() {
  int n, m, p = 0, r = 0;
  cin >> n >> m;
  DisjointSet ds(n);
  vector<edge> e(m), f;
  for (auto& [x, y, z] : e) cin >> x >> y >> z;
  sort(begin(e), end(e));
  for (int i = 0, j = 0; i < m; i = j) {
    for (; j < m && e[i].z == e[j].z; j++)
      if (ds.root(e[i].x) != ds.root(e[i].y)) f.push_back(e[i]);
    for (auto& [x, y, z] : f)
      if (ds.root(x) != ds.root(y))
        ds.merge(x, y);
      else
        r++;
    f.clear();
  }
  cout << r;
}
