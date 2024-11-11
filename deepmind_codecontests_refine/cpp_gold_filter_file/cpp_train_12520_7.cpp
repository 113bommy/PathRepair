#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
void solve() {
  int n, m;
  scanf("%d", &n);
  vector<vector<int>> G(n, vector<int>());
  vector<long long> f;
  vector<long long> p;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  function<long long(int, int)> dfs = [&](int u, int pre) {
    long long d = 1;
    for (int& v : G[u]) {
      if (v == pre) continue;
      d += dfs(v, u);
    }
    f.push_back(d * (n - d));
    return d;
  };
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    long long x;
    scanf("%lld", &x);
    p.push_back(x);
  }
  dfs(0, -1);
  sort(f.begin(), f.end());
  sort(p.begin(), p.end());
  if (m <= n - 1) {
    for (int i = m; i < n - 1; i++) {
      p.push_back(1LL);
    }
    sort(p.begin(), p.end());
  } else {
    for (int i = n - 1; i < m; i++) {
      p[n - 2] = p[n - 2] * p[i] % mod;
    }
  }
  long long res = 0;
  for (int i = 1; i < (int)f.size(); i++) {
    res = (res + p[i - 1] * f[i] % mod) % mod;
  }
  cout << res << endl;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
