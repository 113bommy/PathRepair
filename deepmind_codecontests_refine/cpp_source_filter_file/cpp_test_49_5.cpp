#include <bits/stdc++.h>
using namespace std;
void _io() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void _init();
const int MAXN = 1000005;
const long long mod = 998244353;
int n, q, a[MAXN], p[MAXN], ans[MAXN];
int occur[MAXN];
vector<int> num[MAXN];
vector<int> g[MAXN];
struct NODE {
  int l, k, id;
  NODE(int a, int b, int c) : l(a), k(b), id(c) {}
};
vector<NODE> Q[MAXN];
int ta[MAXN];
void add(int k, int p) {
  if (k <= 0) return;
  for (int i = k; i <= n; i += i & (-i)) ta[i] += p;
}
int get(int k) {
  int res = 0;
  for (int i = k; i > 0; i -= i & (-i)) res += ta[i];
  return res;
}
void add(int v) {
  add(occur[v], -1);
  occur[v]++;
  add(occur[v], 1);
  num[occur[v]].emplace_back(v);
}
void del(int v) {
  add(occur[v], -1);
  occur[v]--;
  add(occur[v], 1);
  num[occur[v]].emplace_back(v);
}
int deal(int l, int k) {
  int low = l, high = n;
  while (low < high) {
    int mid = (low + high) >> 1;
    if (get(mid) - get(l - 1) >= k)
      high = mid;
    else
      low = mid + 1;
  }
  if (get(low) - get(l - 1) < k) return -1;
  while (occur[num[low].back()] < l) num[low].pop_back();
  return num[low].back();
}
void dfs(int u) {
  add(a[u]);
  for (auto x : Q[u]) {
    ans[x.id] = deal(x.l, x.k);
  }
  for (auto v : g[u]) {
    dfs(v);
  }
  del(a[u]);
}
void _work() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) Q[i].clear(), g[i].clear(), cin >> a[i];
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    g[p[i]].emplace_back(i);
  }
  for (int v, l, k, i = 1; i <= q; i++) {
    cin >> v >> l >> k;
    Q[v].emplace_back(l, k, i);
  }
  dfs(1);
  for (int i = 1; i <= q; i++) cout << ans[i] << ' ';
  cout << '\n';
}
int main() {
  _io();
  _init();
  int T = 1;
  cin >> T;
  while (T--) {
    _work();
  }
  return 0;
}
void _init() {}
