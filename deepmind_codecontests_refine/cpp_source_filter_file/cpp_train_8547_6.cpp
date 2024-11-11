#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
int const N = 3e5 + 20;
int n, m, in[N], out[N], l[N], r[N];
vector<int> g[N], h[N];
int que[N], he, ta;
int ans;
inline bool ok(int v) { return (l[v] + 1 + r[v] >= n - 1); }
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0, u, v; i < n; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    out[u]++;
    h[v].push_back(u);
    in[v]++;
  }
  for (int i = 0; i < n; i++)
    if (!in[i]) que[ta++] = i;
  while (he < ta) {
    int v = que[he++];
    if (he + 1 < ta)
      r[v] = -N;
    else if (he < ta) {
      bool fl = 0;
      for (int u : g[que[he]]) fl |= (in[u] == 1);
      if (fl)
        r[v] = -N;
      else
        r[v] = n - ta;
    } else
      r[v] = n - ta;
    for (int u : g[v]) {
      in[u]--;
      if (!in[u]) que[ta++] = u;
    }
  }
  he = ta = 0;
  for (int i = 0; i < n; i++)
    if (!out[i]) que[ta++] = i;
  while (he < ta) {
    int v = que[he++];
    if (he + 1 < ta)
      l[v] = -N;
    else if (he < ta) {
      bool fl = 0;
      for (int u : h[que[he]]) fl |= (out[u] == 1);
      if (fl)
        l[v] = -N;
      else
        l[v] = n - ta;
    } else
      l[v] = n - ta;
    for (int u : h[v]) {
      out[u]--;
      if (!out[u]) que[ta++] = u;
    }
  }
  for (int i = 0; i < n; i++) {
    ans += ok(i);
  }
  cout << ans << '\n';
}
