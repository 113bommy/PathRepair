#include <bits/stdc++.h>
using namespace std;
const int LEN = 200000;
using namespace std;
const long long N = 456789;
struct point_t {
  long long x, y;
  point_t(long long x = 0, long long y = 0) : x(x), y(y) {}
  point_t operator+(const point_t &b) const {
    return point_t(x + b.x, y + b.y);
  }
  point_t operator-(const point_t &b) const {
    return point_t(x - b.x, y - b.y);
  }
  long long operator*(const point_t &b) const { return x * b.y - y * b.x; }
  long long solve(long long k) { return k * x + y; }
} dist[N];
vector<pair<long long, point_t>> adj[N], edge[N];
long long n, m, root, proot, Size[N];
vector<point_t> l, r, all;
bool visit[N];
void rebuild(long long x, long long parent) {
  vector<pair<long long, point_t>> son;
  for (auto e : edge[x]) {
    if (e.first != parent) {
      rebuild(e.first, x);
      son.push_back(e);
    }
  }
  for (long long i = 0, t = x; i < son.size(); ++i) {
    if (i && i + 1 < son.size()) {
      adj[n].emplace_back(t, point_t(0, 0));
      adj[t].emplace_back(n, point_t(0, 0));
      t = n++;
    }
    adj[t].emplace_back(son[i].first, son[i].second);
    adj[son[i].first].emplace_back(t, son[i].second);
  }
}
void find_root(long long x, long long p, long long s) {
  Size[x] = 1;
  for (auto e : adj[x]) {
    long long y = e.first;
    if (y != p && !visit[y]) {
      find_root(y, x, s);
      Size[x] += Size[y];
    }
  }
  if (!~root || max(Size[root], s - Size[root]) > max(Size[x], s - Size[x])) {
    root = x;
    proot = p;
  }
}
void init(long long x, long long p, bool subtree) {
  if (subtree) {
    r.push_back(dist[x]);
  } else {
    l.push_back(dist[x]);
  }
  for (auto e : adj[x]) {
    long long y = e.first;
    if (y != p && !visit[y]) {
      dist[y] = dist[x] + e.second;
      init(y, x, y == root || subtree);
    }
  }
}
vector<point_t> build_convex(vector<point_t> v) {
  vector<point_t> convex;
  sort(v.begin(), v.end(), [&](const point_t &a, const point_t &b) {
    return a.x < b.x || (a.x == b.x && a.y > b.y);
  });
  long long m = 0;
  for (long long i = 0; i < v.size(); ++i) {
    if (i && v[i].x == v[i - 1].x) {
      continue;
    }
    while (m && convex[m - 1].y <= v[i].y) {
      convex.pop_back();
      --m;
    }
    while (m > 1 &&
           (v[i] - convex[m - 2]) * (convex[m - 1] - convex[m - 2]) <= 0) {
      convex.pop_back();
      --m;
    }
    convex.push_back(v[i]);
    m++;
  }
  return convex;
}
void minkowski_sum(vector<point_t> a, vector<point_t> b) {
  all.push_back(a[0] + b[0]);
  for (long long i = 0, j = 0; i + 1 < a.size() || j + 1 < b.size();) {
    if (j + 1 == b.size() ||
        (i + 1 < a.size() && (a[i + 1] - a[i]) * (b[j + 1] - b[j]) < 0)) {
      all.push_back(a[++i] + b[j]);
    } else {
      all.push_back(a[i] + b[++j]);
    }
  }
}
void divide(long long x, long long s) {
  if (s == 1) {
    return;
  }
  root = -1;
  find_root(x, -1, s);
  long long u = root, v = proot, size_u = Size[u], size_v = s - Size[u];
  dist[v] = point_t(0, 0);
  l.clear();
  r.clear();
  init(v, -1, false);
  l = build_convex(l);
  r = build_convex(r);
  minkowski_sum(l, r);
  visit[v] = true;
  divide(u, size_u);
  visit[v] = false;
  visit[u] = true;
  divide(v, size_v);
  visit[u] = false;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt;
  tt = 1;
  cin >> n >> m;
  if (n == 1) {
    for (long long i = 0; i < m; ++i) cout << 0 << " ";
    return 0;
  }
  for (long long i = 0; i < n - 1; ++i) {
    long long x, y, a = 1, b;
    cin >> x >> y >> a >> b;
    --x;
    --y;
    edge[x].emplace_back(y, point_t(a, b));
    edge[y].emplace_back(x, point_t(a, b));
  }
  rebuild(0, -1);
  divide(0, n);
  all = build_convex(all);
  vector<long long> answer(m);
  long long j = 0;
  for (long long i = 0; i < m; ++i) {
    while (j + 1 < all.size() && all[j + 1].solve(i) >= all[j].solve(i)) {
      ++j;
    }
    answer[i] = all[j].solve(i);
  }
  for (long long i = 0; i < m; ++i) {
    cout << answer[i] << " ";
  }
  all.clear();
  for (long long i = 0; i < n; ++i) {
    adj[i].clear();
    edge[i].clear();
    visit[i] = false;
  }
  return 0;
}
