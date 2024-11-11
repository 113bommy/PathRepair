#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-ffloat-store")
#pragma GCC optimize("-fno-defer-pop")
using namespace std;
void solve() {
  int m, n, p;
  cin >> m >> n >> p;
  int f[m], g[n];
  for (int i = 0; i < m; i++) cin >> f[i];
  for (int j = 0; j < n; j++) cin >> g[j];
  int i = 0, j = 0;
  while (!(f[i] % p)) i++;
  while (!(g[j] % p)) j++;
  cout << i + j << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t = 1;
  while (t--) solve();
  return 0;
}
