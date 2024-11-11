#include <bits/stdc++.h>
using namespace std;
long long n, m, ok = 0, i, vis[20007], a[20007];
long long dfs(long long x) {
  if (vis[x])
    return 1;
  else
    return a[x] - 1;
  return 0;
}
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) {
    if (a[a[a[i]]] == i) ok = 1;
  }
  cout << (ok ? "YES" : "NO") << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
