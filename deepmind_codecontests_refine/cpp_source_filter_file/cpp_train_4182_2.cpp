#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
template <typename first, typename second>
ostream &operator<<(ostream &os, const pair<first, second> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename first, typename second>
ostream &operator<<(ostream &os, const map<first, second> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
void faltu() { cerr << '\n'; }
template <typename T>
void faltu(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << '\n';
}
template <typename T, typename... hello>
void faltu(T arg, const hello &...rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
const int mx = 2e5 + 123;
struct info {
  long long u, v, w;
} edge[mx];
vector<info> adj[mx];
map<info, long long> E;
set<long long> t[mx * 3];
long long L[mx], R[mx], n, second[mx];
long long d1[mx], d2[mx], d[mx];
bool vis[mx * 3], vis_e[mx];
pair<long long, long long> par[mx], par1[mx], par2[mx];
void shift(int id) {
  t[id * 2].insert(*t[id].begin());
  vis[id * 2] = 1;
  t[id * 2 + 1].insert(*t[id].begin());
  vis[id * 2 + 1] = 1;
  vis[id] = 0;
}
void upd(int id, int b, int e, int i, int j, long long val) {
  if (b > j || e < i) return;
  if (b >= i && e <= j) {
    t[id].insert(val);
    vis[id] = 1;
    return;
  }
  if (vis[id]) shift(id);
  int mid = (b + e) >> 1;
  upd(id * 2, b, mid, i, j, val);
  upd(id * 2 + 1, mid + 1, e, i, j, val);
}
long long ask(int id, int b, int e, int i) {
  if (b > i || e < i) return infLL;
  if (b >= i && e <= i) return (t[id].empty()) ? infLL : *t[id].begin();
  int mid = (b + e) >> 1;
  if (vis[id]) shift(id);
  long long p1 = ask(id * 2, b, mid, i);
  long long p2 = ask(id * 2 + 1, mid + 1, e, i);
  return min(p1, p2);
}
void dijkstra() {
  priority_queue<pair<long long, long long>,
                 vector<pair<long long, long long> >,
                 greater<pair<long long, long long> > >
      q;
  q.push({0, 1});
  d[1] = 0;
  while (!q.empty()) {
    pair<long long, long long> u = q.top();
    q.pop();
    for (auto v : adj[u.second]) {
      if (d[v.u] >= d[u.second] + v.w) {
        d[v.u] = d[u.second] + v.w;
        par[v.u] = {u.second, v.v};
        q.push({d[v.u], v.u});
      }
    }
  }
}
struct que {
  long long dist, node, f1, Edge;
};
struct cmp {
  bool operator()(que &a, que &b) { return a.dist > b.dist; }
};
void dijkstra1() {
  priority_queue<que, vector<que>, cmp> q;
  q.push({0, 1, 1, 0});
  d1[1] = 0;
  while (!q.empty()) {
    que u = q.top();
    q.pop();
    for (auto v : adj[u.node]) {
      if (d1[v.u] >= d1[u.node] + v.w) {
        d1[v.u] = d1[u.node] + v.w;
        bool f1 = u.f1;
        if ((!vis_e[v.v] || !u.f1) && u.Edge != 0) f1 = 0;
        que New;
        if (f1) {
          New.Edge = v.v;
          L[v.u] = v.v;
        } else {
          L[v.u] = u.Edge;
          New.Edge = u.Edge;
        }
        New.dist = d1[v.u];
        New.f1 = f1;
        New.node = v.u;
        q.push(New);
      }
    }
  }
}
void dijkstra2() {
  priority_queue<que, vector<que>, cmp> q;
  q.push({0, n, 1, 0});
  d2[n] = 0;
  while (!q.empty()) {
    que u = q.top();
    q.pop();
    for (auto v : adj[u.node]) {
      if (d2[v.u] >= d2[u.node] + v.w) {
        d2[v.u] = d2[u.node] + v.w;
        bool f1 = u.f1;
        if ((!vis_e[v.v] || !u.f1) && u.Edge != 0) f1 = 0;
        que New;
        if (f1) {
          New.Edge = v.v;
          R[v.u] = v.v;
        } else {
          R[v.u] = u.Edge;
          New.Edge = u.Edge;
        }
        New.dist = d2[v.u];
        New.f1 = f1;
        New.node = v.u;
        q.push(New);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  for (int i = 0; i <= 2e5; i++) {
    d[i] = d1[i] = d2[i] = infLL;
  }
  int m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, i, w});
    adj[v].push_back({u, i, w});
    info get1 = {u, v, w};
    info get2 = {v, u, w};
    edge[i] = get1;
  }
  dijkstra();
  int cur = n, tmp = 0;
  while (cur != 1) {
    vis_e[par[cur].second] = 1;
    cur = par[cur].first;
    tmp++;
  }
  dijkstra1();
  dijkstra2();
  int cnt = tmp;
  cur = n;
  while (cur != 1) {
    second[L[cur]] = cnt--;
    cur = par[cur].first;
  }
  for (int i = 1; i <= m; i++) {
    int u = edge[i].u;
    int v = edge[i].v;
    int w = edge[i].w;
    if (vis_e[i]) continue;
    long long path1, path2;
    if (d1[u] == d2[v] && d1[u] == infLL) {
      path1 = infLL;
    } else {
      path1 = d1[u] + d2[v] + w;
    }
    if (d1[v] == d2[u] && d1[v] == infLL) {
      path2 = infLL;
    } else {
      path2 = d1[v] + d2[u] + w;
    }
    if (path1 < path2) {
      int l = second[L[u]] + 1, r = second[R[v]] - 1;
      if (second[R[v]] == 0) r = tmp;
      if (l <= r) upd(1, 1, tmp, l, r, path1);
    } else {
      int l = second[L[v]] + 1, r = second[R[u]] - 1;
      if (second[R[u]] == 0) r = tmp;
      if (l <= r) upd(1, 1, tmp, l, r, path2);
    }
  }
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (vis_e[t]) {
      if (edge[t].w >= x) {
        cout << d1[n] - (edge[t].w - x) << '\n';
      } else {
        cout << min(ask(1, 1, tmp, second[t]), d1[n] + (x - edge[t].w)) << '\n';
      }
    } else {
      int u, v;
      u = edge[t].u;
      v = edge[t].v;
      long long path1;
      long long path2;
      if (d1[u] == infLL || d2[v] == infLL)
        path1 = infLL;
      else
        path1 = d1[u] + d2[v] + x;
      if (d2[u] == infLL || d1[v] == infLL)
        path2 = infLL;
      else
        path2 = d2[u] + d1[v] + x;
      cout << min(d1[n], min(path1, path2)) << '\n';
    }
  }
  return 0;
}
