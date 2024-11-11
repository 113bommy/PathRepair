#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int M = 5e5 + 10;
const long long INF = 1e18;
const double eps = 1e-5;
const int MOD = 1e9;
struct node {
  int l, r;
  long long sum, tag;
} t[N << 2];
long long ans[N];
int n;
void push_up(int u) { t[u].sum = t[u << 1].sum + t[u << 1 | 1].sum; }
void push_down(int u) {
  if (t[u].tag) {
    t[u << 1].tag += t[u].tag;
    t[u << 1 | 1].tag += t[u].tag;
    t[u << 1].sum = 1ll * (t[u << 1].r - t[u << 1].l + 1) * t[u].tag;
    t[u << 1 | 1].sum =
        1ll * (t[u << 1 | 1].r - t[u << 1 | 1].l + 1) * t[u].tag;
    t[u].tag = 0;
  }
}
void build(int u, int l, int r) {
  t[u].l = l, t[u].r = r;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  push_up(u);
}
void modify(int u, int ql, int qr, int val) {
  if (ql <= t[u].l && qr >= t[u].r) {
    t[u].sum += 1ll * (t[u].r - t[u].l + 1) * val;
    t[u].tag += val;
    return;
  }
  push_down(u);
  int mid = (t[u].l + t[u].r) >> 1;
  if (ql <= mid) modify(u << 1, ql, qr, val);
  if (qr > mid) modify(u << 1 | 1, ql, qr, val);
  push_up(u);
}
long long query(int u, int pos) {
  if (t[u].l == t[u].r) return t[u].sum;
  push_down(u);
  int mid = (t[u].l + t[u].r) >> 1;
  if (pos <= mid)
    return query(u << 1, pos);
  else
    return query(u << 1 | 1, pos);
}
vector<int> g[N];
vector<pair<int, int> > Query[N];
void dfs(int u, int fa, int dep) {
  for (auto it : Query[u]) {
    int depl = dep;
    int depr = min(n, dep + it.first);
    modify(1, depl, depr, it.second);
  }
  ans[u] = query(1, dep);
  for (auto &v : g[u]) {
    if (v == fa) continue;
    dfs(v, u, dep + 1);
  }
  for (auto it : Query[u]) {
    int depl = dep;
    int depr = min(n, dep + it.first);
    modify(1, depl, depr, -it.second);
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  build(1, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int u, d, x;
    cin >> u >> d >> x;
    Query[u].push_back({d, x});
  }
  dfs(1, 0, 1);
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
