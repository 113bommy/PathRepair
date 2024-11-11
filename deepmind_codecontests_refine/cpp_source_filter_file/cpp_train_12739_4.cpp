#include <bits/stdc++.h>
using namespace std;
void setIO(string name) {
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
const int N = 1e5 + 100;
const int pod = (1 << 17);
int n, m;
int a, b;
vector<int> v[N];
int in[N], out[N], Time, ord[N];
void dfs(int u, int p) {
  in[u] = ++Time;
  ord[Time] = u;
  for (auto it : v[u])
    if (it != p) dfs(it, u);
  out[u] = Time;
}
struct gao {
  int a, b, c, d, z;
};
vector<gao> g[N];
int ans[N];
struct seg {
  pair<int, int> t[2 * pod];
  int lazy[2 * pod];
  pair<int, int> merge(int u) {
    int x = 2 * u, y = 2 * u + 1;
    if (t[x].first == t[y].first)
      return {t[x].first, t[x].second + t[y].second};
    if (t[x].first < t[y].first) return {t[x].first, t[x].second};
    return {t[y].first, t[y].second};
  }
  void init() {
    for (int i = pod; i <= 2 * pod - 1; ++i) t[i] = {0, 1};
    for (int i = pod - 1; 1 <= i; --i) t[i] = merge(i);
    for (int i = 1; i <= 2 * pod - 1; ++i) lazy[i] = 0;
  }
  void push(int u) {
    t[2 * u].first += lazy[u];
    t[2 * u + 1].first += lazy[u];
    lazy[2 * u] += lazy[u];
    lazy[2 * u + 1] += lazy[u];
    lazy[u] = 0;
  }
  void add(int x, int y, int z, int u = 1, int l = 0, int r = pod - 1) {
    if (x <= l && r <= y) {
      t[u].first += z;
      lazy[u] += z;
      return;
    }
    push(u);
    int m = (l + r) / 2;
    if (x <= m) add(x, y, z, 2 * u, l, m);
    if (m < y) add(x, y, z, 2 * u + 1, m + 1, r);
    t[u] = merge(u);
  }
} ja;
void qw(int l, int r, int c) {
  if (l == -1) return;
  ja.add(l, r, c);
}
int main() {
  ja.init();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1, 0);
  while (m--) {
    scanf("%d%d", &a, &b);
    int la = in[a];
    int ra = out[a];
    int lb = in[b];
    int rb = out[b];
    if (la > lb) {
      swap(la, lb);
      swap(ra, rb);
    }
    if (rb <= ra) {
      g[ra].push_back({la, ra, -1, -1, 1});
      g[rb + 1].push_back({la, ra, -1, -1, -1});
    } else {
      g[la].push_back({la, ra, lb, rb, 1});
      g[ra + 1].push_back({la, ra, lb, rb, -1});
      g[lb].push_back({la, ra, lb, rb, 1});
      g[rb + 1].push_back({la, ra, lb, rb, -1});
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (auto it : g[i]) {
      qw(it.a, it.b, it.z);
      qw(it.c, it.d, it.z);
    }
    qw(i, i, 1);
    ans[ord[i]] = pod - ja.t[1].second;
    qw(i, i, -1);
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i] - 1);
  return 0;
}
