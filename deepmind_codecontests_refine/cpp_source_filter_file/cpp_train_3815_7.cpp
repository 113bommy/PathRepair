#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, maxm = (1 << 17), mod = 1e9 + 7;
const double PI = 3.14159265359;
long long ans, d[maxn];
int par[maxn], h[maxn];
int father(int v) {
  if (!par[v]) return v;
  return par[v] = father(par[v]);
}
bool merge(int v, int u) {
  v = father(v), u = father(u);
  if (v == u) {
    if (ans == 0)
      ans++;
    else
      ans = (ans * 2 + 1) % mod;
    d[v] = (d[v] * 2 + 1) % mod;
    return 1;
  }
  if (h[u] > h[v]) swap(v, u);
  par[u] = v, h[v] = max(h[v], h[u] + 1), d[v] += d[u];
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    merge(a, b);
    cout << ans << endl;
  }
  return 0;
}
