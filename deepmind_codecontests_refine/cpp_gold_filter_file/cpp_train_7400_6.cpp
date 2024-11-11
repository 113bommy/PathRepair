#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 1e5 + 7;
int ans, d[N], b[N];
vector<int> a;
int f[N], n, k, u, v, w, st, ed, x, l, r, p;
pair<int, int> h[N];
vector<pair<int, int> > g[N];
bool use[N];
void dfs(int u, int fa) {
  for (auto v : g[u])
    if (v.first != fa) {
      f[v.first] = u;
      d[v.first] = d[u] + v.second;
      dfs(v.first, u);
    }
}
void dfs2(int u, int fa, int dep, int p) {
  b[p] = max(b[p], dep);
  for (auto v : g[u])
    if (v.first != fa && !use[v.first]) {
      dfs2(v.first, u, dep + v.second, p);
    }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n >> k;
  for (int i = (1); i < (n); i++) {
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs(1, 0);
  st = max_element(d + 1, d + n + 1) - d;
  d[st] = 0;
  f[st] = 0;
  dfs(st, 0);
  ed = max_element(d + 1, d + n + 1) - d;
  x = ed;
  while (1) {
    use[x] = 1;
    a.push_back(x);
    x = f[x];
    if (x == 0) break;
  }
  reverse(a.begin(), a.end());
  for (int i = (0); i < ((int)a.size()); i++) dfs2(a[i], 0, 0, i);
  if (k >= (int)a.size())
    cout << *max_element(b, b + (int)a.size());
  else {
    l = 0;
    r = -1;
    p = 0;
    ans = (1ll << (30));
    for (int i = (0); i < ((int)a.size() - k + 1); i++) {
      while (l <= r && h[l].second < i) l++;
      while (p <= i + k - 1) {
        while (l <= r && h[r].first <= b[p]) r--;
        h[++r] = {b[p], p};
        p++;
      }
      ans = min(ans, max(max(h[l].first, d[a[i]]), d[a.back()] - d[a[p - 1]]));
    }
    cout << ans;
  }
  return 0;
}
