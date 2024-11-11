#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
const long long LLINF = numeric_limits<long long>::max();
const unsigned long long ULLINF = numeric_limits<unsigned long long>::max();
struct pt {
  long long x, y;
  pt() = default;
  pt(long long x, long long y) : x(x), y(y) {}
  bool operator<(const pt a) const {
    if (x == a.x) return y < a.y;
    return x < a.x;
  }
};
int n;
vector<vector<int>> g;
vector<pair<pt, int>> pts;
int sz[1510], ans[1510];
int dfs(int v, int p) {
  sz[v] = 1;
  for (int& to : g[v])
    if (to != p) sz[v] += dfs(to, v);
  return sz[v];
}
int current = 0;
bool cmp(pair<pt, int> a, pair<pt, int> b) {
  return (a.first.x - pts[current].first.x) *
                 (b.first.y - pts[current].first.y) -
             (a.first.y - pts[current].first.y) *
                 (b.first.x - pts[current].first.x) >
         0;
}
void go(int v, int p, int l, int r) {
  if (l == r)
    ans[pts[l].second] = v + 1;
  else {
    ans[pts[l].second] = v + 1;
    int k = l + 1;
    current = l;
    sort(pts.begin() + k, pts.begin() + r + 1);
    for (int to : g[v]) {
      if (to == p) continue;
      go(to, v, k, k + sz[to] - 1);
      k += sz[to];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  g.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  pts.resize(n);
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    pts[i] = make_pair(pt(x, y), i);
  }
  sort((pts).begin(), (pts).end());
  dfs(0, -1);
  sort(pts.begin() + 1, pts.end(), cmp);
  go(0, -1, 0, pts.size() - 1);
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
