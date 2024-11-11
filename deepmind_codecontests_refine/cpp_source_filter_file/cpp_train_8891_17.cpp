#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b,
                 long long mod = (long long)(1e9 + 7)) {
  if (!b) return 1;
  a %= mod;
  return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mxn = 1e3, mxt = 2 * mxn;
int n, m, t;
int a[mxn], tin[mxn], tout[mxn], tree[mxt], d[mxn];
vector<int> adj[mxn];
void init() {
  t = 0;
  for (int i = 0; i < mxt; i++) tree[i] = 0;
}
void add(int i, int x) {
  for (; i < mxt; i |= i + 1) tree[i] += x;
}
int sum(int i) {
  int sum = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) sum += tree[i];
  return sum;
}
void dfs(int v, int p) {
  tin[v] = t++;
  d[v] = p == -1 ? 0 : d[p] + 1;
  for (int w : adj[v])
    if (w != p) dfs(w, v);
  tout[v] = t++;
}
int o(int v) { return d[v] % 2 ? -1 : 1; }
void solve() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int _ = 0; _ < n - 1; _++) {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }
  init();
  dfs(0, -1);
  stringstream ss;
  for (int _ = 0; _ < m; _++) {
    int cmd;
    scanf("%d", &cmd);
    if (cmd == 1) {
      int x, val;
      scanf("%d", &x);
      scanf("%d", &val);
      x--;
      add(tin[x], o(x) * val);
      add(tout[x], -1 * o(x) * val);
    } else {
      int x;
      scanf("%d", &x);
      x--;
      ss << sum(tin[x]) * o(x) + a[x] << endl;
    }
  }
  cout << ss.str();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
