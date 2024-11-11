#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int r = 1;
  x = x % p;
  while (y) {
    if (y & 1) r = r * x % p;
    y = y >> 1;
    x = x * x % p;
  }
  return r;
}
const int N = 1e5 + 9;
int par[N];
int get(int v) { return par[v] == v ? v : par[v] = get(par[v]); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n + 2; i++) par[i] = i;
  long long int ans = 1;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (get(u) == get(v)) ans = (ans * 2LL) % (1000000009);
    par[u] = get(v);
    cout << ans - 1 << '\n';
  }
}
