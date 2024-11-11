#include <bits/stdc++.h>
using namespace std;
void canhazfast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    T q = a / b;
    a %= b;
    swap(a, b);
    x0 -= q * x1;
    swap(x0, x1);
    y0 -= q * y1;
    swap(y0, y1);
  }
  x = x0;
  y = y0;
  return a;
}
int ctz(unsigned x) { return __builtin_ctz(x); }
int ctzll(unsigned long long x) { return __builtin_ctzll(x); }
int clz(unsigned x) { return __builtin_clz(x); }
int clzll(unsigned long long x) { return __builtin_clzll(x); }
int popcnt(unsigned x) { return __builtin_popcount(x); }
int popcntll(unsigned long long x) { return __builtin_popcountll(x); }
int bsr(unsigned x) { return 31 ^ clz(x); }
int bsrll(unsigned long long x) { return 63 ^ clzll(x); }
int p[200016];
vector<int> adj[200016];
void dfs(int u) {
  for (int v : adj[u]) {
    if (p[v]) continue;
    p[v] = u;
    dfs(v);
  }
}
int main() {
  canhazfast();
  int n, m, d;
  cin >> n >> m >> d;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (d > (int)adj[1].size()) return cout << "NO 1", 0;
  p[1] = -1;
  for (int v : adj[1]) {
    if (p[v]) continue;
    if (!d) return cout << "NO", 0;
    --d;
    p[v] = 1;
    dfs(v);
  }
  if (d) {
    for (int v : adj[1]) {
      if (p[v] == 1) continue;
      p[v] = 1;
      if (!--d) break;
    }
  }
  cout << "YES\n";
  for (int i = 2; i <= n; ++i) cout << i << ' ' << p[i] << '\n';
  return 0;
}
