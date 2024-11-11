#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct point_t {
  long long x, y;
  point_t() {}
  point_t(long long x, long long y) : x(x), y(y) {}
  point_t operator+(point_t a) { return point_t(x + a.x, y + a.y); }
  point_t operator-(point_t a) { return point_t(x - a.x, y - a.y); }
  long long f(long long d) { return x * d + y; }
  bool operator<(const point_t& a) const {
    return x == a.x ? y < a.y : x < a.x;
  }
} px;
long long cross(point_t a, point_t b) { return a.x * b.y - a.y * b.x; }
int n, m, tt, size[N], pu, pv, all, diff;
vector<pair<int, point_t>> adj[N], go[N];
vector<point_t> all_points;
bool visit[N];
int newnode(int u) {
  ++tt;
  go[u].emplace_back(tt, point_t(0, 0));
  go[tt].emplace_back(u, point_t(0, 0));
  return tt;
}
void build(int l, int r, int u, vector<pair<int, point_t>>& nodes) {
  if (l == r) {
    go[u].emplace_back(nodes[l].first, nodes[l].second);
    go[nodes[l].first].emplace_back(u, nodes[l].second);
  } else {
    int mid = l + r >> 1;
    build(l, mid, l == mid ? u : newnode(u), nodes);
    build(mid + 1, r, mid + 1 == r ? u : newnode(u), nodes);
  }
}
void dfs(int u, int p) {
  vector<pair<int, point_t>> nodes;
  for (auto v : adj[u]) {
    if (v.first != p) {
      dfs(v.first, u);
      nodes.push_back(v);
    }
  }
  if (nodes.size()) {
    build(0, nodes.size() - 1, u, nodes);
  }
}
void find_edge(int u, int p) {
  size[u] = 1;
  for (auto v : go[u]) {
    if (v.first != p && !visit[v.first]) {
      find_edge(v.first, u);
      size[u] += size[v.first];
      if (abs(all - 2 * size[v.first]) < diff) {
        diff = abs(all - 2 * size[v.first]);
        pu = u;
        pv = v.first;
        px = v.second;
      }
    }
  }
}
void get_all_info(int u, int p, point_t fun, vector<point_t>& s) {
  s.push_back(fun);
  for (auto v : go[u]) {
    if (v.first != p && !visit[v.first]) {
      get_all_info(v.first, u, fun + v.second, s);
    }
  }
}
vector<point_t> convex_hull(vector<point_t> x) {
  sort(x.begin(), x.end());
  vector<point_t> result;
  for (int i = 0; i < x.size(); ++i) {
    for (int j; (j = result.size()) > 0 && result[j - 1].y <= x[i].y;
         result.pop_back())
      ;
    for (int j; (j = result.size()) > 1 &&
                cross(x[i] - result[j - 2], result[j - 1] - result[j - 2]) <= 0;
         result.pop_back())
      ;
    result.push_back(x[i]);
  }
  return result;
}
void minkowski_sum(vector<point_t> x, vector<point_t> y) {
  all_points.push_back(x[0] + y[0]);
  int n = x.size(), m = y.size();
  x.push_back(x[0]);
  y.push_back(y[0]);
  for (int i = 0, j = 0; i + j < n + m - 1;) {
    if (j == m || (i < n && cross(x[i + 1] - x[i], y[j + 1] - y[j]) > 0)) {
      all_points.push_back(x[++i] + y[j]);
    } else {
      all_points.push_back(x[i] + y[++j]);
    }
  }
}
void solve(int u, int s) {
  if (s == 1) {
    return;
  }
  all = s;
  diff = s + 1;
  find_edge(u, 0);
  vector<point_t> su, sv;
  get_all_info(pu, pv, {0, 0}, su);
  get_all_info(pv, pu, px, sv);
  minkowski_sum(convex_hull(su), convex_hull(sv));
  int oldu = pu, oldv = pv, sizeu = s - size[pv], sizev = size[pv];
  visit[oldv] = true;
  solve(oldu, sizeu);
  visit[oldv] = false;
  visit[oldu] = true;
  solve(oldv, sizev);
  visit[oldu] = false;
}
int main() {
  scanf("%d%d", &n, &m);
  all_points.emplace_back(0, 0);
  for (int i = 1; i < n; ++i) {
    int u, v, k, b;
    scanf("%d%d%d%d", &u, &v, &k, &b);
    adj[u].emplace_back(v, point_t(k, b));
    adj[v].emplace_back(u, point_t(k, b));
  }
  tt = n;
  dfs(1, 0);
  solve(1, tt);
  all_points = convex_hull(all_points);
  for (int i = 0, j = 0; i < m; ++i) {
    for (; j + 1 < all_points.size() &&
           all_points[j].f(i) <= all_points[j + 1].f(i);
         ++j)
      ;
    printf("%lld%c", all_points[j].f(i), " \n"[i + 1 == m]);
  }
  return 0;
}
