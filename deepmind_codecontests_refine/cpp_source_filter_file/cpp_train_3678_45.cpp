#include <bits/stdc++.h>
using namespace std;
int n, m, mod, sz, c;
vector<int> e[111111];
bool used[111111];
void dfs(int u) {
  used[u] = true;
  ++sz;
  for (__typeof(e[u].begin()) it = e[u].begin(); it != e[u].end(); ++it)
    if (!used[*it]) dfs(*it);
}
int modPow(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = (1LL * res * a) % mod;
    b >>= 1;
    a = (1LL * a * a) % mod;
  }
  return res;
}
int main() {
  scanf("%d%d%d", &n, &m, &mod);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  int res = 1 % mod;
  for (int i = 0; i < n; ++i)
    if (!used[i]) {
      sz = 0;
      dfs(i);
      ++c;
      res = (1LL * res * sz) % mod;
    }
  if (c < 2)
    res = 1;
  else {
    res = (1LL * res * modPow(n, c - 2)) % mod;
  }
  cout << res << endl;
  return 0;
}
