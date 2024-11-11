#include <bits/stdc++.h>
using namespace std;
using namespace std;
inline long long gcd(long long a, long long b) {
  return b ? gcd(b, a % b) : a;
};
const long long mod = 998244353;
long long QPow(long long a, long long b) {
  long long as = 1;
  if (b < 0) return 0;
  while (b) {
    if (b & 1) as = as * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return as;
}
const long long maxn = 3e5 + 100;
inline long long rd() {
  long long ans = 0;
  char last = ' ', ch = getchar();
  while (!(ch >= '0' && ch <= '9')) last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
  return ans;
}
pair<signed, signed> lr[maxn];
vector<signed> g[maxn];
long long xi[maxn], yi[maxn];
bool vis1[maxn], vis2[maxn];
long long fa[maxn];
void dfs(long long u, long long f) {
  fa[u] = f;
  for (auto v : g[u])
    if (v != f) dfs(v, u);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t, n, m, k, u, v, a, b, k1, k2;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i < n; i++)
      cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    cin >> k1;
    for (long long i = 1; i <= k1; i++) cin >> xi[i], vis1[xi[i]] = 1;
    cin >> k2;
    for (long long i = 1; i <= k2; i++) cin >> yi[i], vis2[yi[i]] = 1;
    dfs(xi[1], 0);
    cout << "B " << yi[1] << endl;
    cout.flush();
    cin >> u;
    while (!vis1[u]) u = fa[u];
    cout << "A " << u << endl;
    cout.flush();
    cin >> v;
    if (!vis2[v])
      cout << "C " << -1 << endl, cout.flush();
    else
      cout << "C " << u << endl, cout.flush();
    for (long long i = 0; i <= n; i++) g[i].clear(), vis1[i] = vis2[i] = 0;
  }
  return 0;
}
