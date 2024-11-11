#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> size;
void init(int n) {
  parent.resize(n);
  size.resize(n);
  for (int i = 0; i < n; i++) {
    parent[i] = i;
    size[i] = 1;
  }
}
int find(int x) { return (parent[x] == x) ? x : parent[x] = find(parent[x]); }
void join(int a, int b) {
  int ra = find(a), rb = find(b);
  if (ra != rb) {
    size[rb] += size[ra];
    parent[ra] = rb;
  }
}
double doit(vector<vector<int> > &g, vector<int> &a) {
  vector<pair<int, int> > h(g.size());
  for (int i = 0; i < g.size(); i++) {
    h[i] = make_pair(a[i], i);
  }
  sort(h.rbegin(), h.rend());
  init(g.size());
  vector<bool> added(g.size());
  double ans = 0;
  double denom = g.size() * (double)(g.size() - 1);
  for (int i = 0; i < g.size(); i++) {
    int v = h[i].second;
    added[v] = true;
    set<int> s;
    for (int j = 0; j < g[v].size(); j++) {
      if (added[g[v][j]]) {
        s.insert(find(g[v][j]));
      }
    }
    s.insert(find(v));
    long long all = 0, inner = 0;
    for (set<int>::iterator j = s.begin(); j != s.end(); j++) {
      long long sz = size[find(*j)];
      all += sz;
      inner += sz * (sz - 1);
    }
    all *= all - 1;
    long long connected_pairs = all - inner;
    ans += connected_pairs / denom * a[v];
    for (set<int>::iterator j = s.begin(); j != s.end(); j++) {
      join(v, *j);
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int> > g(n);
  vector<int> a(n);
  vector<bool> added(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x - 1].push_back(y - 1);
    g[y - 1].push_back(x - 1);
  }
  cout.precision(10);
  cout.setf(ios::fixed);
  cout << doit(g, a) << '\n';
  return 0;
}
