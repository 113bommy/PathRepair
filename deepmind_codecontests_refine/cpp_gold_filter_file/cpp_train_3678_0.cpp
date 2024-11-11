#include <bits/stdc++.h>
using namespace std;
int n, m, mod;
const int N = 1e6 + 7;
vector<int> v[N];
int sz[N];
int dfs(int x) {
  sz[x]++;
  for (int i : v[x])
    if (!sz[i]) sz[x] += dfs(i);
  return sz[x];
}
long long pw(int x, int y) {
  if (!y) return 1;
  long long cnt = pw(x, y / 2);
  return (((cnt * cnt) % mod) * (y & 1 ? x : 1)) % mod;
}
int main() {
  cin >> n >> m >> mod;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  long long zarb = 1, cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!sz[i]) zarb = (zarb * dfs(i)) % mod, cnt++;
  if (!(cnt - 1))
    cout << 1 % mod;
  else
    cout << (zarb * pw(n, cnt - 2)) % mod;
}
