#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n, ans, p[500005], sz[500005];
string a, b;
int get(int v) { return p[v] = (v == p[v] ? v : get(p[v])); }
void unite(int u, int v) {
  if ((u = get(u)) == (v = get(v))) return;
  if (sz[u] < sz[v]) swap(u, v);
  sz[u] += sz[v], p[v] = u;
}
void solve() {
  ans = 0;
  cin >> n >> a >> b;
  a = "#" + a;
  b = "#" + b;
  for (int i = 0; i < 26; i++) p[i] = i, sz[i] = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] > b[i]) {
      cout << -1 << "\n";
      return;
    }
    unite(a[i] - 'a', b[i] - 'a');
  }
  for (int i = 0; i < 26; i++) ans += (i == get(i)) * (sz[i] - 1);
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout.precision(30);
  cerr.precision(7);
  ;
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
