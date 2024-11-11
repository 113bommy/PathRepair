#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000")
using namespace std;
inline long long read() {
  long long x;
  cin >> x;
  return x;
}
const int MAX_N = 1e5 + 5;
const int MAX_K = 1e6 + 66;
const int MAX_LOG = 19;
const long long MODULE = 1e9 + 7;
int n, logN;
vector<pair<int, int> > e[MAX_N];
int p[MAX_N][MAX_LOG], h[MAX_N], pre[MAX_N], a[MAX_N], b[MAX_N];
bool ok[MAX_N];
long long pow2[MAX_K];
inline long long mmod(long long x) {
  x %= MODULE;
  if (x < 0) x += MODULE;
  return x;
}
void dfs(int u) {
  ok[u] = 0;
  for (int i = (1); i <= (logN); ++i) {
    if (h[u] - (1 << i) < 1) break;
    p[u][i] = p[p[u][i - 1]][i - 1];
  }
  for (__typeof(e[u].begin()) it = e[u].begin(); it != e[u].end(); it++) {
    int v = it->first;
    if (!ok[v]) continue;
    pre[v] = it->second;
    h[v] = h[u] + 1;
    p[v][0] = u;
    dfs(v);
  }
}
inline int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  if (h[u] > h[v])
    for (int i = (logN); i >= (0); --i)
      if (h[u] - (1 << i) >= h[v]) u = p[u][i];
  if (u == v) return u;
  for (int i = (logN); i >= (0); --i)
    if (p[u][i] != p[v][i]) {
      u = p[u][i];
      v = p[v][i];
    }
  return p[u][0];
}
void solve(int u) {
  for (__typeof(e[u].begin()) it = e[u].begin(); it != e[u].end(); it++) {
    int v = it->first;
    if (p[v][0] == u) {
      solve(v);
      a[u] += a[v];
      b[u] += b[v];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(9);
  cout.setf(ios::fixed, ios::floatfield);
  cin >> n;
  for (int i = (1); i <= (n - 1); ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    if (c == 0) {
      e[x].push_back(make_pair(y, -1));
      e[y].push_back(make_pair(x, -1));
    } else {
      e[x].push_back(make_pair(y, 0));
      e[y].push_back(make_pair(x, 1));
    }
  }
  pow2[0] = 1;
  for (int i = (1); i <= (MAX_K - 1); ++i) pow2[i] = mmod(pow2[i - 1] * 2LL);
  logN = 0;
  while (1 << (logN + 1) <= n) ++logN;
  memset(ok, 1, sizeof(ok));
  memset(p, 0, sizeof(p));
  pre[1] = -1;
  h[1] = 1;
  dfs(1);
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  int nQ = read(), u = 1, v, r;
  while (nQ--) {
    cin >> v;
    r = lca(u, v);
    ++a[u], --a[r];
    ++b[v], --b[r];
    u = v;
  }
  long long ans = 0;
  solve(1);
  for (int u = (2); u <= (n); ++u) {
    if (a[u] > 0 && pre[u] == 0) ans = mmod(ans + pow2[a[u]] - 1);
    if (b[u] > 0 && pre[u] == 1) ans = mmod(ans + pow2[b[u]] - 1);
  }
  cout << ans << '\n';
  return 0;
}
