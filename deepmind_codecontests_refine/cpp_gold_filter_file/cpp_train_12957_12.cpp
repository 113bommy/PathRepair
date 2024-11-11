#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int INF = 1e9;
const int N = 2010;
const int mod = 1e9 + 7;
int d, n, u, v, val[N];
vector<int> G[N];
int base;
void add(long long& x, long long y) {
  x += y;
  if (x >= mod) x %= mod;
}
long long dfs(int u, int fa) {
  long long ret = 1;
  for (int y : G[u]) {
    if (y == fa || val[y] < val[base] || (val[y] == val[base] && y < base))
      continue;
    if (val[y] <= val[base] + d) ret = ret * (1 + dfs(y, u)) % mod;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> d >> n;
  for (int i = 1; i <= n; i++) cin >> val[i];
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    base = i;
    add(ans, dfs(i, i));
  }
  cout << ans << endl;
}
