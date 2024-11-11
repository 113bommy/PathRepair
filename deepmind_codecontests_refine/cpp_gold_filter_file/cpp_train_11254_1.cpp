#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 * 1000 + 100;
const long long mod = 1e9 + 7;
const long long inf = 2 * 1e18;
long long n, m, k, c[maxn], ans;
map<long long, vector<pair<int, int>>> mp;
struct DSU {
  int p[maxn], comp = 0;
  void clear() { comp = 0; }
  int find(int u) { return (p[u] < 0 ? u : (p[u] = find(p[u]))); }
  void add(int u, int v) {
    int p_u = find(u), p_v = find(v);
    if (p_u == p_v) return;
    comp--;
    if (p[p_u] < p[p_v]) {
      p[p_u] += p[p_v];
      p[p_v] = p_u;
    } else {
      swap(p_v, p_u);
      p[p_u] += p[p_v];
      p[p_v] = p_u;
    }
  }
} dsu;
long long pw(long long b) {
  if (b == 0) return 1;
  long long A = pw(b / 2);
  A = A * A % mod;
  if (b & 1) A = A * 2 % mod;
  return A;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    mp[c[u] ^ c[v]].push_back({u, v});
  }
  for (auto x : mp) {
    dsu.clear();
    for (auto y : x.second) {
      dsu.p[y.first] = -1;
      dsu.p[y.second] = -1;
    }
    for (auto y : x.second) {
      dsu.add(y.first, y.second);
    }
    ans += pw((n + dsu.comp));
    ans %= mod;
  }
  ans += ((1ll << k) - mp.size()) % mod * pw(n) % mod;
  cout << ans % mod;
  return 0;
}
